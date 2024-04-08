
#include <cstring>
#include <iostream>

#ifndef Request_hpp
#define Request_hpp

namespace RAR
{

    class Request
    {
    private:
        char *request_method;
        // Request object with file path
        char *request_uri;
        char *http_version;
        // body of the request, will be blank for GET
        char *body;

        // extract fields from request line
        void parse_request_line(char *request_string);
        void parse_request_headers(char *request_headers);
        void parse_request_body(char *request_body);

    public:
        /* CONSTRUCTORS*/
        Request(char *request_string);

        /* GETTERS */
        char *get_request_method();
        char *get_request_uri();
        char *get_http_version();
    };
};

#endif /* Request_hpp*/