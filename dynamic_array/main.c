
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include "dynamic_array.h"

typedef struct {
    double  _double;
    int     _integer;
    char*   _string;
} TestStruct;

int main(int argc, char** argv)
{
    VECTOR* integer_vector = vector_new(sizeof(int));
    VECTOR* test_struct_vector = vector_new(sizeof(TestStruct));

    int test_val = 123;
    vector_push_back(integer_vector, &test_val);

    int test_val2 = 4321;
    vector_push_back(integer_vector, &test_val2);

    int test_val3 = 743;
    vector_push(integer_vector, &test_val3);

    vector_remove(integer_vector, 1);

    int test_val4 = 8732;
    vector_insert(integer_vector, &test_val4, 1);

    int test_val5 = 9832;
    vector_insert(integer_vector, &test_val5, 2);

    TestStruct t_struct;
    t_struct._double = 2.32;
    t_struct._integer = 32;
    t_struct._string = "Some String";
    vector_push_back(test_struct_vector, &t_struct);

    for (int i = 0; i < vector_size(integer_vector); i++)
    {
        int val;
        if (vector_get(integer_vector, &val, i) == VECTOR_OK)
        {
            printf("The value in the vector at index %d is %d\n", i, val);
        }
    }

    for (int i = 0; i < vector_size(test_struct_vector); i++)
    {
        TestStruct test;
        if (vector_get(test_struct_vector, &test, i) == VECTOR_OK)
        {
            printf("Test struct double: %.2f\n", test._double);
            printf("Test struct integer: %d\n", test._integer);
            printf("Test struct string: %s\n", test._string);
        }
    }

    vector_free(integer_vector);
    vector_free(test_struct_vector);
    return 0;
}
