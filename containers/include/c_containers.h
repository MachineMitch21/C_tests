
#ifndef C_CONTAINERS_H
#define C_CONTAINERS_H

#ifdef _WIN32
    #ifdef CCONTAINERS_BUILD
        #define CCONTAINERS_API __declspec(dllexport)
    #else
        #define CCONTAINERS_API __declspec(dllimport)
    #endif // CCONTAINERS_BUILD
#endif // _WIN32

#ifdef __unix__
    #define CCONTAINERS_API
#endif // __unix__

#define CCONTAINERS_CALL _cdecl

#include "map.h"
#include "list.h"
#include "dynamic_array.h"

#endif // C_CONTAINERS_H
