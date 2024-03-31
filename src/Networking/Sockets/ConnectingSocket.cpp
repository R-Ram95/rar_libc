#include "ConnectingSocket.hpp"

// Constructor
RAR::ConnectingSocket::ConnectingSocket(int domain, int service, int protocol, int port, u_long interface) : SimpleSocket(domain, service, protocol, port, interface)
{
    // Connect socket to host machine
    connect_to_network(get_sock(), get_address());
    // make sure connection works
    test_connection(connection);
}

// Implementation of connect_to_network virtual function
void RAR::ConnectingSocket::connect_to_network(int sock, struct sockaddr_in address)
{
    connection = connect(sock, (struct sockaddr *)&address, sizeof(address));
}

// Getters
int RAR::ConnectingSocket::get_connection()
{
    return connection;
}