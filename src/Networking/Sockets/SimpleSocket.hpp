#ifndef SimpleSocket_hpp
#define SimpleSocket_hpp

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>

namespace RAR
{
   class SimpleSocket
   {
   private:
      struct sockaddr_in address;
      int sock;

   public:
      /* CONSTRUCTORS */
      SimpleSocket(int domain, int service, int protocol, int port, u_long interface);

      /* VIRTUAL FUNCTIONS */
      // This function connects to the networking using bind(), connect(), or listen() from sys/socket.h
      virtual void connect_to_network(int sock, struct sockaddr_in address) = 0;

      /* TESTERS */
      // This function ends the program if the connection is not properly established.
      void test_connection(int);

      /* GETTERS */
      struct sockaddr_in get_address();
      int get_sock();
   };
}

#endif /* SimpleSocket_hpp */