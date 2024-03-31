#include <stdio.h>
#include "SimpleSocket.hpp"

namespace RAR
{
    // Client side socket
    class ConnectingSocket : public SimpleSocket
    {
    private:
        // Stores 0 if connection is successful
        int connection;
        // Virtual function from parent
        void connect_to_network(int sock, struct sockaddr_in address);

    public:
        // Constructor
        ConnectingSocket(int domain, int service, int protocol, int port, u_long interface);

        // Getters
        int get_connection();
    };
};
