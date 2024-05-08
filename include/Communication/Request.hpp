
#include <string>
#include <iostream>
#include <vector>

#ifndef Request_hpp
#define Request_hpp

namespace RAR
{
    class Request
    {
    private:
        std::string m_request;
        std::string m_request_method;
        std::string m_request_uri;
        std::string m_http_version;

        // extract fields from request line
        /**
         * @brief tokenizes the string and returns a vector of the tokens based on the given
         * delimeter, TODO MOVE THIS TO A SEPARATE PART OF LIB
         *
         * @param delimeter
         * @return std::vector<std::string>
         */
        std::vector<std::string> tokenize_string(const std::string &, char delimeter);
        void parse_request_line(const std::string &request_line);

    public:
        /* CONSTRUCTORS*/
        /**
         * @brief Parses request string and builds Request
         *
         * @param request_string
         */
        Request(const std::string &request_string);

        /* GETTERS */
        std::string get_request_method();
        std::string get_request_uri();
        std::string get_http_version();
        std::string get_request();
    };
};

#endif /* Request_hpp*/