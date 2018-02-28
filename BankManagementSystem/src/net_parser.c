
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
    char*   _actionID;

    // The string containing the data which is to be sent to the database
    // Will still need to be parsed for each specific action type
    char*   _actionStr;
};

NetMessage* parse_netMsg(char* msg)
{
    NetMessage* net_msg = (NetMessage*) malloc(sizeof(NetMessage));

    net_msg->_actionID = (char*) malloc(sizeof(char) * (ACTIONID_SIZE));
    net_msg->_actionStr = (char*) malloc(sizeof(char) * (ACTIONSTR_SIZE));

    memset(net_msg->_actionID, 0, ACTIONID_SIZE);
    memset(net_msg->_actionStr, 0, ACTIONSTR_SIZE);

    net_msg->_actionID  = strtok(msg, ACTIONID_DELIMETER);
    net_msg->_actionStr = strtok(NULL, ACTIONSTR_DELIMETER);

    return net_msg;
}

void print_netMsg(NetMessage* net_msg)
{
    printf("ActionID: %s\n", net_msg->_actionID);
    printf("ActionStr: %s\n", net_msg->_actionStr);
}

void cleanup_netMessage(NetMessage* net_msg)
{
    net_msg->_actionID  = NULL;
    net_msg->_actionStr = NULL;

    free(net_msg->_actionID);
    free(net_msg->_actionStr);

    net_msg = NULL;
    free(net_msg);
}
