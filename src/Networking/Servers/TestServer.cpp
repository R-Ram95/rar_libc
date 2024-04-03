#include "TestServer.hpp"

RAR::TestServer::TestServer()
{
    tcp_socket = new TCPSocket(80);
    new_socket = tcp_socket->get_sock();
    tcp_socket->listen_on_socket(10);
    launch();
}

void RAR::TestServer::accepter()
{
    new_socket = tcp_socket->accept_connection();
    int val_read = read(new_socket, buffer, 30000);
    if (val_read < 0)
    {
        perror("Failed to read ...");
        exit(EXIT_FAILURE);
    }
}

void RAR::TestServer::handler()
{
    std::cout << buffer << std::endl;
}

void RAR::TestServer::responder()
{
    const char *hello = "Hello from server";
    int written = write(new_socket, hello, strlen(hello) + 1);
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
