//
// Created by bong on 23. 10. 31.
//

#include "Session.h"
#include <iostream>


void Session::waitForRequest(){
    // since we capture `this` in the callback, we need to call shared_from_this()
    auto self(shared_from_this());
    // and now call the lambda once data arrives
    // we read a string until the null termination character
    asio::async_read_until(m_socket, m_buffer, "\0",
                           [this, self](asio::error_code ec, std::size_t /*length*/)
                           {
                               // if there was no error, everything went well and for this demo
                               // we print the data to stdout and wait for the next request
                               if (!ec)  {
                                   std::string data{
                                           std::istreambuf_iterator<char>(&m_buffer),
                                           std::istreambuf_iterator<char>()
                                   };
                                   // we just print the data, you can here call other api's
                                   // or whatever the server needs to do with the received data
                                   std::cout << data << std::endl;
                                   waitForRequest();
                               } else {
                                   std::cout << "error: " << ec << std::endl;;
                               }
                           });
}