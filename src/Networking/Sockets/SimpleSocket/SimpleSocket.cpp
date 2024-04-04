#include "SimpleSocket.hpp"

// Constructor
RAR::SimpleSocket::SimpleSocket(int domain, int service, int protocol)
{

    // Establish socket
    sock = socket(domain, service, protocol);
    test_connection(sock);
}

// Make sure the connection (socket, bind, listen, accept, etc.) is successful
void RAR::SimpleSocket::test_connection(int item_to_test)
{
    // confirm that the socket or connection has been properly established
    if (item_to_test < 0)
    {
        perror("Failed to connect ...");
        // TODO MAKE Virtual so user needs to implement what happens on failure
        exit(EXIT_FAILURE);
    }
}

// Getter functions
struct sockaddr_in RAR::SimpleSocket::get_address()
{
    return address;
}

int RAR::SimpleSocket::get_sock()
{
    return sock;
}

// Setter functions
void RAR::SimpleSocket::set_address(struct sockaddr_in addr)
{
    address = addr;
}

void RAR::SimpleSocket::set_sock(int socket)
{
    sock = socket;
}