
#ifndef MAP_H
#define MAP_H

#include "c_containers.h"
#include <memory.h>
#include <stdlib.h>

typedef struct _Map Map;
typedef struct _Pair Pair;

#ifdef __cplusplus
#define extern "C"
{
#endif

	CCONTAINERS_API Pair*   		CCONTAINERS_CALL pair_new(void* key, void* value);

	CCONTAINERS_API void*   		CCONTAINERS_CALL pair_key(Pair* pair);

	CCONTAINERS_API void*   		CCONTAINERS_CALL pair_value(Pair* pair);

	CCONTAINERS_API void    		CCONTAINERS_CALL pair_free(Pair* pair);

	CCONTAINERS_API Map*    		CCONTAINERS_CALL map_new();

	CCONTAINERS_API int     		CCONTAINERS_CALL map_size(Map* map);

	CCONTAINERS_API void*   		CCONTAINERS_CALL map_get_value(Map* map, void* key, int* rc);

	CCONTAINERS_API int     		CCONTAINERS_CALL map_insert(Map* map, void* key, void* value, int index);

	CCONTAINERS_API int     		CCONTAINERS_CALL map_remove(Map* map, void* key);

	CCONTAINERS_API struct List_s*  CCONTAINERS_CALL map_get_keys(Map* map, int* rc);

	CCONTAINERS_API struct List_s*  CCONTAINERS_CALL map_get_values(Map* map, int* rc);

	CCONTAINERS_API int     		CCONTAINERS_CALL map_push(Map* map, void* key, void* value);

	CCONTAINERS_API int     		CCONTAINERS_CALL map_pop(Map* map);

	CCONTAINERS_API Pair*   		CCONTAINERS_CALL map_peek(Map* map, int* rc);

	CCONTAINERS_API int     		CCONTAINERS_CALL map_push_back(Map* map, void* key, void* value);

	CCONTAINERS_API int     		CCONTAINERS_CALL map_pop_back(Map* map);

	CCONTAINERS_API Pair*   		CCONTAINERS_CALL map_peek_back(Map* map, int* rc);

	CCONTAINERS_API int     		CCONTAINERS_CALL map_modify_value(Map* map, void* key, void* new_val);

	CCONTAINERS_API int     		CCONTAINERS_CALL map_clear(Map* map);

	CCONTAINERS_API int     		CCONTAINERS_CALL map_free(Map* map);

#ifdef __cplusplus
}
#endif

#endif // MAP_H
