
#ifdef _WIN32
#define CONTAINER_API __declspec(dllexport)
#else
#define CONTAINER_API __declspec(dllexport)
#endif

#ifdef __unix__
#define CONTAINER_API
#endif

#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#endif

#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdio.h>

typedef int bool;
#define true 1
#define false 0

#define LIST_OKAY           0
#define INDEX_OUT_OF_RANGE -1
#define INVALID_POP        -2
#define EMPTY_LIST_ERROR   -3
#define NO_ELEMENT_FOUND   -4

typedef struct Node_s Node;
typedef struct List_s List;

typedef struct DummyStruct {
    double      test_double;
    int         test_int;
    const char* test_str;
} DummyStruct;


BOOL WINAPI DllMain(
    HINSTANCE hinstDLL,  // handle to DLL module
    DWORD fdwReason,     // reason for calling function
    LPVOID lpReserved )  // reserved
{
    // Perform actions based on the reason for calling.
    switch( fdwReason )
    {
        case DLL_PROCESS_ATTACH:
         // Initialize once for each new process.
         // Return FALSE to fail DLL load.
            break;

        case DLL_THREAD_ATTACH:
         // Do thread-specific initialization.
            break;

        case DLL_THREAD_DETACH:
         // Do thread-specific cleanup.
            break;

        case DLL_PROCESS_DETACH:
         // Perform any necessary cleanup.
            break;
    }
    return TRUE;  // Successful DLL_PROCESS_ATTACH.
}


// ------------------------------------
// List functions
CONTAINER_API List* list_new();

CONTAINER_API int list_last_error(List* list);

CONTAINER_API int list_size(List* list);

CONTAINER_API Node* list_get_element(List* list, int index);

CONTAINER_API bool list_push(List* list, Node* node);

CONTAINER_API void list_pop(List* list);

CONTAINER_API Node* list_peek(List* list);

CONTAINER_API void list_push_back(List* list, Node* node);

CONTAINER_API void list_pop_back(List* list);

CONTAINER_API Node* list_peek_back(List* list);

CONTAINER_API void list_clear(List* list);

CONTAINER_API bool list_is_empty(List* list);

CONTAINER_API void list_insert(List* list, Node* node, int index);

CONTAINER_API bool list_remove_i(List* list, int index);

CONTAINER_API bool list_remove_n(List* list, Node* node);

CONTAINER_API void free_list(List* list);

// ------------------------------------
// Node functions
// No free_node function is provided, as nodes are freed along with the list They
// belong to
CONTAINER_API Node* node_new(void* data, size_t size);

CONTAINER_API void* node_data(Node* node);

CONTAINER_API void node_set_data_free(Node* node, void (*data_free)(void*));
