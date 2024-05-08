#ifndef ServerSocket_hpp
#define ServerSocket_hpp

#include "SimpleSocket.hpp"
namespace RAR
{
    class ServerSocket : public SimpleSocket
    {
    private:
    public:
        /* CONSTRUCTOR */
        ServerSocket(int domain, int service, int protocol);

        /**
         * @brief Inherited from SimpleSocket and implemented here to use the
         * bind() system call from sys/socket.h
         *
         */
        void assign_address(int domain, int port, u_long interface);

        /**
         * @brief - Wait for incoming connections on a socket
         *
         * @param bklg - number of connection requests to queue
         */
        virtual void listen_on_socket(int bklg) = 0;

        /**
         * @brief - get the first connection request from a que
         *
         */
        virtual int accept_connection() = 0;
    };
};
#endif /* ServerSocket_hpp*/