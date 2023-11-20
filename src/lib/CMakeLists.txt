add_library(proxy_lib
        ./http/HTTPException.cpp
        ./http/HTTPHeaders.cpp
        ./http/HTTPCommonHeaders.cpp
        ./http/codec/HTTP1xCodec.cpp)

target_include_directories(
        proxy_lib
        ./http/HTTPException.h
)
