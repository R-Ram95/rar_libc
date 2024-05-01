#include "HTTPServer.hpp"

const std::string ROOT_PATH = "serve";
const std::string DEFAULT_ROOT_OBJECT = "index.html";

RAR::HTTPServer::HTTPServer()
{
  tcp_socket = new TCPSocket(80);
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

  if (!is_method_supported(request->get_request_method()))
  {
    response->set_response_status(405, "Method Not Allowed");
    return;
  }

  std::string file_path = construct_file_path(request->get_request_uri());
  std::cout << file_path << std::endl;

  auto [content_type, file_extension] = get_mime_type_and_extension(file_path);

  if (add_file_to_body(file_path, file_extension))
  {
    response->set_response_status(200, "OK");
    response->set_content_type(content_type);
  }
  else
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

void RAR::HTTPServer::log_response()
{
  std::cout << "Logging response ..." << std::endl;
  std::cout << response->get_response() << std::endl;
}

std::tuple<std::string, std::string> RAR::HTTPServer::get_mime_type_and_extension(const std::string &file_name)
{

  std::string extension;
  std::string content_type;

  static std::array<std::string, 10> mime_types{".html", "text/html", ".js", "application/javascript", ".png", "image/png", ".jpeg", "image/jpeg", ".svg", "image/svg"};
  size_t dot_position = file_name.find_last_of('.');

  // didn't find dot => no extension
  if (std::string::npos == dot_position)
  {
    content_type = "text/plain";
    return {content_type, ""};
  }

  extension = file_name.substr(dot_position);

  for (int i = 0; i < mime_types.size() - 1; i++)
  {
    if (mime_types[i] == extension)
    {
      // mime type is next in the array
      content_type = mime_types[i + 1];
      return {content_type, extension};
    }
  }

  // did not find a valid mime type
  return {"text/plain", ""};
}

bool RAR::HTTPServer::add_file_to_body(const std::string &file_path, const std::string &file_extension)
{

  std::ifstream file;

  // check file type to see how we open it
  if (file_extension == ".html" || file_extension == ".js")
  {
    file.open(file_path);
  }
  else
  {
    file.open(file_path, std::ios::binary);
  }

  if (!file.is_open())
  {
    // TODO Log Error
    return false;
  }

  // read file contents into buffer
  std::vector<char> file_contents((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());

  response->add_to_body(std::string(file_contents.begin(), file_contents.end()));
  response->update_content_length(file_contents.size());

  file.close();
  return true;
}