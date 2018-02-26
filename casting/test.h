
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct {
    char*   _name;
    int     _number;
    float   _money;
} test;

typedef struct {
    test* test_arr;
} test_holder;

void write_to_file(test_holder* th, size_t num_elements, const char* file_name);
test_holder* read_file(const char* file_name);
