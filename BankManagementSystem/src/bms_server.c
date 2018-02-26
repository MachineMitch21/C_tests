#include <bms/bms_server.h>

struct Server_s {
    SOCKET ListenSocket;
};

struct Client_s {
    SOCKET ClientSocket;
};
