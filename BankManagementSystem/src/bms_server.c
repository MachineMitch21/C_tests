#include <bms/bms_server.h>

struct Server_s {
    #ifdef _WIN32
        SOCKET              socket;
        struct addrinfo*    result;
        struct addrinfo     hints;
    #endif // _WIN32

    #ifdef __unix__
        int                 socket_fd;
        struct sockaddr_in  addr_info;
    #endif // __unix__
};

struct Client_s {
    #ifdef _WIN32
        SOCKET socket;
    #endif // _WIN32

    #ifdef __unix__
        int                 socket_fd;
        struct sockaddr_in  addr_info;
        int                 addr_len;
    #endif // __unix__
};

/*
 *  Take in a string of binary 1s and 0s and toggle each bit
 */
void flipBits(char* str)
{
    size_t len = strlen(str);

    int i;
    int j;
    for (i = 0; i < len; i++)
    {
        for (j = 0; j < 7; j++)
        {
            str[i] ^= (1 << j);
        }
    }
}

void decode_netMsg(char* msg)
{
    printf("\nNet Message encoded: %s\n\n", msg);
    flipBits(msg);
    printf("\nNet Message decoded: %s\n\n", msg);
}

Server* server_init(const char* ip, const char* port, int* status)
{
    // Allocate space for Server regardless of OS
    Server* server = (Server*) malloc(sizeof(Server));

    #ifdef __unix__

        if ( (server->socket_fd = socket(AF_INET, SOCK_STREAM, )) < 0)
        {
            fprintf(stderr, "Error creating socket\n")
            return NULL;
        }

        bzero(&server->addr_info, sizeof(server->addr_info));
        server->addr_info->sin_family       = AF_INET;
        server->addr_info->sin_port         = htons(DEFAULT_PORT);
        server->addr_info->sin_addr.s_addr  = INADDR_ANY;

        if ( bind(server->socket_fd, (struct sockaddr_in*)&server->addr_info, sizeof(server->addr_info)) != 0)
        {
            fprintf(stderr, "Error binding socket\n");
            return NULL;
        }

        if (listen(server->socket_fd, 20) != 0)
        {
            fprintf(stderr, "Error initializing %d as listening socket\n", server->socket_fd);
            return NULL;
        }

    #endif // __unix__

    #ifdef _WIN32
        server->socket = INVALID_SOCKET;
        server->result = NULL;

        WSADATA wsaData;
        int iResult = 0;

        *status = WSAStartup(MAKEWORD(2, 2), &wsaData);

        if (*status != 0)
        {
            free(server);
            return NULL;
        }

        memset(&server->hints, 0, sizeof(server->hints));
        server->hints.ai_family     = AF_INET;
        server->hints.ai_socktype   = SOCK_STREAM;
        server->hints.ai_protocol   = IPPROTO_TCP;
        server->hints.ai_flags      = AI_PASSIVE;

        *status = getaddrinfo(NULL, port, &server->hints, &server->result);

        if (*status != 0)
        {
            free(server);
            return NULL;
        }

        server->socket = socket(server->result->ai_family, server->result->ai_socktype, server->result->ai_protocol);

        if (server->socket == INVALID_SOCKET)
        {
            *status = WSAGetLastError();
            freeaddrinfo(server->result);
            free(server);
            return NULL;
        }

        *status = bind(server->socket, server->result->ai_addr, (int)server->result->ai_addrlen);

        if (*status == SOCKET_ERROR)
        {
            *status = WSAGetLastError();
            freeaddrinfo(server->result);
            closesocket(server->socket);
            free(server);
            return NULL;
        }

        freeaddrinfo(server->result);

        *status = listen(server->socket, SOMAXCONN);

        if (*status == SOCKET_ERROR)
        {
            *status = WSAGetLastError();
            int close_stat;
            return NULL;
        }

        *status = 0;


    #endif // _WIN32

    return server;
}

Client* server_acceptConn(Server* server, int* status)
{
    printf("Waiting for a client to connect..\n\n");

    Client* client = (Client*) malloc(sizeof(Client));


    if (client != NULL)
    {
        #ifdef __unix__

            client->addr_len = sizeof(client->addr_info);
            client->socket_fd = accept(client->socket_fd, (struct sockaddr*)&client->addr_info, client->addr_len)

            fprintf(stdout, "%s:%d connected\n", inet_ntoa(client->addr_info.sin_addr), ntohs(client->addr_info.sin_port));

        #endif // __unix__

        #ifdef _WIN32

            client->socket = accept(server->socket, NULL, NULL);

            if (client->socket == INVALID_SOCKET)
            {
                *status = WSAGetLastError();
                return NULL;
            }

        #endif // _WIN32

        status = 0;

    }
    else
    {
        fprintf(stderr, "Client memory could not be allocated..\n");
        return NULL;
    }

    return client;
}

void server_receive(Client* client, NetData* netData, int* status)
{
    // We need to make sure we don't have any garbage bytes in netData->data
    memset(netData->data, 0, DEFAULT_BUFFER_SIZE);
    int recResult;

    #ifdef __unix__

        recResult = recv(client->socket_fd, netData->data, DEFAULT_BUFFER_SIZE, 0);

        if (recResult > 0)
        {
            printf("Bytes received: %d\n", recResult);
            decode_netMsg(netData->data);
        }

    #endif // __unix__

    #ifdef _WIN32

        recResult = recv(client->socket, netData->data, DEFAULT_BUFFER_SIZE, 0);
        netData->size = recResult;

        if (recResult > 0)
        {
            printf("Bytes received: %d\n", recResult);
            decode_netMsg(netData->data);
        }
        if (recResult == 0)
        {
            printf("Closing connection..\n");
        }
        else
        {
            *status = WSAGetLastError();
            printf("Failed to receive bytes with status: %d\n", *status);
            return;
        }

    #endif // _WIN32

    *status = 0;
}

void server_send(Client* client, char* msg, int* status)
{

    #ifdef __unix__

        *status = send(client->socket_fd, msg, strlen(msg), 0);

    #endif

    #ifdef _WIN32

        *status = send(client->socket, msg, strlen(msg), 0);

        if (*status == SOCKET_ERROR)
        {
            *status = WSAGetLastError();
            printf("Failed to send bytes with status: %d\n", *status);
            return;
        }

    #endif // _WIN32

    printf("Bytes sent: %d\n", *status);
}

void server_cleanup(Server* server, int* status)
{

    #ifdef __unix__

        close(server->socket_fd);

    #endif // __unix__

    #ifdef _WIN32

        closesocket(server->socket);
        WSACleanup();

    #endif // _WIN32

    free(server);
    *status = 0;
}

void server_cleanup_c(Client* client)
{

    #ifdef __unix__

        close(client->socket_fd);

    #endif // __unix__

    #ifdef _WIN32

        closesocket(client->socket);

    #endif // _WIN32

    free(client);
}
