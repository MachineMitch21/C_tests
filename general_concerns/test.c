
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Interface Interface;

struct _Interface {
    void (*print_something)();
    void (*do_something)();
};

typedef struct {
    Interface*  _base;
} Implementation;

typedef struct {
    Interface*  _base;
} Implementation2;

void implementation2_doSomething()
{
    char hello[255] = "Hello, ";

    strcat(hello, "World!");

    printf("%s\n", hello);
}

void implementation2_printSomething()
{
    printf("Something from implementation 2 function\n");
}

Implementation2* implementation2_new()
{
    Implementation2* imp2           = malloc(sizeof(Implementation2));
    imp2->_base                     = malloc(sizeof(Interface));
    imp2->_base->print_something    = implementation2_printSomething;
    imp2->_base->do_something       = implementation2_doSomething;

    return imp2;
}

void implementation2_free(Implementation2* imp2)
{
    free(imp2->_base);
    free(imp2);
}

void implementation_doSomething()
{
    int a = 3;
    int b = 2;

    printf("a + b = %d\n", a + b);
}

void implementation_printSomething()
{
    printf("\nSomething from implementation function\n");
}

Implementation* implementation_new()
{
    Implementation* imp         = malloc(sizeof(Implementation));
    imp->_base                  = malloc(sizeof(Interface));
    imp->_base->print_something = implementation_printSomething;
    imp->_base->do_something    = implementation_doSomething;

    return imp;
}

void implementation_free(Implementation* imp)
{
    free(imp->_base);
    free(imp);
}

int main(int argc, char** argv)
{
    Implementation* imp     = implementation_new();
    Implementation2* imp2   = implementation2_new();

    Interface* imp_interface = imp->_base;
    Interface* imp2_interface = imp2->_base;

    Interface* interfaces[] = {imp_interface, imp2_interface};

    for (int i = 0; i < 2; i++)
    {
        interfaces[i]->print_something();
        interfaces[i]->do_something();
    }

    implementation_free(imp);
    implementation2_free(imp2);
    return 0;
}
