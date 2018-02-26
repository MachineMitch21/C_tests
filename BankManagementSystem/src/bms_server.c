#include <bms/bms_server.h>

struct Server_s {
    #ifdef _WIN32
        SOCKET              socket;
        struct addrinfo*    result;
        struct addrinfo     hints;
    #endif // _WIN32
};

struct Client_s {
    #ifdef _WIN32
        SOCKET socket;
    #endif // _WIN32
};

Server* server_init(const char* ip, const char* port, int* status)
{
    // Allocate space for Server regardless of OS
    Server* server = (Server*) malloc(sizeof(Server));

    #ifdef _WIN32
        server->socket = INVALID_SOCKET;
        server->result = NULL;

        WSADATA wsaData;
        int iResult = 0;

        *status = WSAStartup(MAKEWORD(2, 2), &wsaData);

        printf("%d\n", *status);

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

        printf("%d\n", *status);

        if (*status != 0)
        {
            free(server);
            WSACleanup();
            return NULL;
        }

        server->socket = socket(server->result->ai_family, server->result->ai_socktype, server->result->ai_protocol);

        if (server->socket == INVALID_SOCKET)
        {
            *status = WSAGetLastError();
            printf("%d \n", *status);
            freeaddrinfo(server->result);
            free(server);
            WSACleanup();
            return NULL;
        }

        *status = bind(server->socket, server->result->ai_addr, (int)server->result->ai_addrlen);

        printf("%d\n", *status);

        if (*status == SOCKET_ERROR)
        {
            *status = WSAGetLastError();
            freeaddrinfo(server->result);
            closesocket(server->socket);
            free(server);
            WSACleanup();
            return NULL;
        }

        freeaddrinfo(server->result);

        *status = listen(server->socket, SOMAXCONN);

        printf("%d\n", *status);

        if (*status == SOCKET_ERROR)
        {
            *status = WSAGetLastError();
            closesocket(server->socket);
            free(server);
            return NULL;
        }

        *status = 0;

        return server;

    #endif // _WIN32
}

Client* server_acceptConn(Server* server, int* status)
{
    printf("\n\nWaiting for a client to connect..\n\n");

    Client* client = (Client*) malloc(sizeof(Client));

    #ifdef _WIN32

        client->socket = accept(server->socket, NULL, NULL);

        if (client->socket == INVALID_SOCKET)
        {
            *status = WSAGetLastError();
            closesocket(client->socket);
            free(client);
            WSACleanup();
            return NULL;
        }

    #endif // _WIN32

    status = 0;

    return client;
}

void server_receive(Client* client, NetData* netData, int* status)
{
    #ifdef _WIN32

        int recResult;
        int sendResult;
        recResult = recv(client->socket, netData->data, DEFAULT_BUFFER_SIZE, 0);
        netData->size = recResult;

        if (recResult > 0)
        {
            printf("Bytes received: %d\n", recResult);

            char* sendBuf = "Message recieved";

            sendResult = send(client->socket, sendBuf, strlen(sendBuf), 0);

            if (sendResult == SOCKET_ERROR)
            {
                *status = WSAGetLastError();
                closesocket(client->socket);
                WSACleanup();
            }
            printf("Bytes sent: %d\n", sendResult);
        }
        else if (recResult == 0)
        {
            printf("Closing connection..\n");
        }
        else
        {
            *status = WSAGetLastError();
            closesocket(client->socket);
            WSACleanup();
        }

        *status = 0;

        closesocket(client->socket);

    #endif // _WIN32

    free(client);
}

void server_cleanup(Server* server, int* status)
{
    #ifdef _WIN32

        closesocket(server->socket);
        WSACleanup();

    #endif // _WIN32

    free(server);
    *status = 0;
}
