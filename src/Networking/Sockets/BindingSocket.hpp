#include <stdio.h>
#include "SimpleSocket.hpp"

namespace RAR
{
    // Server side socket
    class BindingSocket : public SimpleSocket
    {
    private:
        // Stores 0 if binding is successful
        int binding;
        // Virtual function from parent
        void connect_to_network(int sock, struct sockaddr_in address);

    public:
        // Constructor
        BindingSocket(int domain, int service, int protocol, int port, u_long interface);

        // Getters
        int get_binding();
    };
}