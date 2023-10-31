//
// Created by bong on 23. 10. 31.
//

#include "HttpServer.h"

void HttpServer::start() {
    ioContextPtr->run();
}

HttpServer::HttpServer() :
ioContextPtr(std::make_unique<asio::io_context>()){
    tcpServerPtr = std::make_unique<TcpServer>(*ioContextPtr, 9990);
}
