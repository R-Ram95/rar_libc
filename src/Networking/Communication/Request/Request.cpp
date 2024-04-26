#include "Request.hpp"

RAR::Request::Request(const std::string &request_string)
{
    m_request = request_string;
    std::vector<std::string> tokens = tokenize_string(request_string, '\n');

    // first line is the request_line
    parse_request_line(tokens.front());

    // TODO LATER => parse request_headers and body
}

std::vector<std::string> RAR::Request::tokenize_string(const std::string &str, char delimeter)
{
    std::vector<std::string> tokens;
    int left_ptr = 0;
    int right_ptr = 0;

    while (right_ptr < str.length())
    {
        if (str[right_ptr] == delimeter)
        {
            tokens.push_back(str.substr(left_ptr, right_ptr - left_ptr));
            left_ptr = right_ptr + 1;
        }
        right_ptr++;
    }

    // get the last token
    if (left_ptr < str.length())
    {
        tokens.push_back(str.substr(left_ptr));
    }
    return tokens;
}

void RAR::Request::parse_request_line(const std::string &request_line)
{
    std::vector<std::string> rl_tokens = tokenize_string(request_line, ' ');
    m_request_method = rl_tokens[0];
    m_request_uri = rl_tokens[1];
    m_http_version = rl_tokens[2];
}

/** GETTERS */
std::string RAR::Request::get_request_method()
{
    return m_request_method;
}

std::string RAR::Request::get_request_uri()
{
    return m_request_uri;
}

std::string RAR::Request::get_http_version()
{
    return m_http_version;
}

// TODO Override <<
std::string RAR::Request::get_request()
{
    return m_request;
}
