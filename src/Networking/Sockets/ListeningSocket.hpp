#ifndef ListeningSocket_hpp
#define ListeningSocket_hpp

#include <stdio.h>

#include "BindingSocket.hpp"

namespace RAR
{
    class ListeningSocket : public BindingSocket
    {
    private:
        // Number of connections to que.
        int backlog;
        // This is 0 if the socket is successfully listening and -1 if failed.
        int listening;

    public:
        /* CONSTRUCTORS */
        ListeningSocket(int domain, int service, int protocol, int port, u_long interface, int bklg);

        /* FUNCTIONS */
        // This function starts listening on a socket that is created by the parent.
        void start_listening();
    };
};

#endif /* ListeningSocket_hpp */