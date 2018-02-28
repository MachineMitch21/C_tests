
#ifndef __NET_PARSER_H__
#define __NET_PARSER_H__

#include <string.h>
#include <stdlib.h>

typedef struct _NetMessage NetMessage;

NetMessage* parse_netMsg(char* msg);
void        cleanup_netMessage(NetMessage* net_message);

char**      parse_actionStr(char* actionStr);

#endif // __NET_PARSER_H__
