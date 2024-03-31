#include <stdio.h>
#include "SimpleSocket.hpp"

namespace RAR
{
    // Server side socket
    class BindingSocket : public SimpleSocket
    {
    public:
        // Constructor
        BindingSocket(int domain, int service, int protocol, int port, u_long interface);
        // Virtual function from parent
        int connect_to_network(int sock, struct sockaddr_in address);
    };
}