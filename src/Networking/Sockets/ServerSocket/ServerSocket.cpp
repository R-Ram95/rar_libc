
#include "ServerSocket.hpp"

RAR::ServerSocket::ServerSocket(int domain, int service, int protocol) : SimpleSocket(domain, service, protocol){};

void RAR::ServerSocket::assign_address(int domain, int port, u_long interface)
{
    struct sockaddr_in address = get_address();
    int sock = get_sock();

    // configure address
    address.sin_family = domain;
    address.sin_port = htons(port);
    address.sin_addr.s_addr = htonl(interface);

    // set the address in the parent object
    set_address(address);

    // bind to address
    int binding = bind(sock, (struct sockaddr *)&address, sizeof(address));

    // is the connection successful?
    test_connection(binding);
}