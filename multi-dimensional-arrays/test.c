#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    int threeD_arr[2][2][2] =
    {
        {
            { 2, 3 },
            { 3, 5 }
        },
        {
            { 3, 4 },
            { 2, 1 }
        }
    };

    printf("3D array has %d at row {%d} and column {%d} in table {%d}\n", threeD_arr[0][1][0], 1, 0, 0);

    int fourD_arr[2][2][2][2] =
    {
        {
            {
                {4, 3},
                {2, 3}
            },
            {
                {5, 3},
                {2, 3}
            }
        },
        {
            {
                {1, 231},
                {2, 74}
            },
            {
                {90, 342},
                {43, 9123}
            }
        }
    };

    printf("4D array has %d at row {%d} and column {%d} of table {%d} in table {%d}\n", fourD_arr[1][0][0][1], 0, 1, 0, 1);

    return 0;
}
