//
// Created by bong on 23. 10. 31.
//

#ifndef MYPROXY_SESSION_H
#define MYPROXY_SESSION_H

#include <memory>
#include <asio.hpp>
#include <http_parser.h>

using namespace asio::ip;

// this was created as shared ptr and we need later `this`
// therefore we need to inherit from enable_shared_from_this
class Session : public std::enable_shared_from_this<Session>
{
public:
    // our sesseion holds the socket
    Session(tcp::socket socket)
            : socket_(std::move(socket)) {


        settings.on_url = [](http_parser*, const char *at, size_t length)->int{ return 0;};
        settings.on_header_field = [](http_parser*, const char *at, size_t length)->int{ return 0;};

        parser = std::make_unique<http_parser>();
        http_parser_init(parser.get(), HTTP_REQUEST);
        parser->data = &socket_;


    }

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

    // https://github.com/nodejs/http-parser
    http_parser_settings settings;
    std::unique_ptr<http_parser> parser;

};

#endif //MYPROXY_SESSION_H
