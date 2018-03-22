#include <stdlib.h>
#include <memory.h>

typedef struct _VECTOR VECTOR;

#define VECTOR_OK                   0
#define VECTOR_ALLOCATION_ERR       -1
#define VECTOR_INDEX_OUT_OF_RANGE   -2

VECTOR* vector_new(size_t elementSize);
int     vector_push_back(VECTOR* vector, void* ptr);
int     vector_push(VECTOR* vector, void* ptr);
int     vector_pop_back(VECTOR* vector);
int     vector_pop(VECTOR* vector);
int     vector_get(VECTOR* vector, void* ptr, int index);
size_t  vector_size(VECTOR* vector);
int     vector_remove(VECTOR* vector, int index);
int     vector_insert(VECTOR* vector, void* ptr, int index);
int     vector_clear(VECTOR* vector);
int     vector_free(VECTOR* vector);
