//
// Created by bong on 23. 10. 31.
//

#include "Session.h"
#include <iostream>


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

                                   auto nparsed = http_parser_execute(parser.get(),
                                                                      &settings,
                                                                      data.data(),
                                                                      data.size());


                                   if (parser->upgrade) {
                                       /* handle new protocol */
                                   }

                                   // we just print the data, you can here call other api's
                                   // or whatever the server needs to do with the received data
                                   std::cout << data << std::endl << std::endl;
                                   //wait_for_request();
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
