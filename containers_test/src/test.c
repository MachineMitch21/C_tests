
#include <containers/c_containers.h>

typedef struct {
    VECTOR* _tVector;
    List*   _tList;
    Map*    _tMap;
} TestStruct;

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

int map_keycmp_callback(void* first, void* second)
{
    int integer_first = *(int*) first;
    int integer_second = *(int*) second;

    if (integer_first < integer_second)
    {
        return -1;
    }
    else if (integer_first == integer_second)
    {
        return 0;
    }
    else if (integer_first > integer_second)
    {
        return 1;
    }
}

void test_one()
{
    printf("\n\n-------Initiate test_one-------\n\n");

    int value = 983;
    VECTOR* test_vector = vector_new_d(&value, 250, sizeof(int));
    vector_set_print_callback(test_vector, &print_int_vector);

    printf("Printing the VECTOR at the beginning of test_one\n");
    vector_print(test_vector);
    printf("\n");

    Map* test_map = map_new();
    map_set_keycmp_callback(test_map, &map_keycmp_callback);

    int key = 1;
    map_push_back(test_map, &key, test_vector);

    VECTOR* vector = map_get_value(test_map, &key);
    printf("Printing VECTOR after getting it from the map\n");
    vector_print(vector);
    printf("\n");

    List* test_list = list_new();

    list_push_back(test_list, node_new(vector, vector_mem_size()));

    Node* list_node = list_peek(test_list);
    VECTOR* vector_from_list = node_data(list_node);
    printf("Printing VECTOR after getting it from test_list\n");
    vector_print(vector_from_list);
    printf("\n");
    vector_free(test_vector);
    printf("-------test_one complete-------\n\n");
}

void test_two()
{
    printf("\n-------Intiate test_two-------\n\n");

    int test_integer = 901234;
    TestStruct test_struct1;
    test_struct1._tVector   = vector_new_d(&test_integer, 100, sizeof(int));
    test_struct1._tList     = list_new();
    test_struct1._tMap      = map_new();

    vector_set_print_callback(test_struct1._tVector, &print_int_vector);

    for (int i = 0; i < 10; i++)
    {
        list_push_back(test_struct1._tList, node_new(test_struct1._tVector, vector_mem_size()));
    }

    int key = 123;
    map_push_back(test_struct1._tMap, &key, test_struct1._tList);

    TestStruct test_struct2;
    test_struct2._tVector   = vector_new_d(&test_struct1, 5, sizeof(TestStruct));
    test_struct2._tList     = list_new();
    test_struct2._tMap      = map_new();

    list_push_back(test_struct2._tList, &test_struct1);
    map_push_back(test_struct2._tMap, &key, &test_struct1);

    size_t size = vector_size(test_struct1._tVector);

    printf("\n-------test_two completed-------\n\n");
}

int main(int argc, char** argv)
{
    test_one();
    test_two();
    return 0;
}
