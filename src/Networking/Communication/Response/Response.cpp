#include "Response.hpp"

RAR::Response::Response()
{
  content_type = "";
  content_length = 0;
}

/** GETTERS */
// Construct string of response
std::string RAR::Response::get_response()
{
  std::ostringstream response;
  response << "HTTP/1.1 " << status_code << " " << status_message << std::endl;
  response << "Content-Type: " << content_type << std::endl;
  response << "Content-Length: " << content_length << std::endl;
  response << std::endl;
  response << body.str() << std::endl;

  return response.str();
}

int RAR::Response::get_response_length()
{
  return get_response().length();
}

/** SETTERS */

void RAR::Response::set_status_code(int code) { status_code = code; }

void RAR::Response::set_status_message(std::string message)
{
  status_message = message;
}

void RAR::Response::set_content_type(std::string type) { content_type = type; }

void RAR::Response::update_content_length(int bytes) { content_length += bytes; }

void RAR::Response::add_to_body(std::string line)
{
  body << line;
}
