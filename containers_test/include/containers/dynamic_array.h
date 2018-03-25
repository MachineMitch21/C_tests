
#include "c_containers.h"
#include <stdlib.h>
#include <stdarg.h>
#include <assert.h>
#include <memory.h>

typedef struct _VECTOR VECTOR;

#define VECTOR_OK                   0
#define VECTOR_ALLOCATION_ERR       -1
#define VECTOR_INDEX_OUT_OF_RANGE   -2

// Allocates space for a VECTOR struct instance on the heap
CCONTAINERS_API VECTOR* CCONTAINERS_CALL vector_new(size_t elementSize);

// Allocates space for a VECTOR struct instance on the heap
// and sets (howManyElements) number of elements equal to *ptr
CCONTAINERS_API VECTOR* CCONTAINERS_CALL vector_new_d(void* ptr, int howManyElements, size_t elementSize);

// Adds an element to the end of the VECTOR
CCONTAINERS_API int     CCONTAINERS_CALL vector_push_back(VECTOR* vector, void* ptr);

// Adds an element to the front of the VECTOR
CCONTAINERS_API int     CCONTAINERS_CALL vector_push(VECTOR* vector, void* ptr);

// Removes an element from the back of the VECTOR
CCONTAINERS_API int     CCONTAINERS_CALL vector_pop_back(VECTOR* vector);

// Removes an element from the front of the VECTOR
CCONTAINERS_API int     CCONTAINERS_CALL vector_pop(VECTOR* vector);

// Swap the elements in the two input vectors
CCONTAINERS_API int     CCONTAINERS_CALL vector_swap(VECTOR* vector1, VECTOR* vector2);

// Set the element at position (index)
CCONTAINERS_API int     CCONTAINERS_CALL vector_set(VECTOR* vector, void* ptr, int index);

// Retreives the element at (index) position in the VECTOR and stores it in (ptr)
CCONTAINERS_API int     CCONTAINERS_CALL vector_get(VECTOR* vector, void* ptr, int index);

// Gets the length of the VECTOR
CCONTAINERS_API size_t  CCONTAINERS_CALL vector_size(VECTOR* vector);

// Removes an element from the VECTOR at (index) position
CCONTAINERS_API int     CCONTAINERS_CALL vector_remove(VECTOR* vector, int index);

// Inserts an element anywhere in the array at the index specified
CCONTAINERS_API int     CCONTAINERS_CALL vector_insert(VECTOR* vector, void* ptr, int index);

// Clears the contents of the VECTOR
CCONTAINERS_API int     CCONTAINERS_CALL vector_clear(VECTOR* vector);

// Compares the element at (index) to the memory at location pointed to by ptr
CCONTAINERS_API int     CCONTAINERS_CALL vector_elemcmp(VECTOR* vector, void* ptr, int index);

// Frees the memory taken up by the VECTOR
CCONTAINERS_API int     CCONTAINERS_CALL vector_free(VECTOR* vector);

// Sets the print function callback
CCONTAINERS_API void    CCONTAINERS_CALL vector_set_print_callback(VECTOR* vector, void (*print)(VECTOR* vector));

// Calls the callback that was passed to vector_set_print_callback
// The idea is to give programmers the power to access each element and
// perform whatever casts are needed and print each element the way it would
// need to be printed
CCONTAINERS_API void    CCONTAINERS_CALL vector_print(VECTOR* vector);
