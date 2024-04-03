compile:
	g++ src/Networking/Sockets/SimpleSocket/SimpleSocket.cpp src/Networking/Sockets/ServerSocket/ServerSocket.cpp src/Networking/Sockets/TCPSocket/TCPSocket.cpp src/Networking/Servers/TestServer.cpp src/Networking/Servers/test.cpp  -o test.exe 

run:
	chmod +x test.exe && sudo ./test.exe