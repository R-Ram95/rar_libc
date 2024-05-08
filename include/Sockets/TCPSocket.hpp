
#ifndef TCPSocket_hpp
#define TCPSocket_hpp

#include "ServerSocket.hpp"
namespace RAR
{
    class TCPSocket : public ServerSocket
    {
    private:
    public:
        /* CONSTRUCTOR*/
        /**
         * @brief Construct a new TCPSocket object in the IPV4 domain. Creates a ServerSocket as a tcp type ( service = SOCK_STREAM)
         * and binds it to a transport address on the specifed port in the internet protocol domain (domain = AF_INET).
         * Uses the default protocol (protocol = 0)
         */
        TCPSocket(int port);

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
    };

};
#endif /* TCPSocket_hpp*/