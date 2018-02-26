
#include <stdio.h>
#include "merge.h"
#include "selection.h"
#include "bubble.h"

#define ARRAY_SIZE 100000

int main(int argc, char** argv)
{
    int* arr =  (int*) malloc(ARRAY_SIZE * sizeof(int));
    int* arr2 = (int*) malloc(ARRAY_SIZE * sizeof(int));
    int* arr3 = (int*) malloc(ARRAY_SIZE * sizeof(int));

    int i;
    for (i = 0; i < ARRAY_SIZE; i++)
    {
        int val = ARRAY_SIZE - i;
        arr[i] = val;
        arr2[i] = val;
        arr3[i] = val;
    }

    float start_ms, end_ms;

    printf("\nArray element count: %d\n\n", ARRAY_SIZE);

    printf("All arrays are in descending order from %d to 1\n\n", ARRAY_SIZE);

    printf("Performing bubble sort...\n");
    bubble_sort(arr, ARRAY_SIZE);
    printf("bubble sort finished\n\n");

    printf("Performing selection sort...\n");
    selection_sort(arr2, ARRAY_SIZE);
    printf("selection sort finished\n\n");

    printf("Performing merge sort...\n");
    merge_sort(arr3, 0, ARRAY_SIZE - 1);
    printf("merge sort finished\n\n");

    free(arr);
    free(arr2);
    free(arr3);
    return 0;
}
