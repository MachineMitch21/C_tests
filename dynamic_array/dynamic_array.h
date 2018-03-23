#include <stdlib.h>
#include <memory.h>

typedef struct _VECTOR VECTOR;

#define VECTOR_OK                   0
#define VECTOR_ALLOCATION_ERR       -1
#define VECTOR_INDEX_OUT_OF_RANGE   -2

// Allocates space for a VECTOR struct instance on the heap
VECTOR* vector_new(size_t elementSize);

// Adds an element to the end of the VECTOR
int     vector_push_back(VECTOR* vector, void* ptr);

// Adds an element to the front of the VECTOR
int     vector_push(VECTOR* vector, void* ptr);

// Removes an element from the back of the VECTOR
int     vector_pop_back(VECTOR* vector);

// Removes an element from the front of the VECTOR
int     vector_pop(VECTOR* vector);

// Retreives the element at (index) position in the VECTOR and stores it in (ptr)
int     vector_get(VECTOR* vector, void* ptr, int index);

// Gets the length of the VECTOR
size_t  vector_size(VECTOR* vector);

// Removes an element from the VECTOR at (index) position
int     vector_remove(VECTOR* vector, int index);

// Inserts an element anywhere in the array at the index specified
int     vector_insert(VECTOR* vector, void* ptr, int index);

// Clears the contents of the VECTOR
int     vector_clear(VECTOR* vector);

// Frees the memory taken up by the VECTOR
int     vector_free(VECTOR* vector);

void    vector_print_contents(VECTOR* vector);
