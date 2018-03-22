
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

// ------------------------------------
// List functions
List* list_new();

int list_last_error(List* list);

int list_size(List* list);

Node* list_get_element(List* list, int index);

bool list_push(List* list, Node* node);

void list_pop(List* list);

Node* list_peek(List* list);

void list_push_back(List* list, Node* node);

void list_pop_back(List* list);

Node* list_peek_back(List* list);

void list_clear(List* list);

bool list_is_empty(List* list);

void list_insert(List* list, Node* node, int index);

bool list_remove_i(List* list, int index);

bool list_remove_n(List* list, Node* node);

void free_list(List* list);

// ------------------------------------
// Node functions
// No free_node function is provided, as nodes are freed along with the list They
// belong to
Node* node_new(void* data, size_t size);

Node* node_copy(Node* node);

void* node_data(Node* node);

void node_set_data_free(Node* node, void (*data_free)(void*));
