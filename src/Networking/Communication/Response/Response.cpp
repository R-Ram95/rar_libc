#include "Response.hpp"

RAR::Response::Response()
{
  m_content_type = "";
  m_content_length = 0;
}

/** GETTERS */
// Construct string of response
std::string RAR::Response::get_response()
{
  std::ostringstream response;
  response << "HTTP/1.1 " << m_status_code << " " << m_status_message << std::endl;
  response << "Content-Type: " << m_content_type << std::endl;
  response << "Content-Length: " << m_content_length << std::endl;
  response << std::endl;
  response << m_body.str() << std::endl;

  return response.str();
}

int RAR::Response::get_response_length()
{
  return get_response().length();
}

/** SETTERS */

void RAR::Response::set_response_status(int status_code, const std::string &status_message)
{
  m_status_code = status_code;
  m_status_message = status_message;
}

void RAR::Response::set_content_type(std::string type) { m_content_type = type; }

void RAR::Response::update_content_length(int bytes) { m_content_length += bytes; }

void RAR::Response::add_to_body(std::string line)
{
  m_body << line;
}
