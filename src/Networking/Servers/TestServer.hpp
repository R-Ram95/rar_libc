
#ifndef TestServer_hpp
#define TestServer_hpp

#include "SimpleServer.hpp"
#include <cstring>
#include <unistd.h>

namespace RAR
{
    class TestServer : public SimpleServer
    {
    private:
        char buffer[30000] = {0};
        int new_socket;

        void accepter();
        void handler();
        void responder();

    public:
        TestServer();
        void launch();
    };
};
;

#endif /* TestServer_hpp */