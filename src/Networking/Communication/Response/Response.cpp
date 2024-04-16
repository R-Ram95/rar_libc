#include "Response.hpp"

RAR::Response::Response()
{
    content_type = "";
    content_length = 0;
}

/** GETTERS */
// Construct string of response
char *RAR::Response::get_response_string() {}

/** SETTERS */
void RAR::Response::set_http_version(char *version)
{
    http_version = version;
}

void RAR::Response::set_status_code(int code)
{
    status_code = code;
}

void RAR::Response::set_status_message(char *message)
{
    status_message = message;
}

void RAR::Response::set_content_type(char *type)
{
    content_type = type;
}

void RAR::Response::set_content_length(int length)
{
    content_length = length;
}