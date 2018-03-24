
#include <bms/list.h>
#include <memory.h>
#include <stdlib.h>

typedef struct _Map Map;
typedef struct _Pair Pair;

Pair*   pair_new(void* key, void* value);

void*   pair_key(Pair* pair);

void*   pair_value(Pair* pair);

void    pair_free(Pair* pair);


Map*    map_new();

int     map_size(Map* map);

void*   map_get_value(Map* map, void* key, int* rc);

int     map_insert(Map* map, void* key, void* value, int index);

int     map_remove(Map* map, void* key);

List*   map_get_keys(Map* map, int* rc);

List*   map_get_values(Map* map, int* rc);

int     map_push(Map* map, void* key, void* value);

int     map_pop(Map* map);

Pair*   map_peek(Map* map, int* rc);

int     map_push_back(Map* map, void* key, void* value);

int     map_pop_back(Map* map);

Pair*   map_peek_back(Map* map, int* rc);

int     map_modify_value(Map* map, void* key, void* new_val);

int     map_clear(Map* map);

int     map_free(Map* map);
