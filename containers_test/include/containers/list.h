
#ifndef LIST_H
#define LIST_H

#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdio.h>

#include "c_containers.h"

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

#ifdef __cplusplus
#define extern "C"
{
#endif

	// ------------------------------------
	// List functions
	CCONTAINERS_API List* 	CCONTAINERS_CALL list_new();

	CCONTAINERS_API int 	CCONTAINERS_CALL list_last_error(List* list);

	CCONTAINERS_API int 	CCONTAINERS_CALL list_size(List* list);

	CCONTAINERS_API Node* 	CCONTAINERS_CALL list_get_element(List* list, int index);

	CCONTAINERS_API bool 	CCONTAINERS_CALL list_push(List* list, Node* node);

	CCONTAINERS_API void 	CCONTAINERS_CALL list_pop(List* list);

	CCONTAINERS_API Node* 	CCONTAINERS_CALL list_peek(List* list);

	CCONTAINERS_API void 	CCONTAINERS_CALL list_push_back(List* list, Node* node);

	CCONTAINERS_API void 	CCONTAINERS_CALL list_pop_back(List* list);

	CCONTAINERS_API Node* 	CCONTAINERS_CALL list_peek_back(List* list);

	CCONTAINERS_API void 	CCONTAINERS_CALL list_clear(List* list);

	CCONTAINERS_API bool 	CCONTAINERS_CALL list_is_empty(List* list);

	CCONTAINERS_API void 	CCONTAINERS_CALL list_insert(List* list, Node* node, int index);

	CCONTAINERS_API bool 	CCONTAINERS_CALL list_remove_i(List* list, int index);

	CCONTAINERS_API bool 	CCONTAINERS_CALL list_remove_n(List* list, Node* node);

	CCONTAINERS_API void 	CCONTAINERS_CALL free_list(List* list);

	// ------------------------------------
	// Node functions
	// No free_node function is provided, as nodes are freed along with the list They
	// belong to
	CCONTAINERS_API Node* 	CCONTAINERS_CALL node_new(void* data, size_t size);

	CCONTAINERS_API Node* 	CCONTAINERS_CALL node_copy(Node* node);

	CCONTAINERS_API void* 	CCONTAINERS_CALL node_data(Node* node);

	CCONTAINERS_API void 	CCONTAINERS_CALL node_set_data_free(Node* node, void (*data_free)(void*));

#ifdef __cplusplus
}
#endif

#endif // LIST_H
