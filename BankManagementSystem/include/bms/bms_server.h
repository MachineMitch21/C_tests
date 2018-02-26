#include <stdio.h>
#include <errno.h>
#include <memory.h>

#ifdef _WIN32
#include <winsock2.h>
#include <windows.h>
#pragma comment (lib, "ws2_32.lib")
#endif // _WIN32

#ifdef __unix__
#include <sys/socket.h>
#include <resolv.h>
#include <arpa/inet.h>
#endif // __unix__

#define DEFAULT_BUFFER_SIZE 1024
#define DEFAULT_PORT        "27015"

typedef unsigned short serv_stat;
#define SOCKET_OK               0x0000
#define SOCKET_ADDR_INFO_ERR    0x0001
#define SOCKET_CREATION_ERR     0x0002
#define SOCKET_BIND_ERR         0x0003
#define SERVER_LISTEN_ERR       0x0004
#define SERVER_ACCEPT_CON_ERR   0x0005
#define SERVER_SEND_ERR         0x0006
#define SERVER_RECV_ERR         0x0007
#define SERVER_SHUTDOWN_ERR     0x0008

// Opaque pointers to the internal structs
typedef struct Server_s Server;
typedef struct Client_s Client;  // The struct that will hold the accepted client connection socket

Server* server_init(const char* ip, const char* port, serv_stat* status);
Client* server_listen(Server* server, serv_stat* status);
char*   server_receive(Server* server, Client* client, serv_stat* status);
void    server_cleanup(Server* server, Client* client, serv_stat* status);
