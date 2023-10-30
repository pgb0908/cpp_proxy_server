
add_library(server
        http_server.cpp
        http_server_connection.cpp
)

target_link_libraries(server
        http_parser::http_parser
        asio::asio
        JsonCpp::JsonCpp
        boost::boost
        )


add_executable(http_server main.cpp)

target_link_libraries(http_server
        server)
