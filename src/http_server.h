//
// Created by bong on 23. 10. 21.
//

#ifndef MYPROXY_HTTP_SERVER_H
#define MYPROXY_HTTP_SERVER_H

#include <cstdlib>
#include <iostream>
#include <memory>
#include <utility>
#include <asio.hpp>
#include "http_server_connection.h"


template<typename RequestHandler>
class http_server {
public:
    using  connection_type = basic_http_connection<RequestHandler>;

    http_server(asio::io_service &io_svc,
                const asio::ip::tcp::endpoint& endpoint_,
                RequestHandler request_handler = RequestHandler());

    /**
     * Start asynchronous accept.
     */
    void start_accept();

    /**
     * Stop accepting new connections
     */
    void stop_accept();

    /**
     * New client connected
     */
    void handle_accept(typename connection_type::pointer new_connection,
                       const std::error_code &error);

    void handle_request(typename connection_type::pointer connection);

    inline asio::ip::tcp::acceptor &get_acceptor() {
        return acceptor_;
    }

private:
    asio::io_service &io_svc_;

    /**
     * It waits for sockets
     */
    asio::ip::tcp::acceptor acceptor_;
    RequestHandler request_handler_;
};


#endif //MYPROXY_HTTP_SERVER_H
