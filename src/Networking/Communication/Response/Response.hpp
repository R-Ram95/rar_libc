#include <sstream>
#include <string>

#ifndef RESPONSE_HPP
#define RESPONSE_HPP

namespace RAR
{
  /**
   * @brief Used to construct a minimal (only what is required by the browser) HTTP response
   *
   */
  class Response
  {
  private:
    int status_code;
    std::string status_message;
    std::string content_type;
    int content_length;
    std::ostringstream body;

  public:
    /**
     * @brief Construct a new Response object - initialized the Content-Type and Content-Length
     *
     */
    Response();

    /** GETTERS */
    std::string get_response();
    int get_response_length();

    /** SETTERS */
    void set_status_code(int);
    void set_status_message(std::string);
    void set_content_type(std::string);
    /**
     * @brief updates the length (in bytes) of the body - this is used by the browser to
     * determines how many bytes the download
     *
     */
    void update_content_length(int);
    void add_to_body(std::string);
  };
}; // namespace RAR

#endif /* response_hpp*/
