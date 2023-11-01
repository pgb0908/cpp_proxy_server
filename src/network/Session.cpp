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
                                    write(length);
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
