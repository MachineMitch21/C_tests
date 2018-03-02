
#ifndef __BMS_SERVER_H__
#define __BMS_SERVER_H__

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <memory.h>

#ifdef _WIN32
#include <winsock2.h>
#include <ws2tcpip.h>
#include <windows.h>
#pragma comment (lib, "ws2_32.lib")
#endif // _WIN32

#ifdef __unix__
#include <sys/socket.h>
#include <resolv.h>
#include <arpa/inet.h>
#endif // __unix__

#define DEFAULT_BUFFER_SIZE 16384
#define DEFAULT_IP          "127.0.0.1"
#define DEFAULT_PORT        "27015"

typedef struct {
    char    data[DEFAULT_BUFFER_SIZE];
    size_t  size;
} NetData;

// Opaque pointers to the internal structs
typedef struct Server_s Server;
typedef struct Client_s Client;  // The struct that will hold the accepted client connection socket

Server* server_init(const char* ip, const char* port, int* status);
Client* server_acceptConn(Server* server, int* status);
void    server_receive(Client* client, NetData* netData, int* status);
void    server_send(Client* client, char* msg, int* status);
void    server_cleanup(Server* server, int* status);
void    server_cleanup_c(Client* client);

#endif // __BMS_SERVER_H__
