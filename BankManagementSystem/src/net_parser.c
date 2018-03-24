
// We need to query the DEFAULT_BUFFER_SIZE located in bms_server.h
#include <bms/bms_server.h>
#include <bms/net_parser.h>

#define ACTIONID_SIZE           1
#define ACTIONSTR_SIZE          (DEFAULT_BUFFER_SIZE - ACTIONID_SIZE)

#define MAX_IDS 14

// MACROS defining actionID's
#define CUSTOMER_LOGIN          0
#define CREATE_CUSTOMER         1
#define MODIFY_CUSTOMER         2
#define DELETE_CUSTOMER         3
#define CREATE_ACCOUNT          4
#define MODIFY_ACCOUNT          5
#define DELETE_ACCOUNT          6
#define CUSTOMER_CREATE_PROFILE 7
#define CUSTOMER_MODIFY_PROFILE 8
#define CUSTOMER_DELETE_PROFILE 9
#define ACCOUNT_TRANSFER        10
#define GET_CUSTOMER            11
#define GET_ACCOUNT_LIST        12
#define GET_ACCOUNT             13

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

struct _ActionIDManager {
    Map* _actionIDMap;
    Map* _functionMap;
};

typedef struct {
    void (*net_func)(List*, ErrorStruct*);
} NetFunc;

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
    if (list_size(actionStrsList) != 2)
    {
        err_struct->sql_stat         = 0;
        err_struct->action_result    = INVALID_ACTION_STR;
    }
    else
    {
        Node* uNameNode = list_get_element(actionStrsList, 0);
        char* uName     = (char*) node_data(uNameNode);

        Node* pWordNode = list_get_element(actionStrsList, 1);
        char* pWord     = (char*) node_data(pWordNode);

        err_struct->action_result = db_verify_login(uName, pWord, &err_struct->sql_stat);
    }
}

void net_create_customer(List* actionStrsList, ErrorStruct* err_struct)
{
    int size = list_size(actionStrsList);

    char** cols_vals = convert_action_strs_list(actionStrsList);

    err_struct->action_result = 0;
    db_create_customer(cols_vals, size, &err_struct->sql_stat);
}

void net_modify_customer(List* actionStrsList, ErrorStruct* err_struct)
{
    Node* node = list_get_element(actionStrsList, 0);

    int uName_len   = strlen((char*) node_data(node));
    char* uName     = malloc(sizeof(char) * uName_len + 1);

    if (node != NULL)
    {
        strcpy(uName, (char*) node_data(node));
        list_remove_n(actionStrsList, node);
    }

    int size = list_size(actionStrsList);

    char** cols_vals = convert_action_strs_list(actionStrsList);

    err_struct->action_result = 0;
    db_modify_customer(56, cols_vals, size, &err_struct->sql_stat);

    free(uName);
}

void net_delete_customer(List* actionStrsList, ErrorStruct* err_struct)
{
    Node* node = list_get_element(actionStrsList, 0);

    char* id_str = malloc(sizeof(char) * strlen((char*) node_data(node)));

    if (node != NULL)
    {
        strcpy(id_str, (char*) node_data(node));
    }

    err_struct->action_result = 0;
    db_delete_customer(strtol(id_str, NULL, 10), err_struct->sql_stat);

    free(id_str);
}

void net_create_account(List* actionStrsList, ErrorStruct* err_struct)
{

}

void net_modify_account(List* actionStrsList, ErrorStruct* err_struct)
{

}

void net_delete_account(List* actionStrsList, ErrorStruct* err_struct)
{

}

void net_create_profile(List* actionStrsList, ErrorStruct* err_struct)
{

}

void net_modify_profile(List* actionStrsList, ErrorStruct* err_struct)
{

}

void net_delete_profile(List* actionStrsList, ErrorStruct* err_struct)
{

}

void net_account_transfer(List* actionStrsList, ErrorStruct* err_struct)
{

}

int keyequ(void* first_arg, void* second_arg)
{
    int* first  =   (int*) first_arg;
    int* second =   (int*) second_arg;

    return (*first - *second);
}

ActionIDManager* actionIDManager_construct()
{
    ActionIDManager* actionIDManager    = malloc(sizeof(ActionIDManager));
    actionIDManager->_actionIDMap       = map_new(&keyequ);
    actionIDManager->_functionMap       = map_new(&keyequ);

    int i;
    for (i = 0; i < MAX_IDS; i++)
    {
        map_push_back(actionIDManager->_actionIDMap, &i, &i);
    }

    int result = 0;

    NetFunc netFunc1 = {net_login};
    int customer_login = CUSTOMER_LOGIN;
    map_push_back(actionIDManager->_functionMap, map_get_value(actionIDManager->_actionIDMap, &customer_login, &result)           , &netFunc1);

    NetFunc netFunc2 = {net_create_customer};
    int create_customer = CREATE_CUSTOMER;
    map_push_back(actionIDManager->_functionMap, map_get_value(actionIDManager->_actionIDMap, &create_customer, &result)          , &netFunc2);

    NetFunc netFunc3 = {net_modify_customer};
    int modify_customer = MODIFY_CUSTOMER;
    map_push_back(actionIDManager->_functionMap, map_get_value(actionIDManager->_actionIDMap, &modify_customer, &result)          , &netFunc3);

    NetFunc netFunc4 = {net_delete_customer};
    int delete_customer = DELETE_CUSTOMER;
    map_push_back(actionIDManager->_functionMap, map_get_value(actionIDManager->_actionIDMap, &delete_customer, &result)          , &netFunc4);

    NetFunc netFunc5 = {net_create_account};
    int create_account = CREATE_ACCOUNT;
    map_push_back(actionIDManager->_functionMap, map_get_value(actionIDManager->_actionIDMap, &create_account, &result)           , &netFunc5);

    NetFunc netFunc6 = {net_modify_account};
    int modify_account = MODIFY_ACCOUNT;
    map_push_back(actionIDManager->_functionMap, map_get_value(actionIDManager->_actionIDMap, &modify_account, &result)           , &netFunc6);

    NetFunc netFunc7 = {net_delete_account};
    int delete_account = DELETE_ACCOUNT;
    map_push_back(actionIDManager->_functionMap, map_get_value(actionIDManager->_actionIDMap, &delete_account, &result)           , &netFunc7);

    NetFunc netFunc8 = {net_create_profile};
    int customer_create_profile = CUSTOMER_CREATE_PROFILE;
    map_push_back(actionIDManager->_functionMap, map_get_value(actionIDManager->_actionIDMap, &customer_create_profile, &result)  , &netFunc8);

    NetFunc netFunc9 = {net_modify_profile};
    int customer_modify_profile = CUSTOMER_MODIFY_PROFILE;
    map_push_back(actionIDManager->_functionMap, map_get_value(actionIDManager->_actionIDMap, &customer_modify_profile, &result)  , &netFunc9);

    NetFunc netFunc10 = {net_delete_profile};
    int customer_delete_profile = CUSTOMER_DELETE_PROFILE;
    map_push_back(actionIDManager->_functionMap, map_get_value(actionIDManager->_actionIDMap, &customer_delete_profile, &result)  , &netFunc10);

    NetFunc netFunc11 = {net_account_transfer};
    int account_transfer = ACCOUNT_TRANSFER;
    map_push_back(actionIDManager->_functionMap, map_get_value(actionIDManager->_actionIDMap, &account_transfer, &result)         , &netFunc11);

    return actionIDManager;
}

void actionIDManager_free(ActionIDManager* actionIDManager)
{
    map_free(actionIDManager->_actionIDMap);
    map_free(actionIDManager->_functionMap);
    free(actionIDManager);
}

ErrorStruct pass_net_msg_to_db(NetMessage* net_msg, ActionIDManager* actionIDManager)
{
    assert(net_msg != NULL && actionIDManager != NULL);

    ErrorStruct err_struct;

    int result = 0;

    print_netMsg(net_msg);

    int current_id = *(int*) map_get_value(actionIDManager->_actionIDMap, &net_msg->_actionID, &result);

    printf("Current ID is: %d\n", current_id);

    printf("Function map has {%d} elements\n", map_size(actionIDManager->_functionMap));

    NetFunc* netFunc = (NetFunc*) map_get_value(actionIDManager->_functionMap, &current_id, &result);

    printf("Getting ready to call net_func\n");
    netFunc->net_func(net_msg->_actionStrsList, &err_struct);

    return err_struct;
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
