
#ifndef TestServer_hpp
#define TestServer_hpp

#include <cstring>
#include <unistd.h>
#include "../rarlibc-networking.hpp"

namespace RAR
{
    class TestServer
    {
    private:
        char buffer[30000] = {0};
        int new_socket;
        TCPSocket *tcp_socket;

        void handler();

    public:
        TestServer();
        void launch();
    };
};
;

#endif /* TestServer_hpp */