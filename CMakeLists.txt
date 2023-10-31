cmake_minimum_required(VERSION 3.15)
project(myProxy LANGUAGES CXX)

find_package(asio)
find_package(http_parser)
find_package(jsoncpp)
find_package(Boost)

add_subdirectory(src)
add_subdirectory(example)


add_subdirectory(test)