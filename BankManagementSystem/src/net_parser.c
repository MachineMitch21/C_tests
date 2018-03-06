
// We need to query the DEFAULT_BUFFER_SIZE located in bms_server.h
#include <bms/bms_server.h>
#include <bms/net_parser.h>

#define ACTIONID_SIZE           1
#define ACTIONSTR_SIZE          (DEFAULT_BUFFER_SIZE - ACTIONID_SIZE)

// MACROS defining actionID's
#define CUSTOMER_LOGIN          0
#define CREATE_CUSTOMER         1
#define ALTER_CUSTOMER          2
#define DELETE_CUSTOMER         3
#define CREATE_ACCOUNT          4
#define ALTER_ACCOUNT           5
#define DELETE_ACCOUNT          6
#define CUSTOMER_CREATE_PROFILE 7
#define CUSTOMER_DELETE_PROFILE 8
#define ACCOUNT_TRANSFER        9
#define GET_CUSTOMER            10
#define GET_ACCOUNT_LIST        11
#define GET_ACCOUNT             12

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
    int         _actionID;

    // Will hold the individual action strings
    List*       _actionStrsList;
};

void str_replace_c(char* str, char toReplace, char replacer)
{
    size_t len = strlen(str);

    int i;
    for (i = 0; i < len; i++)
    {
        if (str[i] == toReplace)
        {
            memset(&str[i], replacer, 1);
        }
    }
}

char** convert_action_strs_list(List* actionStrsList)
{
    int size = list_size(actionStrsList);

    char** cols_vals = (char**) malloc(sizeof(char*) * size);

    int i;
    for (i = 0; i < size; i++)
    {
        Node* node = list_get_element(actionStrsList, i);
        char* cur_str = (char*) node_data(node);

        str_replace_c(cur_str, '_', ' ');

        cols_vals[i] = cur_str;
    }

    return cols_vals;
}

void net_login(List* actionStrsList, ErrorStruct* err_struct)
{
    Node* uNameNode = list_get_element(actionStrsList, 0);
    char* uName     = (char*) node_data(uNameNode);

    Node* pWordNode = list_get_element(actionStrsList, 1);
    char* pWord     = (char*) node_data(pWordNode);

    err_struct->action_result = db_verify_login(uName, pWord, &err_struct->sql_stat);

    return err_struct;
}

void net_create_customer(List* actionStrsList, ErrorStruct* err_struct)
{
    int size = list_size(actionStrsList);

    char** cols_vals = convert_action_strs_list(actionStrsList);

    err_struct->action_result = 0;
    db_create_customer(cols_vals, size, &err_struct->sql_stat);
}

void net_alter_customer(List* actionStrsList, ErrorStruct* err_struct)
{
    int size = list_size(actionStrsList);
}

ErrorStruct pass_net_msg_to_db(NetMessage* net_msg)
{
    assert(net_msg != NULL);

    int actionID            = net_msg->_actionID;
    List* actionStrsList    = net_msg->_actionStrsList;

    ErrorStruct err_struct;

    if (actionID == CUSTOMER_LOGIN)
    {
        if (list_size(actionStrsList) != 2)
        {
            err_struct.sql_stat         = 0;
            err_struct.action_result    = INVALID_ACTION_STR;
            return err_struct;
        }
        else
        {
            net_login(actionStrsList, &err_struct);
            return err_struct;
        }
    }
    else if (actionID == CREATE_CUSTOMER)
    {
        net_create_customer(actionStrsList, &err_struct);
        return err_struct;
    }
}

NetMessage* parse_netMsg(char* msg)
{
    /*  TODO
        Error check the msg string to make sure it is formatted correctly
    */

    NetMessage* net_msg = (NetMessage*) malloc(sizeof(NetMessage));

    char* actionID      = (char*) malloc(sizeof(char) * (ACTIONID_SIZE));
    char* actionStr     = (char*) malloc(sizeof(char) * (ACTIONSTR_SIZE));

    net_msg->_actionStrsList = list_new();

    // Make sure we've emptied the contents of the memory here
    memset(actionID,  0, ACTIONID_SIZE );
    memset(actionStr, 0, ACTIONSTR_SIZE);

    // Get the ActionID from the message
    actionID            = strtok(msg, ACTIONID_DELIMETER);

    net_msg->_actionID  = (int) strtol(actionID, NULL, 10);

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
    printf("ActionID   : %d\n", net_msg->_actionID);

    int i;
    for (i = 0; i < list_size(net_msg->_actionStrsList); i++)
    {
        Node* node = list_get_element(net_msg->_actionStrsList, i);
        printf("ActionStr %d: %s\n", i, (char*)node_data(node));
    }
}

void cleanup_netMessage(NetMessage* net_msg)
{
    free_list(net_msg->_actionStrsList);

    net_msg = NULL;
    free(net_msg);
}
