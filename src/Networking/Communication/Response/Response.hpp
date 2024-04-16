// Minimum requirments:
// Response Line -  HTTP VERSION STATUS CODE STATUS MESSAGE
// Content-Type - e.g. text/plain
// Content-Length - number of bytes to send

// body -

#ifndef RESPONSE_HPP
#define RESPONSE_HPP

namespace RAR
{
    class Response
    {
    private:
        char *http_version;
        int status_code;
        char *status_message;
        char *content_type;
        int content_length;
        char *body;

    public:
        Response();

        /** GETTERS */
        char *get_response_string();

        /** SETTERS */
        void set_http_version(char *);
        void set_status_code(int);
        void set_status_message(char *);
        void set_content_type(char *);
        void set_content_length(int);
    };
};

#endif RESPONSE_HPP /* response_hpp*/