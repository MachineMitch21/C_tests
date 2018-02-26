
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    void* data;
    void (*print_something)(char*);
} Test;

typedef struct {
    void* data;
    void (*print_something)(char*);
} Test1;


void print_something(char* str)
{
    printf("%s\n", str);
}

int main()
{
    Test* test = test_new();

    char* data = "Some data";
    test->data = (void*)data;
    test->print_something = print_something;

    Test1* test1 = (Test1*)test;

    test1->print_something("Something");

    test_free(test);

    return 0;
}
