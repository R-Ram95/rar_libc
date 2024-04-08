#include "TCPSocket.hpp"

// Create the socket and bind it to the specified port
RAR::TCPSocket::TCPSocket(int port) : ServerSocket(AF_INET, SOCK_STREAM, 0)
{
    // bind socket to address
    assign_address(AF_INET, port, INADDR_ANY);
}

void RAR::TCPSocket::listen_on_socket(int bklg)
{
    // listen on the socket
    int listening = listen(get_sock(), bklg);
    // was the connection successful?
    test_connection(listening);
}

int RAR::TCPSocket::accept_connection()
{
    struct sockaddr_in address = get_address();
    int addrlen = sizeof(address);

    // pass in the size of the memory address of the address length
    return accept(get_sock(), (struct sockaddr *)&address, (socklen_t *)&addrlen);
}