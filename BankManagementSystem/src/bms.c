
#include <stdio.h>
#include <stdlib.h>
#include <bms/bms_server.h>
#include <bms/database_manager.h>
#include <bms/net_parser.h>

int main(int argc, char** argv)
{
    int status;

    int rc;

    // char* cols_vals[] = {
    //     "Name", "'Matt'",
    //     "PhoneNumber", "'7651238745'",
    //     "Address", "'34 W Test St'"
    // };
    //
    // db_create_customer(cols_vals, 6, &rc);

    Server* server = server_init(DEFAULT_IP, DEFAULT_PORT, &status);

    if (server != NULL)
    {
        while (1)
        {
            Client* client = server_acceptConn(server, &status);

            NetData net_data;

            server_receive(client, &net_data, &status);

            printf("%s\n", net_data.data);
            NetMessage* net_msg = parse_netMsg(net_data.data);
            print_netMsg(net_msg);
            cleanup_netMessage(net_msg);
            server_send(client, "I got your message, bruh..", &status);

            if (client != NULL)
                server_cleanup_c(client);
        }

        server_cleanup(server, &status);
    }
    else
    {
        exit(-1);
    }
    return 0;
}
