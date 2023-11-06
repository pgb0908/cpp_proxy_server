//
// Created by bong on 23. 10. 31.
//

#ifndef MYPROXY_TCPSERVER_H
#define MYPROXY_TCPSERVER_H

#include "asio.hpp"
#include "http_parser.h"

using namespace asio::ip;

class TcpServer {
public:
    // we need an io_context and a port where we listen to
    TcpServer(asio::io_context& io_context, short port);


private:
    void accept();

    tcp::acceptor acceptor_;





};


#endif //MYPROXY_TCPSERVER_H
