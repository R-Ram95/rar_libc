cmake_minimum_required(VERSION 3.29.1)

project(HTTP_SERVER)


add_executable(${PROJECT_NAME} "src/Networking/Servers/test.cpp" "src/Networking/Servers/HTTPServer/HTTPServer.cpp" "src/Networking/Sockets/ServerSocket/ServerSocket.cpp" "src/Networking/Sockets/SimpleSocket/SimpleSocket.cpp" "src/Networking/Sockets/TCPSocket/TCPSocket.cpp" "src/Networking/Communication/Request/Request.cpp" "src/Networking/Communication/Response/Response.cpp")