
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
    VECTOR* test_vector = vector_new(sizeof(TestStruct));

    TestStruct test_struct;
    test_struct._double = 8.34;
    test_struct._integer = 8732;
    test_struct._string = "Example string for testing";

    vector_push_back(test_vector, &test_struct);

    TestStruct test_struct1;
    test_struct1._string = "Other example string for testing";
    test_struct1._integer = 213;
    test_struct1._double = 832.12;

    vector_push_back(test_vector, &test_struct1);

    TestStruct test_struct2;
    test_struct2._string = "Third example string";
    test_struct2._integer = 8;
    test_struct2._double = 7.21;

    vector_push(test_vector, &test_struct2);

    for (int i = 0; i < vector_size(test_vector); i++)
    {
        TestStruct t_struct;
        vector_get(test_vector, &t_struct, i);

        printf("TestStruct: {%.2f, %d, %s}\n", t_struct._double, t_struct._integer, t_struct._string);
    }

    vector_remove(test_vector, 1);

    printf("\nElement %d was removed\n\n", 1);

    for (int i = 0; i < vector_size(test_vector); i++)
    {
        TestStruct t_struct;
        vector_get(test_vector, &t_struct, i);

        printf("TestStruct: {%.2f, %d, %s}\n", t_struct._double, t_struct._integer, t_struct._string);
    }

    TestStruct test_struct3;
    test_struct3._string = "Fourth example string";
    test_struct3._integer = 19;
    test_struct3._double = 23.2;
    vector_insert(test_vector, &test_struct3, 1);

    printf("\nElement inserted at index {%d}\n\n", 1);

    for (int i = 0; i < vector_size(test_vector); i++)
    {
        TestStruct t_struct;
        vector_get(test_vector, &t_struct, i);

        printf("TestStruct: {%.2f, %d, %s}\n", t_struct._double, t_struct._integer, t_struct._string);
    }

    printf("\n\n");

    vector_print_contents(test_vector);

    printf("\n\n");

    vector_pop(test_vector);
    vector_pop_back(test_vector);

    printf("pop and pop_back called on test_vector\n");
    printf("Attempting to print elements of test_vector if any remain..\n");

    for (int i = 0; i < vector_size(test_vector); i++)
    {
        TestStruct t_struct;
        vector_get(test_vector, &t_struct, i);

        printf("TestStruct: {%.2f, %d, %s}\n", t_struct._double, t_struct._integer, t_struct._string);
    }

    vector_clear(test_vector);
    vector_free(test_vector);
    return 0;
}
