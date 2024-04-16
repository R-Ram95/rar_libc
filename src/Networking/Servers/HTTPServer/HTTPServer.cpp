#include "HTTPServer.hpp"

char *ROOT_PATH = "serve";

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

    request = new RAR::Request(buffer);
}

void RAR::HTTPServer::handle_request()
{

    // Log Request
    std::cout << "Logging Request ..." << std::endl;
    std::cout << request->get_request() << std::endl;
    response = new Response();
    response->set_http_version(request->get_http_version());

    // only supports GET => if not we should return with content type and length
    if (request->get_request_method() != "GET")
    {
        response->set_status_code(405);
        response->set_status_message("Method Not Allowed");
        // TODO set message, content type, and length
        return;
    }

    // check if the file exists
    // char *file_path = strcat(ROOT_PATH, request->get_request_uri());
    // read file -> bytes
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
