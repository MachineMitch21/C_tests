
#include <stdio.h>
#include <stdlib.h>
#include <bms/bms_server.h>
#include <bms/database_manager.h>
#include <bms/net_parser.h>
#include <bms/map.h>

int main(int argc, char** argv)
{
    int status;

    int rc;

    ActionIDManager* actionIDManager = actionIDManager_construct();

    Server* server = server_init(DEFAULT_IP, DEFAULT_PORT, &status);

    if (server != NULL)
    {
        while (1)
        {
            Client* client = server_acceptConn(server, &status);

            NetData net_data;

            server_receive(client, &net_data, &status);
            NetMessage* net_msg = parse_netMsg(net_data.data);

            pass_net_msg_to_db(net_msg, actionIDManager);

            cleanup_netMessage(net_msg);

            server_send(client, "I got your message, bruh..", &status);

            if (client != NULL)
                server_cleanup_c(client);
        }

        server_cleanup(server, &status);
    }
    else
    {
        printf("\nThe server has failed to initialize, Error Code {%d}\n", status);
        exit(-1);
    }

    actionIDManager_free(actionIDManager);
    return 0;
}
