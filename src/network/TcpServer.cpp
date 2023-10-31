//
// Created by bong on 23. 10. 31.
//

#include "TcpServer.h"
#include "Session.h"
#include <iostream>

/***
 *  constructor
 * @param io_context
 * @param port
 */
TcpServer::TcpServer(asio::io_context &io_context, short port)
        : acceptor_(io_context, tcp::endpoint(tcp::v4(), port)) {
    // now we call do_accept() where we wait for clients
    accept();
}

void TcpServer::accept() {
    // this is an async accept which means the lambda function is
    // executed, when a client connects
    acceptor_.async_accept([this](asio::error_code ec, tcp::socket socket) {
        if (!ec) {
            // let's see where we created our session
            std::cout << "creating session on: "
                      << socket.remote_endpoint().address().to_string()
                      << ":" << socket.remote_endpoint().port() << '\n';
            // create a session where we immediately call the run function
            // note: the socket is passed to the lambda here
            std::make_shared<Session>(std::move(socket))->run();
        } else {
            std::cout << "error: " << ec.message() << std::endl;
        }
        // since we want multiple clients to connnect, wait for the next one by calling do_accept()
        accept();
    });
}


