

add_library(network_server
        TcpServer.cpp
        Session.cpp)

target_link_libraries(network_server
        asio::asio
        proxy_lib
        myproxy_http_parser
        )