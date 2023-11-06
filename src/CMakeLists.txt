
add_subdirectory(network)

add_library(http_server
        HttpServer.cpp
        )


target_link_libraries(http_server
        network_server
        JsonCpp::JsonCpp
        )
