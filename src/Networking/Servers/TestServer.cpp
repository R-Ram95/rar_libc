#include "TestServer.hpp"

RAR::TestServer::TestServer() : SimpleServer(AF_INET, SOCK_STREAM, 0, 80, INADDR_ANY, 10)
{
    launch();
}

void RAR::TestServer::accepter()
{
    struct sockaddr_in address = get_socket()->get_address();
    int addrlen = sizeof(address);
    int new_socket = accept(get_socket()->get_sock(), (struct sockaddr *)&address, (socklen_t *)&addrlen);

    read(new_socket, buffer, 30000);
}

void RAR::TestServer::handler()
{
    std::cout << buffer << std::endl;
}

void RAR::TestServer::responder()
{
    char *hello = "Hello from server";
    write(new_socket, hello, strlen(hello));
    close(new_socket);
}

void RAR::TestServer::launch()
{
    while (true)
    {
        std::cout << "============ WAITING ============" << std::endl;
        accepter();
        handler();
        responder();
        std::cout << "=========== DONE =============" << std::endl;
    }
}