
#ifndef HTTPServer_hpp
#define HTTPServer_hpp

#include <cstring>
#include <fstream>
#include <unistd.h>
#include "../../rarlibc-networking.hpp"
#include "stdio.h"

namespace RAR
{

    class HTTPServer
    {
    private:
        char buffer[30000] = {0};

        // Socket file descriptor
        int socket_fd;
        TCPSocket *tcp_socket;

        Request *request;
        Response *response;

        /**
         * @brief Accepts connection on the tcp port, and parses the request into
         * the request member variable.
         *
         */
        void read_request();

        /**
         * @brief Reviews request member variable and prepares output buffer and response
         * logs the request as well.
         */
        void handle_request();

        /**
         * @brief Sends the response and closes the socket.
         *
         */
        void send_response();

    public:
        HTTPServer();
        void run();
    };
};
;

#endif /* HTTPServer_hpp */
