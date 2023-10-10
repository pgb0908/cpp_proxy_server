//
// Created by bong on 23. 10. 10.
//

#include <cstdlib>
#include <cstring>
#include <iostream>
#include <asio.hpp>
#include <string>

using asio::ip::tcp;
using namespace std;

enum { max_length = 1024 };

int main(){

    try {
        while(true){
            asio::io_context io_context;

            tcp::socket s(io_context);
            tcp::resolver resolver(io_context);
            asio::connect(s, resolver.resolve("127.0.0.1", "9000"));

            std::cout << "Enter message: ";
            char request[max_length];
            std::cin.getline(request, max_length);
            size_t request_length = std::strlen(request);
            asio::write(s, asio::buffer(request, request_length));

            char reply[max_length];
            size_t reply_length = asio::read(s,
                                             asio::buffer(reply, request_length));
            std::cout << "Reply is: ";
            std::cout.write(reply, reply_length);
            std::cout << "\n\n";
        }
    }
    catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << "\n";
    }

    return 0;
    
}