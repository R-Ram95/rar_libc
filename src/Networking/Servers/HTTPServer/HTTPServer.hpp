
#ifndef HTTPServer_hpp
#define HTTPServer_hpp

#include <cstring>
#include <unistd.h>
#include "../../rarlibc-networking.hpp"
#include <vector>

namespace RAR
{
    class HTTPServer
    {
    private:
        // todo, this probably won't work, we need to initialize the size of the buffer somwhere
        std::vector<char> buffer;
        int new_socket;
        TCPSocket *tcp_socket;

        // TODO Create two structs:
        // 1 - Request
        struct Request;
        // 2 - Response

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