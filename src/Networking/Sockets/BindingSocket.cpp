#include "BindingSocket.hpp"

// Constructor
RAR::BindingSocket::BindingSocket(int domain, int service, int protocol, int port, u_long interface) : SimpleSocket(domain, service, protocol, port, interface)
{
    // Connect socket to host device and pass connection to parent
    connect_to_network(get_sock(), get_address());
    // make sure the connection is actually working
    test_connection(binding);
}

// Implementation of connect_to_network virtual function
void RAR::BindingSocket::connect_to_network(int sock, struct sockaddr_in address)
{
    binding = bind(sock, (struct sockaddr *)&address, sizeof(address));
}

int RAR::BindingSocket::get_binding()
{
    return binding;
}