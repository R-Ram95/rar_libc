compile:
	g++ src/Networking/Servers/TestServer.cpp src/Networking/Servers/SimpleServer.cpp src/Networking/Sockets/SimpleSocket.cpp src/Networking/Sockets/BindingSocket.cpp src/Networking/Sockets/ListeningSocket.cpp src/Networking/Servers/test.cpp -o test.exe 

run:
	chmod +x test.exe && sudo ./test.exe