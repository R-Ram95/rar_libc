
#include "ServerSocket.hpp"

RAR::ServerSocket::ServerSocket(int domain, int service, int protocol) : SimpleSocket(domain, service, protocol){};

void RAR::ServerSocket::assign_address(int domain, int port, u_long interface)
{
    struct sockaddr_in address = SimpleSocket::get_address();
    int sock = SimpleSocket::get_sock();

    // configure address
    address.sin_family = domain;
    address.sin_port = htons(port);
    address.sin_addr.s_addr = htonl(interface);

    // bind to address
    int binding = bind(sock, (struct sockaddr *)&address, sizeof(address));

    // is the connection successful?
    SimpleSocket::test_connection(binding);
}