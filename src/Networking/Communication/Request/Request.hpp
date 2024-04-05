
#include <string>
#include <vector>

#ifndef Request_hpp
#define Request_hpp

namespace RAR
{
    struct request_line
    {
        std::string method;
        std::string request_uri;
        std::string http_version;
    };

    class Request
    {
    private:
        struct request_line request_line;
        std::string header_fields;
        std::string body;

    public:
        Request();
        void parse_request(char *buffer);
    };
};

#endif /* Request_hpp*/