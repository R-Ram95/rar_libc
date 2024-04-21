#include "HTTPServer.hpp"

const std::string ROOT_PATH = "serve";
const std::string DEFAULT_ROOT_OBJECT = "index.html";

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

  std::string requestString(buffer, bytes_read);

  // read is successful, make request
  request = new RAR::Request(requestString);
}

void RAR::HTTPServer::handle_request()
{

  // Log Request - TODO Add Logging method in server
  std::cout << "Logging Request ..." << std::endl;
  std::cout << request->get_request() << std::endl;

  response = new Response();

  // Only GET is supported strcmp returns 0 (falsy) if strings are equal
  if (request->get_request_method() != "GET")
  {
    response->set_status_code(405);
    response->set_status_message("Method Not Allowed");
    return;
  }

  // file path
  std::string file_path = ROOT_PATH;
  std::string requested_object = DEFAULT_ROOT_OBJECT;

  if (request->get_request_uri() == "/")
  {
    requested_object = "/" + DEFAULT_ROOT_OBJECT;
  }

  std::cout << "FILE PATH" << std::endl;
  std::cout << file_path + requested_object << std::endl;

  // open file
  std::ifstream file(ROOT_PATH + requested_object);

  // could not find file
  if (!file.is_open())
  {
    // TODO add 404 and not found
    std::cout << "COULD NOT FIND FILE" << std::endl;
    return;
  }

  response->set_status_code(200);
  response->set_status_message("OK");

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
