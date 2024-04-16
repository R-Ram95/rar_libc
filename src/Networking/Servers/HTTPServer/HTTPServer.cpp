#include "HTTPServer.hpp"

RAR::HTTPServer::HTTPServer()
{
    tcp_socket = new TCPSocket(81);
    tcp_socket->listen_on_socket(10);
    run();
}

void RAR::HTTPServer::read_request()
{
    socket_fd = tcp_socket->accept_connection();
    int bytes_read = read(socket_fd, buffer, sizeof(buffer));

    if (bytes_read < 0)
    {
        perror("Failed to read ...");
        exit(EXIT_FAILURE);
    }

    RAR::Request *request = new RAR::Request(buffer);
    std::cout << request->get_request_method() << std::endl;
    std::cout << request->get_request_uri() << std::endl;
}

void RAR::HTTPServer::handle_request()
{

    // parse the request
    // std::cout << buffer << std::endl;

    // TODO Log the request => print to console, print to file

    // TODO Build Reponse Object here based on the request object
    // check the request method
    // check if the file exists
}

void RAR::HTTPServer::send_response()
{
    const char *hello = "Hello from server";
    int written = write(socket_fd, hello, strlen(hello) + 1);
    close(socket_fd);
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
