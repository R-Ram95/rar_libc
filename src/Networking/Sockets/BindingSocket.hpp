#include <stdio.h>
#include "SimpleSocket.hpp"

namespace RAR
{
    /**
     * Definition for a server side socket
     */
    class BindingSocket : public SimpleSocket
    {
    private:
        // Stores 0 if binding is successful
        int binding;
        // Virtual function from parent
        void connect_to_network(int sock, struct sockaddr_in address);

    public:
        /* CONSTRUCTORS */
        BindingSocket(int domain, int service, int protocol, int port, u_long interface);

        /* CONSTRUCTORS */
        int get_binding();
    };
}