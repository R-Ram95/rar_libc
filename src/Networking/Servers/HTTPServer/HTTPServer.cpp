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
  // accept connection and read data into buffer
  socket_fd = tcp_socket->accept_connection();
  int bytes_read = read(socket_fd, buffer, sizeof(buffer));

  // we have failed to read
  if (bytes_read < 0)
  {
    perror("Failed to read ...");
    exit(EXIT_FAILURE);
  }

  // read is successful, make request
  request = new RAR::Request(buffer);
}

void RAR::HTTPServer::handle_request()
{

  // Log Request - TODO Add Logging method in server
  std::cout << "Logging Request ..." << std::endl;
  std::cout << request->get_request() << std::endl;

  response = new Response();

  // Only GET is supported strcmp returns 0 (falsy) if strings are equal
  if (request->get_request() == "GET")
  {
    response->set_status_code(405);
    response->set_status_message("Method Not Allowed");
    return;
  }

  // file path
  // char *file_path = std::strcat(ROOT_PATH, request->get_request_uri());
  // std::cout << "FILE PATH" << std::endl;
  // std::cout << file_path << std::endl;

  // open file
  std::ifstream file("index.html");

  // could not find file
  if (!file.is_open())
  {
    // TODO add 404 and not found
    std::cout << "COULD NOT FIND FILE" << std::endl;
    return;
  }

  std::string line;
  // file exists and is open
  while (std::getline(file, line))
  {
    response->add_to_body(line);
    response->update_content_length(line.length());
  }
  file.close();
}

void RAR::HTTPServer::send_response()
{
  int written = write(socket_fd, response->get_response().c_str(), response->get_response_length());
  close(socket_fd);

  // Log Response
  std::cout << "Logging response ..." << std::endl;
  std::cout << response->get_response().c_str() << std::endl;
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
