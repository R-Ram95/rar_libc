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
    int m_status_code;
    std::string m_status_message;
    std::string m_content_type;
    int m_content_length;
    std::ostringstream m_body;

  public:
    /**
     * @brief Construct a new Response object - initialized the Content-Type and Content-Length
     *
     */
    Response();

    /**
     * @brief updates the length (in bytes) of the body - this is used by the browser to
     * determines how many bytes the download
     *
     */
    void update_content_length(int);
    /**
     * @brief add line to file body
     *
     */
    void add_to_body(std::string);

    /** GETTERS */
    std::string get_response();
    int get_response_length();

    /** SETTERS */
    void set_response_status(int status_code, const std::string &status_message);
    void set_content_type(std::string);
  };
}; // namespace RAR

#endif /* response_hpp*/
