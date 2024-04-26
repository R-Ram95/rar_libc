#ifndef SimpleSocket_hpp
#define SimpleSocket_hpp

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>

namespace RAR
{
   /**
    * @brief A thin wrapper around the socket from sys/socket.h
    *
    */
   class SimpleSocket
   {
   private:
      // the transport address of the socket - see netinet/in.h for options
      struct sockaddr_in address;

      // the socket to create
      int sock;

   public:
      /* CONSTRUCTORS */
      /**
       * @brief Construct a new Simple Socket object which defines a socket and address
       *
       * @param domain - communication domain in which socket should be created, see sys/socket.h for more details
       * @param service - type of socket to be created, see sys/socket.h for more detals
       * @param protocol  - protocol to be used with the docket
       */
      SimpleSocket(int domain, int service, int protocol);

      /* VIRTUAL FUNCTIONS */
      /**
       * @brief - Assign a transport address to the socket and connects the socket to the address
       *
       * @param domain - communication domain in which socket should be created, see sys/socket.h for more details
       * @param port  - transport address to be used for defining the address family when the socket is named and used in binding, connecting, or listening
       * @param interface - the address of the socket, i.e. the ip of the hosts networking device
       */
      virtual void assign_address(int domain, int port, u_long interface) = 0;

      /* TESTERS */
      // This function ends the program if the connection is not properly established.
      void test_connection(int);

      /* GETTERS */
      struct sockaddr_in get_address();
      int get_sock();

      /* SETTERS */
      void set_address(struct sockaddr_in addr);
   };
}

#endif /* SimpleSocket_hpp */