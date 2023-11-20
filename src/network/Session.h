//
// Created by bong on 23. 10. 31.
//

#ifndef MYPROXY_SESSION_H
#define MYPROXY_SESSION_H

#include <memory>
#include <asio.hpp>
#include <http_parser.h>
#include <stack>

using namespace asio::ip;

#define MAX_HEADERS 10
#define MAX_ELEMENT_SIZE 500


// this was created as shared ptr and we need later `this`
// therefore we need to inherit from enable_shared_from_this
class Session : public std::enable_shared_from_this<Session>
{
public:
    // our sesseion holds the pParser
    explicit Session(tcp::socket pParser);


    // and run was already called in our server, where we just wait for requests
    void run() {
        read();
    }
private:
    void read();
    void write(std::size_t length);

private:
    tcp::socket socket_;
    asio::streambuf m_buffer;
    enum { max_length = 1024 };
    char data_[max_length]{};

    // https://github.com/nodejs/http-parser
    http_parser_settings settings{};
    std::unique_ptr<http_parser> parser_;

    struct my_http_data {
        char method[64]{};
        //char header_fields[MAX_HEADERS][1024];
        std::stack<std::pair<std::string, std::string>> header_fields;
        int current_header_index{};
    };

    my_http_data http_data_;

    static int on_message_begin(http_parser* parser){
        //printf("HTTP 메시지 시작\n");
        auto* user_data = (struct my_http_data*)parser->data;
        user_data->current_header_index = 0;
        return 0;
    }

    // HTTP 메서드가 파싱될 때 호출되는 콜백
    static int on_url(http_parser* parser, const char *at, size_t length) {
        //printf("메서드: %.*s\n", (int)length, at);
        auto* user_data = (struct my_http_data*)parser->data;
        strncpy(user_data->method, at, length);
        user_data->method[length] = '\0';
        return 0;
    }

    // HTTP 헤더가 파싱될 때 호출되는 콜백
    static int on_header_field(http_parser* parser, const char *at, size_t length) {
        struct my_http_data* user_data = (struct my_http_data*)parser->data;
        if (user_data->current_header_index < MAX_HEADERS) {
            std::string field(at, length);
            user_data->header_fields.emplace(field, "");

            user_data->current_header_index++;
        }
        return 0;
    }

    // HTTP 헤더 값이 파싱될 때 호출되는 콜백
    static int on_header_value(http_parser* parser, const char *at, size_t length) {
        //printf("헤더 값: %.*s\n", (int)length, at);
        struct my_http_data* user_data = (struct my_http_data*)parser->data;
        if (user_data->current_header_index < MAX_HEADERS) {
            std::string field_data(at, length);
            auto front = user_data->header_fields.top();
            auto field = front.first;
            user_data->header_fields.pop();
            user_data->header_fields.emplace(field, field_data);

            user_data->current_header_index++;
        }
        return 0;
    }


    static int message_complete_cb(http_parser* parser){
        //printf("HTTP 메시지 완료\n");
        return 0;
    }

};

#endif //MYPROXY_SESSION_H
