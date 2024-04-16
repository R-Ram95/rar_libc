
#include <cstring>
#include <unordered_map>

#ifndef Request_hpp
#define Request_hpp

namespace RAR
{

    class Request
    {
    private:
        // original request string
        char *request;
        char *request_method;
        // Request object with file path
        char *request_uri;
        char *http_version;
        // body of the request, will be blank for GET
        char *body;
        // TODO fix naming, confusing
        std::unordered_map<char *, char *> request_header_map;

        // extract fields from request line
        void parse_request_line(char *request_string);
        void parse_request_headers(char *request_headers);
        void parse_request_body(char *request_body);

    public:
        /* CONSTRUCTORS*/
        /**
         * @brief Parses request string and builds Request
         *
         * @param request_string
         */
        Request(char *request_string);

        /* GETTERS */
        char *get_request_method();
        char *get_request_uri();
        char *get_http_version();
        char *get_request();
    };
};

#endif /* Request_hpp*/