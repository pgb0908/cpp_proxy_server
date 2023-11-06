

add_library(network_server
        TcpServer.cpp
        Session.cpp)

target_link_libraries(network_server
        asio::asio
        http_parser::http_parser
        )