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
      // the address of the socket - see netinet/in.h for options
      struct sockaddr_in address;
      //
      int sock;

   public:
      /* CONSTRUCTORS */
      /**
       * @brief Construct a new Simple Socket object which defines a socket and address
       *
       * @param domain - communication domain in which socket should be created, see sys/socket.h for more details
       * @param service - type of socket to be created, see sys/socket.h for more detals
       * @param protocol  - protocol to be used with the docket
       * @param port  - transport address to be used for defining the address family when the socket is named and used in binding, connecting, or listening
       * @param interface - the address of the socket, i.e. the ip of the hosts networking device
       */
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