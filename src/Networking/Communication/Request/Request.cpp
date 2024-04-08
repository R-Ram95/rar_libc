#include "Request.hpp"

RAR::Request::Request(char *request_string)
{
    char transformed_request[strlen(request_string)];
    strcpy(transformed_request, request_string);

    // separate the request headers from the body - seperated by 2 blank lines (\n)
    for (int i = 0; i < strlen(transformed_request) - 2; i++)
    {
        // we have encountered 2 blank lines in a row, replace
        if (transformed_request[i] == '\n' && transformed_request[i + 1] == '\n')
        {
            transformed_request[i + 1] = '|';
        }
    }

    // split up request sections
    char *request_line = strtok(transformed_request, "\n");
    char *header_fields = strtok(nullptr, "|");
    char *body = strtok(nullptr, "|");

    parse_request_line(request_line);
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
    // go through the request header string and make a key-value mapping of headers to values (HEADER : VALUE)
}