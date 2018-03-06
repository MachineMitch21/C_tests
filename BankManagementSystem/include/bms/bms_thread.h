#ifndef __BMS_THREAD_H__
#define __BMS_THREAD_H__

#include <bms_server.h>

#ifdef _WIN32
    #include <windows.h>
#endif // _WIN32

typedef struct BMSThread_s bms_thread;

bms_thread* bms_thread_init(Client* client);

#endif // __BMS_THREAD_H__
