#include "test.h"
#include <memory.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    test_holder* th = (test_holder*) malloc(sizeof(test_holder));

    test t[] = {
        { ._name = "Thing", ._number = 54, ._money = 54.3f },
        { ._name = "Another thing", ._number = 12, ._money = 83.2f },
        { ._name = "Some other thing", ._number = 823, ._money = 12.32f }
    };

    th->test_arr = (test*) malloc(sizeof(test) * 3);

    memmove(th->test_arr, t, sizeof(test) * 3);

    write_to_file(th, 3, "test.txt");

    free(th->test_arr);
    free(th);

    test_holder* th_from_file = read_file("test.txt");

    test* t1 = (test*) malloc(sizeof(test));

    int i = 0;
    for (i = 0; i < 3; i++)
    {
        t1 = &th_from_file->test_arr[i];
        if (t1 != NULL)
        {
            printf("Test name: %s\n", t1->_name);
            printf("Test number: %d\n", t1->_number);
            printf("Test money: %f\n", t1->_money);
        }
        printf("\n");
    }

    free(t1);
    free(th_from_file->test_arr);
    free(th_from_file);

    return 0;
}
