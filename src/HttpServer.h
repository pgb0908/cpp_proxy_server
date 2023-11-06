//
// Created by bong on 23. 10. 31.
//

#ifndef MYPROXY_HTTPSERVER_H
#define MYPROXY_HTTPSERVER_H

#include "network/TcpServer.h"
#include <memory>


class HttpServer {
public:
    HttpServer();

    void start();

private:
    std::unique_ptr<TcpServer> tcpServerPtr;
    std::unique_ptr<asio::io_context> ioContextPtr;

};

#endif //MYPROXY_HTTPSERVER_H
