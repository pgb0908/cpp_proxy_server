//
// Created by bong on 23. 10. 31.
//

#include "http_server.h"
#include "http_server_connection.h"
#include "json/json.h"
#include <boost/lexical_cast.hpp>

struct http_request_handler
{
    typedef basic_http_connection<http_request_handler> connection;
    Json::Value get_json_data(const connection::pointer & ptr)
    {
        Json::Value result;
        result["url"] = ptr->get_request_url();
        Json::Value headers(Json::objectValue);
        std::ostringstream oss;
        for (connection::headers_type::const_iterator it = ptr->get_headers().begin(), end = ptr->get_headers().end();
             it != end; ++it)
        {
            headers[it->first] = it->second;
        }
        result["headers"] = headers;
        result["origin"] = boost::lexical_cast<std::string>(ptr->get_socket().local_endpoint().address());
        return result;
    }
    void operator()(const connection::pointer & ptr)
    {
        std::cout << "Request URL: " << ptr->get_request_url() << std::endl;
        if (ptr->get_request_url() == "/get")
        {
            if (ptr->get_request_method() != HTTP_GET)
            {
                ptr->send_response(405, "Method Not Allowed");
                return;
            }
            std::cout << "Request handler" << std::endl;
            Json::Value result = get_json_data(ptr);
            ptr->send_response(200, result.toStyledString());
            return;
        }
        if (ptr->get_request_url() == "/post")
        {
            if (ptr->get_request_method() != HTTP_POST)
            {
                ptr->send_response(405, "Method Not Allowed");
                return;
            }
            Json::Value result = get_json_data(ptr);
            result["data"] = ptr->get_request_body();
            ptr->send_response(200, result.toStyledString());
            return;
        }
        ptr->send_response(404, HTTP_404_TEMPLATE);
    }
};

int main(int argc, char *argv[]) {
    try {
        typedef http_server <http_request_handler> server_type;
        asio::io_service io_service;
        server_type srv(io_service, tcp::endpoint(tcp::v4(), 0));
        io_service.run();
    }
    catch (std::exception &e) {
        return 1;
    }
}