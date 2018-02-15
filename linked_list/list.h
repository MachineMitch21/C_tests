
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

typedef struct Node Node;

typedef struct DummyStruct {
    double      test_double;
    int         test_int;
    const char* test_str;
} DummyStruct;

void free_dummyStruct(void* d_struct);

struct Node {
    Node*   next;
    void*   data;
};

typedef struct {
    Node*   root;
    int     lastError;
} List;

// ------------------------------------
// List functions
List* list_new();

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

void list_remove(List* list, int index);

void free_list(List* list);

// ------------------------------------
// Node functions
Node* node_new(void* data, size_t size);

void node_set_data_free(Node* node, void (*data_free)(void*));

void free_node(Node* node);
