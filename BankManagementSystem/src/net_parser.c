
// We need to query the DEFAULT_BUFFER_SIZE located in bms_server.h
#include <bms/bms_server.h>
#include <bms/net_parser.h>

#define ACTIONID_SIZE           1
#define ACTIONSTR_SIZE          (DEFAULT_BUFFER_SIZE - ACTIONID_SIZE)

// MACROS defining actionID's
#define CUSTOMER_LOGIN          "0"
#define CREATE_CUSTOMER         "1"
#define ALTER_CUSTOMER          "2"
#define DELETE_CUSTOMER         "3"
#define CREATE_ACCOUNT          "4"
#define ALTER_ACCOUNT           "5"
#define DELETE_ACCOUNT          "6"
#define CUSTOMER_CREATE_PROFILE "7"
#define CUSTOMER_DELETE_PROFILE "8"
#define ACCOUNT_TRANSFER        "9"
#define GET_CUSTOMER            "10"
#define GET_ACCOUNT_LIST        "11"
#define GET_ACCOUNT             "12"

// Seperates _actionID from _actionStr
#define ACTIONID_DELIMETER      ","

// Signifies the end of the _actionStr
#define ACTIONSTR_DELIMETER     "!"

// Seperates all of the different strings within
// the _actionStr
#define DATA_PIECE_DELIMETER    ":"

struct _NetMessage {
    // The identifier which will specifiy which action is to be taken
    // with the given action string (Will we be creating a customer?
    // Altering a table? Something else?)
    char*       _actionID;

    // Will hold the individual action strings
    List*       _actionStrsList;
};



NetMessage* parse_netMsg(char* msg)
{
    /*  TODO
        Error check the msg string to make sure it is formatted correctly
    */

    NetMessage* net_msg = (NetMessage*) malloc(sizeof(NetMessage));

    net_msg->_actionID  = (char*) malloc(sizeof(char) * (ACTIONID_SIZE));
    char* actionStr     = (char*) malloc(sizeof(char) * (ACTIONSTR_SIZE));

    net_msg->_actionStrsList = list_new();

    // Make sure we've emptied the contents of the memory here
    memset(net_msg->_actionID, 0, ACTIONID_SIZE);
    memset(actionStr, 0, ACTIONSTR_SIZE);

    // Get the ActionID from the message
    net_msg->_actionID  = strtok(msg, ACTIONID_DELIMETER);

    // Get the whole ActionStr from the message
    actionStr           = strtok(NULL, ACTIONSTR_DELIMETER);

    char* cur_actionStr_token = strtok(actionStr, DATA_PIECE_DELIMETER);

    while(cur_actionStr_token != NULL)
    {
        Node* node = node_new(cur_actionStr_token, strlen(cur_actionStr_token));
        list_push_back(net_msg->_actionStrsList, node);
        cur_actionStr_token = strtok(NULL, DATA_PIECE_DELIMETER);
    }

    return net_msg;
}

void print_netMsg(NetMessage* net_msg)
{
    printf("ActionID   : %s\n", net_msg->_actionID);

    int i;
    for (i = 0; i < list_size(net_msg->_actionStrsList); i++)
    {
        Node* node = list_get_element(net_msg->_actionStrsList, i);
        printf("ActionStr %d: %s\n", i, (char*)node_data(node));
    }
}

void cleanup_netMessage(NetMessage* net_msg)
{
    net_msg->_actionID = NULL;

    free(net_msg->_actionID);
    free_list(net_msg->_actionStrsList);

    net_msg = NULL;
    free(net_msg);
}
