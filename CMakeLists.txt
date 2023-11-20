cmake_minimum_required(VERSION 3.15)
project(myProxy LANGUAGES CXX)

set(MYPROXY_ROOT ${CMAKE_CURRENT_SOURCE_DIR})

find_package(asio)
find_package(http_parser)
find_package(jsoncpp)
find_package(Boost)

include_directories(${MYPROXY_ROOT}/src/external)
include_directories(${MYPROXY_ROOT}/src/lib)
include_directories(${MYPROXY_ROOT}/src/util)

add_subdirectory(src)
add_subdirectory(example)



add_subdirectory(test)