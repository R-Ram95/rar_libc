#include "Response.hpp"
#include <iostream>
#include <string>

RAR::Response::Response() {
  content_type = "";
  content_length = 0;
}

/** GETTERS */
// Construct string of response
std::string RAR::Response::get_response_string() {

  std::string response = "HTTP/1.1 ";
  response.append(std::to_string(status_code));
  response.append(" ");
  response.append(status_message);
  response.append("\n");
  return response.c_str();
}

/** SETTERS */

void RAR::Response::set_status_code(int code) { status_code = code; }

void RAR::Response::set_status_message(char *message) {
  status_message = message;
}

void RAR::Response::set_content_type(char *type) { content_type = type; }

void RAR::Response::set_content_length(int length) { content_length = length; }
