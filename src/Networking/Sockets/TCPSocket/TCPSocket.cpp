#include "TCPSocket.hpp"

//
RAR::TCPSocket::TCPSocket(int port, int bklg) : ServerSocket(AF_INET, SOCK_STREAM, 0)
{
    // bind socket to address
    assign_address(AF_INET, port, INADDR_ANY);
    listen_on_socket(bklg);
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

char &RAR::TCPSocket::receive_request()
{

    set_sock(accept_connection());
    int val_read = read(get_sock(), buffer, 30000);

    // failed to read bytes
    if (val_read < 0)
    {
        perror("Failed to read ...");
        exit(EXIT_FAILURE);
    }

    return *buffer;
}

void RAR::TCPSocket::send_response(char *request)
{

    int written = write(get_sock(), request, strlen(request) + 1);
    close(get_sock());
}
