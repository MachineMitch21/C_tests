
#include <map.h>

typedef int (*equ_callback)(void* first, void* second);

struct _Map {
    List*           _pairs;

    /* Callback function for checking key equality for this map struct */
    equ_callback    keyequ;
};

struct _Pair {
    void* _key;
    void* _value;
};

Pair*   pair_new(void* key, void* value)
{
    Pair* pair = malloc(sizeof(*pair));
    pair->_key      = key;
    pair->_value    = value;

    return pair;
}

void*   pair_key(Pair* pair)
{
    return pair->_key;
}

void*   pair_value(Pair* pair)
{
    return pair->_value;
}

void    pair_free(Pair* pair)
{
    free(pair);
}


Map*    map_new(equ_callback keyequ)
{
    Map* map    = malloc(sizeof(*map));
    map->_pairs = list_new();
    map->keyequ = keyequ;

    return map;
}

int     map_size(Map* map)
{
    return list_size(map->_pairs);
}

void*   map_get_value(Map* map, void* key, int* rc)
{
    List* temp_pairs = map->_pairs;

    int size = map_size(map);

    int i;
    for (i = 0; i < size; i++)
    {
        Node* node = list_get_element(temp_pairs, i);

        if (node != NULL)
        {
            Pair* pair = (Pair*) node_data(node);

            if (map->keyequ(pair->_key, key) == 0)
            {
                *rc = list_last_error(temp_pairs);
                return pair->_value;
            }
        }
    }

    *rc = NO_ELEMENT_FOUND;
    return NULL;
}

int     map_insert(Map* map, void* key, void* value, int index)
{
    List* temp_pairs = map->_pairs;

    int size = map_size(map);

    int i;
    for (i = 0; i < size; i++)
    {
        Node* node = list_get_element(temp_pairs, i);

        if (node != NULL)
        {
            Pair* pair = (Pair*) node_data(node);

            list_insert(temp_pairs, pair, index);
            break;
        }
    }

    return list_last_error(temp_pairs);
}

int     map_remove(Map* map, void* key)
{
    List* temp_pairs = map->_pairs;

    int size = map_size(map);

    int i;
    for (i = 0; i < size; i++)
    {
        Node* node = list_get_element(temp_pairs, i);

        if (node != NULL)
        {
            Pair* pair = (Pair*) node_data(node);

            if (map->keyequ(pair->_key, key) == 0)
            {
                list_remove_i(temp_pairs, i);
                return LIST_OKAY;
            }
        }
    }

    return NO_ELEMENT_FOUND;
}

List*  map_get_keys(Map* map, int* rc)
{
    List* keys_list = list_new();

    List* temp_pairs = map->_pairs;

    int size = list_size(temp_pairs);

    int i;
    for (i = 0; i < size; i++)
    {
        Node* node = list_get_element(temp_pairs, i);

        if (node != NULL)
        {
            list_push(keys_list, node_copy(node));
        }
    }

    return keys_list;
}

List*  map_get_values(Map* map, int* rc)
{
    List* vals_list = list_new();

    List* temp_pairs = map->_pairs;

    int size = list_size(temp_pairs);

    int i;
    for (i = 0; i < size; i++)
    {
        Node* node = list_get_element(temp_pairs, i);

        if (node != NULL)
        {
            list_push(vals_list, node_copy(node));
        }
    }

    return vals_list;
}

int     map_push(Map* map, void* key, void* value)
{
    List* temp_pairs = map->_pairs;
    Pair pair;

    pair._key      = key;
    pair._value    = value;

    list_push(temp_pairs, node_new(&pair, sizeof(Pair)));

    return list_last_error(temp_pairs);
}

int     map_pop(Map* map)
{
    List* temp_pairs = map->_pairs;

    list_pop(temp_pairs);

    return list_last_error(temp_pairs);
}

Pair*   map_peek(Map* map, int* rc)
{
    List* temp_pairs = map->_pairs;

    Node* node = list_peek(temp_pairs);

    if (node != NULL)
    {
        Pair* pair = (Pair*) node_data(node);
        *rc = LIST_OKAY;
        return pair;
    }

    *rc = list_last_error(temp_pairs);
    return NULL;
}

int     map_push_back(Map* map, void* key, void* value)
{
    List* temp_pairs = map->_pairs;

    Pair pair;

    pair._key   = key;
    pair._value = value;

    list_push_back(temp_pairs, node_new(&pair, sizeof(Pair)));

    return list_last_error(temp_pairs);
}

int     map_pop_back(Map* map)
{
    List* temp_pairs = map->_pairs;

    list_pop_back(temp_pairs);

    return list_last_error(temp_pairs);
}

Pair*   map_peek_back(Map* map, int* rc)
{
    List* temp_pairs = map->_pairs;
    Node* node = list_peek_back(temp_pairs);

    if (node != NULL)
    {
        Pair* pair = (Pair*) node_data(node);
        *rc = LIST_OKAY;
        return pair;
    }

    *rc = list_last_error(temp_pairs);
    return NULL;
}

int     map_modify_value(Map* map, void* key, void* new_val)
{
    List* temp_pairs = map->_pairs;

    int size = list_size(temp_pairs);

    int i;
    for (i = 0; i < size; i++)
    {
        Node* node = list_get_element(temp_pairs, i);

        if (node != NULL)
        {
            Pair* pair = (Pair*) node_data(node);

            if (map->keyequ(pair->_key, key) == 0)
            {
                pair->_value = new_val;
                return LIST_OKAY;
            }
        }
    }

    return NO_ELEMENT_FOUND;
}

int     map_clear(Map* map)
{
    List* temp_pairs = map->_pairs;

    list_clear(temp_pairs);

    return list_last_error(temp_pairs);
}

int     map_free(Map* map)
{
    free_list(map->_pairs);
    free(map);
}
