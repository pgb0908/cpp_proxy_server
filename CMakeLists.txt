cmake_minimum_required(VERSION 3.15)
project(myProxy LANGUAGES CXX)


find_package(asio)

add_subdirectory(src/server)
add_subdirectory(src/client)