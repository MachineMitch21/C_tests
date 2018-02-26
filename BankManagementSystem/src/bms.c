
#include <stdio.h>
#include <stdlib.h>
#include <bms/bms_server.h>

int main(int argc, char** argv)
{
    int status;

    Server* server = server_init(DEFAULT_IP, DEFAULT_PORT, &status);

    if (server != NULL)
    {
        while (1)
        {
            Client* client = server_acceptConn(server, &status);

            NetData net_data;

            server_receive(client, &net_data, &status);

            if (net_data.size < DEFAULT_BUFFER_SIZE)
                memset(&net_data.data[net_data.size], '\0', 1);

            printf("%s\n", net_data.data);
        }

        server_cleanup(server, &status);
    }
    else
    {
        exit(-1);
    }
    return 0;
}
