//
// Created by bong on 23. 10. 31.
//

#include "Session.h"
#include <iostream>

Session::Session(tcp::socket socket)
        : socket_(std::move(socket)){

    settings.on_message_begin = on_message_begin;
    settings.on_header_field      = on_header_field;
    settings.on_header_value      = on_header_value;
    //settings.on_path              = request_path_cb;
    //settings.on_uri               = request_uri_cb;
    //settings.on_fragment          = fragment_cb;
    //settings.on_query_string      = query_string_cb;
    //settings.on_body              = body_cb;
    //settings.on_headers_complete  = headers_complete_cb;
    settings.on_message_complete  = message_complete_cb;

    parser_ = std::make_unique<http_parser>();
    http_parser_init(parser_.get(), HTTP_REQUEST);
    parser_->data = &http_data_;
}


void Session::read() {
    auto self(shared_from_this());

    asio::async_read_until(socket_, m_buffer, "\r\n\r\n",
                           [this, self](asio::error_code ec, std::size_t /*length*/)
                           {
                               // if there was no error, everything went well and for this demo
                               // we print the data to stdout and wait for the next request
                               if (!ec)  {
                                   std::string data{
                                           std::istreambuf_iterator<char>(&m_buffer),
                                           std::istreambuf_iterator<char>()
                                   };

                                   auto nparsed = http_parser_execute(parser_.get(),
                                                                      &settings,
                                                                      data.data(),
                                                                      data.size());


                                   if (parser_->upgrade) {
                                       /* handle new protocol */
                                   }

                                   auto* user_data = static_cast<struct my_http_data*>(parser_->data);
                                   user_data->header_fields;


                                   // we just print the data, you can here call other api's
                                   // or whatever the server needs to do with the received data
                                   //std::cout << data << std::endl << std::endl;

                                   // todo something write

                                   read();
                               } else {
                                   std::cout << "error: " << ec << std::endl;;
                               }
                           });


}

void Session::write(std::size_t length) {
    auto self(shared_from_this());
    asio::async_write(socket_, asio::buffer(data_, length),
                      [this, self](asio::error_code ec, std::size_t /*length*/)
                      {
                          if (!ec)
                          {
                              read();
                          }
                      });
}


