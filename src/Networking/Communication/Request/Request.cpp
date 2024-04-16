#include "Request.hpp"

RAR::Request::Request(char *request_string)
{
    request = request_string;
    // make copy because we will be tokenizing
    char request_copy[strlen(request_string) + 1];
    strcpy(request_copy, request_string);

    // separate the request headers from the body - seperated by 2 blank lines (\n)
    for (int i = 0; i < strlen(request_copy) - 2; i++)
    {
        // we have encountered 2 blank lines in a row, replace
        if (request_copy[i] == '\n' && request_copy[i + 1] == '\n')
        {
            request_copy[i + 1] = '|';
        }
    }

    // split up request sections
    char *request_line = strtok(request_copy, "\n");
    char *request_headers = strtok(NULL, "|");
    char *body = strtok(NULL, "|");

    parse_request_line(request_line);
    parse_request_headers(request_headers);
}

/* PRIVATE FUNCTIONS*/
void RAR::Request::parse_request_line(char *request_line)
{
    request_method = strtok(request_line, " ");
    request_uri = strtok(nullptr, " ");
    http_version = strtok(nullptr, "\0");
}

void RAR::Request::parse_request_headers(char *request_headers)
{
    // first key
    char *header_key = strtok(request_headers, ": ");
    char *header_value = " ";

    // stop when we reach the end
    while (header_key && header_value)
    {
        // next line is a new key
        header_value = strtok(NULL, "\n");
        // header_value would be \0 if we were at the end
        if (header_value)
        {
            header_key = strtok(NULL, ": ");

            // add to map
            request_header_map[header_key] = header_value;
        }
    }
}

/** GETTERS */
char *RAR::Request::get_request_method()
{
    return request_method;
}

char *RAR::Request::get_request_uri()
{
    return request_uri;
}

char *RAR::Request::get_request()
{
    return request;
}
