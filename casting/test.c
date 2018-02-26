#include "test.h"

int my_getnbr(char* str);

void write_to_file(test_holder* th, size_t num_elements, const char* file_name)
{
    FILE* pFile;

    pFile = fopen(file_name, "wb");

    fprintf(pFile, "%d\n", num_elements);

    for (int i = 0; i < num_elements; i++)
    {
        test t1 = th->test_arr[i];
        fprintf(pFile, "%s\n", t1._name);
        fprintf(pFile, "%d\n", t1._number);
        fprintf(pFile, "%f\n", t1._money);
    }

    fclose(pFile);
}

test_holder* read_file(const char* file_name)
{
    FILE* pFile;
    size_t num_elements;
    size_t bytes_read = 0;

    pFile = fopen(file_name, "rb");

    test_holder* th = (test_holder*) malloc(sizeof(test_holder));

    th->test_arr = (test*) malloc(sizeof(test) * num_elements);

    fscanf(pFile, "%d", &num_elements);

    printf("%d\n", num_elements);

    test* t = (test*) malloc(sizeof(test) * num_elements);

    for (int i = 0; i < num_elements; i++)
    {
        test* temp_t = (test*) malloc(sizeof(test));
        temp_t->_name = (char*) malloc(sizeof(char) * 256);

        fgets(temp_t->_name, 256, pFile);
        fscanf(pFile, "%d", &temp_t->_number);
        fscanf(pFile, "%f", &temp_t->_money);

        memcpy(&t[i], temp_t, sizeof(test));

        free(temp_t);
    }

    memmove(th->test_arr, t, sizeof(test) * num_elements);

    fclose(pFile);
    return th;
}

int             my_getnbr(char *str)
{
    int           result;
    int           puiss;

    result = 0;
    puiss = 1;
    while (('-' == (*str)) || ((*str) == '+'))
    {
        if (*str == '-')
        puiss = puiss * -1;
        str++;
    }
    while ((*str >= '0') && (*str <= '9'))
    {
        result = (result * 10) + ((*str) - '0');
        str++;
    }
    return (result * puiss);
}
