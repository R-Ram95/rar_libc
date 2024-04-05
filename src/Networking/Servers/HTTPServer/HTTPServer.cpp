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
    // TODO This probably won't work, we need to initialize the size of the buffer somewhere
    int val_read = read(new_socket, buffer.data(), buffer.size());

    // failed to read bytes
    if (val_read < 0)
    {
        perror("Failed to read ...");
        exit(EXIT_FAILURE);
    }

    // TODO Build request object here
}

void RAR::HTTPServer::handle_request()
{

    // parse the request
    std::cout << buffer.data() << std::endl;

    // TODO Log the request => print to console, print to file

    // TODO Build Reponse Object here based on the request object
    // check the request method
    // check if the file exists
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
