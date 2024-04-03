#include "TCPSocket.hpp"

//
RAR::TCPSocket::TCPSocket(int port) : ServerSocket(AF_INET, SOCK_STREAM, 0)
{
    // bind socket to address
    ServerSocket::assign_address(AF_INET, port, INADDR_ANY);
}

void RAR::TCPSocket::listen_on_socket(int bklg)
{
    int sock = SimpleSocket::get_sock();
    // listen on the socket
    int listening = listen(sock, bklg);
    // was the connection successful?
    SimpleSocket::test_connection(listening);
}

void RAR::TCPSocket::accept_connection()
{
    int sock = SimpleSocket::get_sock();
    struct sockaddr_in address = SimpleSocket::get_address();
    int addrlen = sizeof(address);

    // pass in the size of the memory address of the address length
    int accepting = accept(sock, (struct sockaddr *)&address, (socklen_t *)&addrlen);
}