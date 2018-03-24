
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include "dynamic_array.h"

typedef struct {
    double  _double;
    int     _integer;
    char*   _string;
} TestStruct;

void print_test_struct_vector(VECTOR* vector)
{
    for (int i = 0; i < vector_size(vector); i++)
    {
        TestStruct t_struct;
        vector_get(vector, &t_struct, i);

        printf("TestStruct: {%.2f, %d, %s}\n", t_struct._double, t_struct._integer, t_struct._string);
    }
}

void test_one()
{
    VECTOR* test_vector = vector_new(sizeof(TestStruct));

    vector_set_print_callback(test_vector, &print_test_struct_vector);

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

    vector_remove(test_vector, 1);

    printf("\nElement %d was removed\n\n", 1);
    vector_print(test_vector);

    TestStruct test_struct3;
    test_struct3._string = "Fourth example string";
    test_struct3._integer = 19;
    test_struct3._double = 23.2;
    vector_insert(test_vector, &test_struct3, 1);

    printf("\nElement inserted at index {%d}\n\n", 1);

    printf("\n\n");

    vector_print(test_vector);

    printf("\n\n");

    vector_pop(test_vector);
    vector_pop_back(test_vector);

    printf("pop and pop_back called on test_vector\n");
    printf("Attempting to print elements of test_vector if any remain..\n");

    vector_print(test_vector);

    vector_clear(test_vector);
    vector_free(test_vector);
}

void test_two()
{
    TestStruct test_struct;
    test_struct._double = 4.32;
    test_struct._integer = 23;
    test_struct._string = "A string of characters";

    VECTOR* test_vector1 = vector_new_d(&test_struct, 7, sizeof(TestStruct));
    VECTOR* test_vector2 = vector_new(sizeof(TestStruct));

    test_struct._double = 128.23;
    test_struct._string = "Another string of characters";
    test_struct._integer = 823;

    vector_push_back(test_vector2, &test_struct);

    vector_print(test_vector1);

    vector_swap(test_vector1, test_vector2);

    vector_print(test_vector1);
}

int main(int argc, char** argv)
{
    test_one();
    return 0;
}
