//
// Created by bong on 23. 10. 31.
//

#ifndef MYPROXY_SESSION_H
#define MYPROXY_SESSION_H

#include <memory>
#include <asio.hpp>

using namespace asio::ip;

// this was created as shared ptr and we need later `this`
// therefore we need to inherit from enable_shared_from_this
class Session : public std::enable_shared_from_this<Session>
{
public:
    // our sesseion holds the socket
    Session(tcp::socket socket)
            : socket_(std::move(socket)) { }

    // and run was already called in our server, where we just wait for requests
    void run() {
        read();
    }
private:
    void read();
    void write(std::size_t length);

private:
    tcp::socket socket_;
    asio::streambuf m_buffer;
    enum { max_length = 1024 };
    char data_[max_length];
};

#endif //MYPROXY_SESSION_H
