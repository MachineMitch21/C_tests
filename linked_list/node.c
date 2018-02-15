
#include "list.h"

Node* node_new(void* data, size_t size)
{
    Node* node      = (Node*) malloc(sizeof(Node));
    node->next      = NULL;
    node->data      = data;

    return node;
}

void free_node(Node* node)
{
    free(node);
    node = NULL;
}
