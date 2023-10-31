
add_subdirectory(network)

add_executable(http_server
        HttpServer.cpp
        )


target_link_libraries(http_server
        network_server
        http_parser::http_parser
        JsonCpp::JsonCpp
        )
