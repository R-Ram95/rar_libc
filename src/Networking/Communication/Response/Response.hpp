// Minimum requirments:
// Response Line -  HTTP VERSION STATUS CODE STATUS MESSAGE
// Content-Type - e.g. text/plain
// Content-Length - number of bytes to send

// body -
#include <sstream>
#include <string>

#ifndef RESPONSE_HPP
#define RESPONSE_HPP

namespace RAR
{
  class Response
  {
  private:
    int status_code;
    std::string status_message;
    std::string content_type;
    int content_length;
    std::ostringstream body;

  public:
    Response();

    /** GETTERS */
    std::string get_response();
    int get_response_length();

    /** SETTERS */
    void set_status_code(int);
    void set_status_message(std::string);
    void set_content_type(std::string);
    void update_content_length(int);
    void add_to_body(std::string);
  };
}; // namespace RAR

#endif /* response_hpp*/
