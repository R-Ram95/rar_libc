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
  request = new RAR::Request(requestString);
}

void RAR::HTTPServer::handle_request()
{
  log_request();
  response = new Response();

  // Only GET is supported strcmp returns 0 (falsy) if strings are equal
  if (!is_method_supported(request->get_request_method()))
  {
    response->set_response_status(405, "Method Not Allowed");
    return;
  }

  std::string file_path = construct_file_path(request->get_request_uri());
  std::cout << file_path << std::endl;

  if (!serve_file(file_path))
  {
    response->set_response_status(404, "Not Found");
  }
}

void RAR::HTTPServer::send_response()
{
  int written = write(socket_fd, response->get_response().c_str(), response->get_response_length());
  close(socket_fd);
  log_response();
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

/** HELPERS */
void RAR::HTTPServer::log_request()
{

  std::cout << "Logging Request ..." << std::endl;
  std::cout << request->get_request() << std::endl;
}

void RAR::HTTPServer::log_response()
{
  std::cout << "Logging response ..." << std::endl;
  std::cout << response->get_response() << std::endl;
}

std::string RAR::HTTPServer::construct_file_path(const std::string &file_name)
{
  std::string file_path = ROOT_PATH;
  if (request->get_request_uri() == "/")
  {
    file_path += "/" + DEFAULT_ROOT_OBJECT;
  }
  else
  {
    file_path += request->get_request_uri();
  }
  return file_path;
}

bool RAR::HTTPServer::is_method_supported(const std::string &method)
{
  return method == "GET";
}

bool RAR::HTTPServer::serve_file(const std::string &file_path)
{
  std::ifstream file(file_path);
  // could not find file
  if (!file.is_open())
  {
    // TODO Log Error
    return false;
  }

  std::string line;
  while (std::getline(file, line))
  {
    response->add_to_body(line);
    response->update_content_length(line.length());
  }

  file.close();
  return true;
}