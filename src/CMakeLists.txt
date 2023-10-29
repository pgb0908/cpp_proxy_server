

add_library(server
        http_server.cpp
        http_server_connection.cpp
)

target_link_libraries(server asio::asio)