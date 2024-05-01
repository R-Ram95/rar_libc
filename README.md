# RARLIBC

A custom C++ library. Build target includes an archive file (`librarlibc.a`)

## Networking

** Communication **

- definition and implementation of simple http Request and Response objects

** Sockets **

- definition and implementation of server TCPSocket using `sys/socket.h` system calls
- FUTURE PLAN: add client side sockets and UDPSocket

** Logging **

- TODO

## CMAKE

- builds an executeable that can be used to test custom communication and socket objects in an HTTP_SERVER
- builds an archive file, `librarlibc.a`
