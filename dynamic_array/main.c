
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include "dynamic_array.h"

typedef struct {
    double  _double;
    int     _integer;
    char*   _string;
} TestStruct;

typedef struct {
    char*   _cstr;
} String;

void print_test_struct_vector(VECTOR* vector)
{
    size_t size = vector_size(vector);
    for (int i = 0; i < size; i++)
    {
        TestStruct t_struct;
        vector_get(vector, &t_struct, i);

        printf("TestStruct: {%.2f, %d, %s}\n", t_struct._double, t_struct._integer, t_struct._string);
    }
}

void print_int_vector(VECTOR* vector)
{
    size_t size = vector_size(vector);
    for (int i = 0; i < size; i++)
    {
        int value;
        vector_get(vector, &value, i);
        printf("Integer at index {%d} is %d\n", i, value);
    }
}

void print_str_vector(VECTOR* vector)
{
    size_t size = vector_size(vector);
    for (int i = 0; i < size; i++)
    {
        String* str;
        vector_get(vector, str, i);
        printf("%s\n", str->_cstr);
    }
}

void print_double_vector(VECTOR* vector)
{
    size_t size = vector_size(vector);
    for (int i = 0; i < size; i++)
    {
        double val;
        vector_get(vector, &val, i);
        printf("Double at index {%d} is %.2f\n", i, val);
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

    vector_set_print_callback(test_vector1, &print_test_struct_vector);
    vector_set_print_callback(test_vector2, &print_test_struct_vector);

    test_struct._double = 128.23;
    test_struct._string = "Another string of characters";
    test_struct._integer = 823;

    vector_push_back(test_vector2, &test_struct);

    printf("\nPrinting contents of test_vector1 before swapping elements with test_vector2\n");
    vector_print(test_vector1);

    vector_swap(test_vector1, test_vector2);

    printf("\nPrinting contents of test_vector1 after swapping elements with test_vector2\n");
    vector_print(test_vector1);

    vector_free(test_vector1);
    vector_free(test_vector2);
    printf("\n");
}

void test_three()
{
    int value = 231;
    VECTOR* integer_vector = vector_new_d(&value, 100, sizeof(int));

    vector_set_print_callback(integer_vector, &print_int_vector);

    int new_value = 87231;
    size_t size = vector_size(integer_vector);
    for (int i = 0; i < size; i++)
    {
        if (i % 2)
        {
            vector_set(integer_vector, &new_value, i);
        }
    }

    printf("Printing contents of integer_vector\n");
    vector_print(integer_vector);

    if (vector_elemcmp(integer_vector, &new_value, 1) == 0)
    {
        printf("\nThe element at index {%d} is equal to %d\n", 1, new_value);
    }
}

void test_four()
{
    String str;
    str._cstr = "Test string and what not";
    VECTOR* string_vector = vector_new_d(&str, 100, sizeof(String));

    vector_set_print_callback(string_vector, &print_str_vector);

    printf("Printing contents of string_vector\n");
    vector_print(string_vector);
}

void test_five()
{
    double value = 23.21;
    VECTOR* double_vector = vector_new_d(&value, 10000, sizeof(double));

    vector_set_print_callback(double_vector, &print_double_vector);

    printf("Printing contents of double_vector\n");
    vector_print(double_vector);
}

int main(int argc, char** argv)
{
    test_one();
    test_two();
    test_three();
    test_four();
    test_five();
    return 0;
}
