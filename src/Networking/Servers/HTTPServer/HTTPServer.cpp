#include "HTTPServer.hpp"

RAR::HTTPServer::HTTPServer()
{
    tcp_socket = new TCPSocket(80);
    tcp_socket->listen_on_socket(10);
    run();
}

void RAR::HTTPServer::read_request()
{
    new_socket = tcp_socket->accept_connection();
    int val_read = read(new_socket, buffer, 30000);

    // failed to read bytes
    if (val_read < 0)
    {
        perror("Failed to read ...");
        exit(EXIT_FAILURE);
    }
}

void RAR::HTTPServer::handle_request()
{

    // parse the request
    std::cout << buffer << std::endl;
}

void RAR::HTTPServer::send_response()
{
    const char *hello = "Hello from server";
    int written = write(new_socket, hello, strlen(hello) + 1);
    close(new_socket);
}

void RAR::HTTPServer::run()
{
    while (true)
    {
        std::cout << "============ WAITING ============" << std::endl;
        read_request();
        handle_request();
        send_response();
        std::cout << "=========== DONE =============" << std::endl;
    }
}
