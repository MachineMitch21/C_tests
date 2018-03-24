
#include "dynamic_array.h"

struct _VECTOR {
    void    (*_print)(VECTOR* vector);
    size_t  _elementSize;
    size_t  _length;
    char*   _arr;
};

VECTOR* vector_new(size_t elementSize)
{
    VECTOR* vector          = malloc(sizeof(VECTOR));
    vector->_elementSize    = elementSize;
    vector->_arr            = malloc(0);
    vector->_length         = 0;

    vector->_print          = NULL;

    return vector;
}

VECTOR* vector_new_d(void* ptr, int howManyElements, size_t elementSize)
{
    // Really simplistic implementation

    /*TODO
     *  Make this function better lol
     */
    VECTOR* vector = vector_new(elementSize);

    for (int i = 0; i < howManyElements; i++)
    {
        vector_push_back(vector, ptr);
    }

    return vector;
}

int     vector_push_back(VECTOR* vector,  void* ptr)
{
    // Store a temporay array in case we have allocation errors, we can set
    // vector->_arr back to its previous state with this temp_arr
    char* temp_arr = malloc(vector->_elementSize * vector->_length);
    memmove(temp_arr, vector->_arr, (vector->_elementSize * vector->_length));

    // increment our length variable and reallocate enough space for one more element
    vector->_length += 1;
    vector->_arr = realloc(vector->_arr, vector->_elementSize * vector->_length);

    if (vector->_arr != NULL)
    {
        // Copy the void* parameter into the last element in vector->_arr
        memcpy(vector->_arr + (vector->_elementSize * (vector->_length - 1)), ptr, vector->_elementSize);
    }
    else
    {
        free(vector->_arr);
        vector->_arr = temp_arr;
        return VECTOR_ALLOCATION_ERR;
    }

    return 0;
}

int     vector_push(VECTOR* vector,  void* ptr)
{
    // Store temporary array in case of allocation errors
    char* temp_arr = malloc(vector->_elementSize * vector->_length);
    memmove(temp_arr, vector->_arr, (vector->_elementSize * vector->_length));

    // Inrement length and reallocate enough space for one more element
    vector->_length += 1;
    vector->_arr = realloc(vector->_arr, vector->_elementSize * vector->_length);

    if (vector->_arr != NULL)
    {
        for (int i = vector->_length - 1; i > 0; i--)
        {
            // Move all the elements to the right in the array
            memmove(vector->_arr + (vector->_elementSize * i), vector->_arr + (vector->_elementSize * (i - 1)), vector->_elementSize);
        }
        // Copy the contents of the void* parameter into the first element in vector->_arr
        memcpy(vector->_arr + (vector->_elementSize * 0), ptr, vector->_elementSize);
    }
    else
    {
        free(vector->_arr);
        vector->_arr = temp_arr;
        return VECTOR_ALLOCATION_ERR;
    }
}

int     vector_pop_back(VECTOR* vector)
{
    memset(vector->_arr + (vector->_elementSize * (vector->_length - 1)), 0, vector->_elementSize);
    vector->_length -= 1;
    vector->_arr = realloc(vector->_arr, vector->_elementSize * (vector->_length));

    if (vector->_arr == NULL)
    {
        vector->_arr = NULL;
        free(vector->_arr);
        return VECTOR_ALLOCATION_ERR;
    }

    return VECTOR_OK;
}

int     vector_pop(VECTOR* vector)
{
    // Decrement length and allocate temporary array so we can edit the array without
    // screwing up vector->_arr

    memset(vector->_arr, 0, vector->_elementSize);

    for (int i = 0; i < vector->_length; i++)
    {
        memmove(vector->_arr + (vector->_elementSize * i), vector->_arr + (vector->_elementSize * (i + 1)), vector->_elementSize);
    }

    vector->_length -= 1;
    vector->_arr = realloc(vector->_arr, vector->_elementSize * vector->_length);

    return VECTOR_OK;
}

int     vector_get(VECTOR* vector, void* ptr, int index)
{
    if (index >= vector->_length)
    {
        return VECTOR_INDEX_OUT_OF_RANGE;
    }

    memmove(ptr, &vector->_arr[index * vector->_elementSize], vector->_elementSize);

    return VECTOR_OK;
}

size_t  vector_size(VECTOR* vector)
{
    return vector->_length;
}

int     vector_remove(VECTOR* vector, int index)
{
    if (index >= vector->_length || index < 0)
    {
        return VECTOR_INDEX_OUT_OF_RANGE;
    }

    if (index == vector->_length - 1)
    {
        vector_pop_back(vector);
        return VECTOR_OK;
    }
    else if (index == 0)
    {
        vector_pop(vector);
        return VECTOR_OK;
    }

    for (int i = index; i < vector->_length - 1; i++)
    {
        memmove(vector->_arr + (vector->_elementSize * i), vector->_arr + (vector->_elementSize * (i + 1)), vector->_elementSize);
    }

    vector->_length -= 1;
    vector->_arr = realloc(vector->_arr, vector->_elementSize * vector->_length);

    return VECTOR_OK;
}

int     vector_insert(VECTOR* vector, void* ptr, int index)
{
    if (index > vector->_length - 1 || index < 0)
    {
        return VECTOR_INDEX_OUT_OF_RANGE;
    }

    vector->_length += 1;
    vector->_arr = realloc(vector->_arr, vector->_elementSize * vector->_length);

    if (vector->_arr != NULL)
    {
        for (int i = vector->_length - 1; i > index; i--)
        {
            memmove(vector->_arr + (vector->_elementSize * i), vector->_arr + (vector->_elementSize * (i - 1)), vector->_elementSize);
        }
    }

    memmove(vector->_arr + (vector->_elementSize * index), ptr, vector->_elementSize);
}

int     vector_swap(VECTOR* vector1, VECTOR* vector2)
{
    char* temp_arr = vector1->_arr;
    vector1->_arr = vector2->_arr;
    vector2->_arr = temp_arr;
}

int     vector_clear(VECTOR* vector)
{
    memset(vector->_arr, 0, (vector->_elementSize * vector->_length));
    vector->_length = 0;
    vector->_arr = realloc(vector->_arr, 0);

    return VECTOR_OK;
}

int     vector_free(VECTOR* vector)
{
    free(vector->_arr);
    vector->_length = 0;
    vector = NULL;
    free(vector);
}

void    vector_set_print_callback(VECTOR* vector, void (*print)())
{
    vector->_print = print;
}

void    vector_print(VECTOR* vector)
{
    if (vector->_print != NULL)
    {
        vector->_print(vector);
    }
}
