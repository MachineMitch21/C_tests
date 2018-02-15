
#include <stdio.h>
#include "list.h"

int main(int argc, char** argv)
{
    List* list = list_new();

    char* data = "Test";
    Node* node = node_new(data, sizeof(char*));

    list_push(list, node);
    list_push(list, node_new("Test 2", sizeof(char*)));
    list_push_back(list, node_new("Test 3", sizeof(char*)));
    list_insert(list, node_new("Test 4", sizeof(char*)), 1);

    printf("The list has %d elements.\n\n", list_size(list));

    Node* n = list_get_element(list, 0);

    if (n != NULL)
    {
        printf("Element 0 data: %s\n", (char*)n->data);
    }

    Node* n1 = list_get_element(list, 1);

    if (n1 != NULL)
    {
        printf("Element 1 data: %s\n", (char*)n1->data);
    }

    Node* n2 = list_get_element(list, 2);

    if (n1 != NULL)
    {
        printf("Element 2 data: %s\n", (char*)n2->data);
    }

    Node* n3 = list_get_element(list, 4);

    if (n3 != NULL)
    {
        printf("Element 3 data: %s\n\n", (char*)n3->data);
    }

    list_pop(list);
    list_pop_back(list);

    printf("List has %d element after pop and pop_back.\n", list_size(list));

    printf("Element 0 data: %s\n\n", (char*)list_get_element(list, 0)->data);


    List* dummyStructList = list_new();

    DummyStruct d_struct;

    d_struct.test_double = 3.2;
    d_struct.test_int = 32;
    d_struct.test_str = "Test";

    Node* d_node = node_new(&d_struct, sizeof(DummyStruct));

    list_push(dummyStructList, d_node);

    DummyStruct test = *(DummyStruct*)list_get_element(dummyStructList, 0)->data;

    printf("Dummy struct double: %f\n", test.test_double);
    printf("Dummy struct int: %d\n", test.test_int);
    printf("Dummy struct string: %s\n", test.test_str);

    list_pop(dummyStructList);

    printf("Dummy struct list now has %d elements.\n", list_size(dummyStructList));

    List* clearTest = list_new();

    int myVal = 8;
    int myVal2 = 15;

    list_push_back(clearTest, node_new(&myVal, sizeof(int)));
    list_push_back(clearTest, node_new(&myVal2, sizeof(int)));

    printf("Clear test list has %d elements.\n", list_size(clearTest));

    int val0 = *(int*)list_get_element(clearTest, 0)->data;
    int val1 = *(int*)list_get_element(clearTest, 1)->data;

    printf("\nValue 0: %d\n\n", val0);
    printf("Value 1: %d\n\n", val1);

    list_remove(clearTest, 0);

    printf("Clear test has %d elements after removing index 0\n", list_size(clearTest));

    list_clear(clearTest);

    printf("Clear test list has %d elements after list_clear\n", list_size(clearTest));

    free_list(list);
    free_list(dummyStructList);
    free_list(clearTest);
    return 0;
}
