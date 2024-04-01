#include <stdio.h>
#include "SimpleSocket.hpp"

namespace RAR
{
    /**
     * Definition for a Client side socket
     */
    class ConnectingSocket : public SimpleSocket
    {
    private:
        // Stores 0 if connection is successful
        int connection;
        // Opens a connection on the provided socket
        void connect_to_network(int sock, struct sockaddr_in address);

    public:
        /* CONSTRUCTORS */
        ConnectingSocket(int domain, int service, int protocol, int port, u_long interface);

        /* GETTERS */
        int get_connection();
    };
};
