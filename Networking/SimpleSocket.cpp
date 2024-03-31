#include "SimpleSocket.hpp"

// Default Constructor

RAR::SimpleSocket::SimpleSocket(int domain, int service, int protocol, int port, u_long interface)
{
    // Defined address structure
    address.sin_family = domain;
    address.sin_port = htons(port);
    address.sin_addr.s_addr = htonl(interface);

    // Establish socket
    sock = socket(domain, service, protocol);
    test_connection(sock);
    // Connect socket to host device
    connection = connect_to_network(sock, address);
    test_connection(connection);
}

// Test connection virtual function

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

int RAR::SimpleSocket::get_connection()
{
    return connection;
}
