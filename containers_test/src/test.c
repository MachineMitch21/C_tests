
#include <containers/map.h>
#include <containers/list.h>
#include <containers/dynamic_array.h>

void print_int_vector(VECTOR* vector)
{
    int size = vector_size(vector);
    for (int i = 0; i < size; i++)
    {
        int value;
        vector_get(vector, &value, i);
        printf("Value at index {%d} is %d\n", i, value);
    }
}

int main(int argc, char** argv)
{
    int value = 983;
    VECTOR* test_vector = vector_new_d(&value, 250, sizeof(int));
    vector_set_print_callback(test_vector, &print_int_vector);
    vector_print(test_vector);
    vector_free(test_vector);
    return 0;
}
