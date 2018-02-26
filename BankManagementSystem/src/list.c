
#include <bms/list.h>

struct Node_s {
    Node* next;
    void* data;
};

struct List_s {
    Node*   root;
    int     lastError;
};

// --------------------------------------------------------------
// Node stuff

Node* node_new(void* data, size_t size)
{
    Node* node      = (Node*) malloc(sizeof(Node));
    node->next      = NULL;
    node->data      = data;

    return node;
}

void* node_data(Node* node)
{
    return node->data;
}

void free_node(Node* node)
{
    free(node);
    node = NULL;
}

// -------------------------------------------------------------

List* list_new()
{
    List* list          = (List*) malloc(sizeof(List));

    assert(list != NULL);
    list->root          = NULL;
    list->lastError = LIST_OKAY;
}

int list_last_error(List* list)
{
    return list->lastError;
}

int list_size(List* list)
{
    assert(list != NULL);

    Node* current = list->root;
    int count = 0;

    while (current != NULL)
    {
        current = current->next;
        count++;
    }

    return count;
}

bool list_is_empty(List* list)
{
    return (list->root == NULL);
}

Node* list_get_element(List* list, int index)
{
    assert(list != NULL);

    if ((list_is_empty(list)) == false)
    {
        Node* current = list->root;
        int count = 0;

        do
        {
            if (count == index)
            {
                list->lastError = LIST_OKAY;
                return current;
            }

            current = current->next;
            count++;
        } while (current != NULL);
    }

    list->lastError = INDEX_OUT_OF_RANGE;

    // If the index we are searching for doesn't exist or current happened to be NULL
    // just return NULL so anyone using the List API will know something went wrong
    return NULL;
}

bool list_push(List* list, Node* node)
{
    assert(node != NULL && list != NULL);

    if (list_is_empty(list))
    {
        list->root = node;
        list->lastError = LIST_OKAY;
        return true;
    }
    else
    {
        Node* currentRoot = list->root;
        list->root = node;
        list->root->next = currentRoot;
        list->lastError = LIST_OKAY;
        return true;
    }
}

void list_pop(List* list)
{
    assert(list != NULL);

    Node* current = list->root;

    list->root = current->next;
    free_node(current);
}

Node* list_peek(List* list)
{
    if (list_is_empty(list) == true)
    {
        list->lastError = EMPTY_LIST_ERROR;
        return NULL;
    }

    return list->root;
}

void list_push_back(List* list, Node* node)
{
    assert(node != NULL && list != NULL);

    if (list_is_empty(list) == true)
    {
        list->root = node;
    }
    else
    {
        Node* current = list->root;

        while (current->next != NULL)
        {
            current = current->next;
        }

        current->next = node;
    }
}

void list_pop_back(List* list)
{
    assert(list != NULL);

    if (list_is_empty(list) == true)
    {
        list->lastError = INVALID_POP;
    }
    else
    {
        if (list_size(list) == 1)
        {
            list->root = NULL;
        }
        else
        {
            Node* current = list->root;
            Node* previous = NULL;

            while (current->next != NULL)
            {
                previous = current;
                current = current->next;
            }

            previous->next = NULL;
            free_node(current);
        }
        list->lastError = LIST_OKAY;
    }
}

Node* list_peek_back(List* list)
{
    assert(list != NULL);

    if (list_is_empty(list) == true)
    {
        list->lastError = EMPTY_LIST_ERROR;
        return NULL;
    }
    else
    {
        Node* current = list->root;

        while (current->next != NULL)
        {
            current = current->next;
        }

        list->lastError = LIST_OKAY;
        return current;
    }
}

void list_clear(List* list)
{
    assert(list != NULL);

    while (list_is_empty(list) == false)
    {
        list_pop(list);
    }
}

void list_insert(List* list, Node* node, int index)
{
    assert(list != NULL && node != NULL);

    if (list_is_empty(list) == true && index != 0)
    {
        list->lastError = INDEX_OUT_OF_RANGE;
        return;
    }
    else if (list_is_empty(list) == true && index == 0)
    {
        list->lastError = LIST_OKAY;
        list->root = node;
        return;
    }
    else
    {
        Node* current = list->root;
        Node* previous = NULL;
        int count = 0;

        do
        {
            if (index == count)
            {
                if (previous != NULL)
                {
                    previous->next = node;
                    node->next = current;
                }
                else
                {
                    // if previous node == NULL
                    // we are inserting at root node
                    list->root = node;
                    node->next = current;
                }
                list->lastError = LIST_OKAY;
                return;
            }
            previous = current;
            current = current->next;
            count++;
        } while (current != NULL);

        list->lastError = INDEX_OUT_OF_RANGE;
        return;
    }
}

bool list_remove_i(List* list, int index)
{
    assert(list != NULL);

    if (list_is_empty(list) == true)
    {
        list->lastError = EMPTY_LIST_ERROR;
        return false;
    }

    Node* current = list->root;
    Node* previous = NULL;
    int count = 0;

    do
    {
        if (index == count)
        {
            if (previous != NULL)
            {
                Node* currentNext = current->next;
                previous->next = currentNext;
                list->lastError = LIST_OKAY;
                free_node(current);
            }
            else
            {
                Node* currentRoot = list->root;
                Node* rootNext = currentRoot->next;
                list->root = rootNext;
                list->lastError = LIST_OKAY;
                free_node(currentRoot);
            }
            return true;
        }
        previous = current;
        current = current->next;
        count++;
    } while (current != NULL);

    list->lastError = INDEX_OUT_OF_RANGE;
    return false;
}

// Same as remove_i but rather than checking the index count
// we check pointer equality against each node in the list with
// the node input
bool list_remove_n(List* list, Node* node)
{
    assert(list != NULL && node != NULL);

    if (list_is_empty(list) == true)
    {
        list->lastError = EMPTY_LIST_ERROR;
        return false;
    }

    Node* current = list->root;
    Node* previous = NULL;

    do
    {
        if (current == node)
        {
            if (previous != NULL)
            {
                Node* currentNext = current->next;
                previous->next = currentNext;
                list->lastError = LIST_OKAY;
                free_node(current);
            }
            else
            {
                Node* currentRoot = list->root;
                Node* rootNext = currentRoot->next;
                list->root = rootNext;
                list->lastError = LIST_OKAY;
                free_node(currentRoot);
            }
            list->lastError = LIST_OKAY;
            return true;
        }
        previous = current;
        current = current->next;
    } while (current != NULL);

    list->lastError = NO_ELEMENT_FOUND;
    return false;
}

void free_list(List* list)
{
    assert(list != NULL);

    // make sure we deallocate all the nodes first
    list_clear(list);
    free(list);
}
