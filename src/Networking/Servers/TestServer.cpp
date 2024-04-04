#include "TestServer.hpp"

RAR::TestServer::TestServer()
{
    tcp_socket = new TCPSocket(1025, 10);
    launch();
}

void RAR::TestServer::handler()
{
    std::cout << buffer << std::endl;
}

void RAR::TestServer::launch()
{

    char *hello = "Hello from server";
    while (true)
    {
        std::cout << "============ WAITING ============" << std::endl;
        std::cout << tcp_socket->receive_request() << std::endl;
        handler();
        tcp_socket->send_response(hello);
        std::cout
            << "=========== DONE =============" << std::endl;
    }
}
