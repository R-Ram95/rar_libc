
#ifndef HTTPServer_hpp
#define HTTPServer_hpp

#include <fstream>
#include <unordered_map>
#include <unistd.h>
#include <tuple>
#include "../../rarlibc-networking.hpp"

namespace RAR
{
    class HTTPServer
    {
    private:
        char buffer[30000] = {0};

        // Socket file descriptor
        int socket_fd;
        TCPSocket *tcp_socket;

        Request *request;
        Response *response;

        /**
         * @brief Accepts connection on the tcp port, and parses the request into
         * the request member variable.
         *
         */
        void read_request();

        /**
         * @brief Reviews request member variable and prepares output buffer and response
         * logs the request as well.
         */
        void handle_request();

        /**
         * @brief Sends the response and closes the socket.
         *
         */
        void send_response();

        /** HELPERS */
        /**
         * @brief prints request to console
         */
        void log_request();
        /**
         * @brief prints response to console
         *
         */
        void log_response();

        /**
         * @brief Get the mime type and extension of the given file
         *
         * @param file_name
         * @return std::tuple<std::string, std::string>
         */
        std::tuple<std::string, std::string> get_mime_type_and_extension(const std::string &file_name);

        /**
         * @brief handles request at default route ("/")
         *
         * @param file_name
         * @return std::string
         */
        std::string construct_file_path(const std::string &file_name);

        /**
         * @brief - checks if the given method is supported by the server
         *
         * @param method
         * @return true - if the method is GET
         */
        bool is_method_supported(const std::string &method);

        /**
         * @brief adds the files contents to body of response
         *
         * @param file_path - path to file
         * @param file_extension - extension of the file
         */
        bool add_file_to_body(const std::string &file_path, const std::string &file_extension);

    public:
        HTTPServer();
        void run();
    };
};
;

#endif /* HTTPServer_hpp */
