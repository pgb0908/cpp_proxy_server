//
// Created by bong on 23. 10. 31.
//

#include "Session.h"
#include <iostream>


void Session::read() {
    auto self(shared_from_this());
    socket_.async_read_some(asio::buffer(data_, max_length),
                            [this, self](asio::error_code ec, std::size_t length)
                            {
                                if (!ec)
                                {
                                    auto buffer = asio::buffer(data_, max_length);

                                    /* Start up / continue the parser.
                                     * Note we pass recved==0 to signal that EOF has been received.
                                     */
                                    auto nparsed = http_parser_execute(parser.get(),
                                                                       &settings,
                                                                       asio::buffer_cast<const char*>(buffer),
                                                                       asio::buffer_size(buffer));

                                    if (parser->upgrade) {
                                        /* handle new protocol */
                                    }
                                    else if (nparsed != asio::buffer_size(buffer)) {
                                        /* Handle error. Usually just close the connection. */
                                        std::cout << "can not parsed!!! error" << std::endl;
                                    }

                                    //write(length);
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
