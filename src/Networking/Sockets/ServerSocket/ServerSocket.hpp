#ifndef ServerSocket_hpp
#define ServerSocket_hpp

#include "../SimpleSocket/SimpleSocket.hpp"
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
    };
};
#endif /* ServerSocket_hpp*/