
#ifndef TCPSocket_hpp
#define TCPSocket_hpp

#include "../ServerSocket/ServerSocket.hpp"
#include <unistd.h>
#include <cstring>

namespace RAR
{
    // TODO CHANGE THIS TO TCPSOCKEIPV4 or something like that
    class TCPSocket : public ServerSocket
    {
    protected:
        char buffer[30000] = {0};

    private:
        /* VIRTUAL FUNCTION DEFINITION */
        /**
         * @brief - override from SimpleSocket => Waits for incoming connections
         *
         */
        void listen_on_socket(int bklg) override;

        /**
         * @brief override from SimpleSocket => accepts first connection in queue
         *
         */
        int accept_connection() override;

        /** Setters*/
        void set_buffer();

    public:
        /* CONSTRUCTOR*/
        /**
         * @brief Construct a new TCPSocket object. Creates a ServerSocket as a byte-stream socket type ( service = SOCK_STREAM)
         * and binds it to a transport address on the specifed port in the internet protocol domain (domain = AF_INET).
         * Uses the default protocol (protocol = 0)
         */
        TCPSocket(int port, int bklg);

        char &receive_request();

        void send_response(char *request);
    };

};
#endif /* TCPSocket_hpp*/