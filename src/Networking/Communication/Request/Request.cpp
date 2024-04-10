#include "Request.hpp"

RAR::Request::Request(char *request_string)
{
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
    char *request_headers = strtok(nullptr, "|");
    char *body = strtok(nullptr, "|");

    std::cout << "REQUEST LINE" << std::endl;
    std::cout << request_line << std::endl;

    std::cout << "REQUEST HEADER" << std::endl;
    std::cout << request_headers << std::endl;

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
    // make copy because we will be tokenizing and we want to preserver the original
    char header_copy[strlen(request_headers) + 1];
    strcpy(header_copy, request_headers);

    std::cout << "REQUEST HEADER in PARSE HEADERS" << std::endl;
    std::cout << request_headers << std::endl;

    std::cout << "HEADER COPY  in PARSE HEADERS" << std::endl;
    std::cout << header_copy << std::endl;
    // go through the request header string and make a key-value mapping of headers to values (HEADER : VALUE)
    char *header1 = strtok(header_copy, ": ");

    std::cout << "header1" << std::endl;
    std::cout << header1 << std::endl;
    std::cout << "request headers after" << std::endl;
    std::cout << header_copy << std::endl;
}