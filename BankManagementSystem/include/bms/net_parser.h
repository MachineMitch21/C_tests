
#ifndef __NET_PARSER_H__
#define __NET_PARSER_H__

#define _CRT_SECURE_NO_WARNINGS

#define INVALID_ACTION_STR  -1
#define INVALID_SQL         -2
#define INVALID_LOGIN       -3

typedef struct {
    int sql_stat;
    int action_result;
} ErrorStruct;

#include <string.h>
#include <stdlib.h>
#include <bms/list.h>
#include <bms/database_manager.h>

typedef struct _NetMessage NetMessage;

char**      convert_action_strs_list(List* actionStrsList);

ErrorStruct pass_net_msg_to_db(NetMessage* net_msg);

NetMessage* parse_netMsg(char* msg);
void        cleanup_netMessage(NetMessage* net_message);

void        print_netMsg(NetMessage* net_msg);

List*       parse_actionStr(char* actionStr);

#endif // __NET_PARSER_H__
