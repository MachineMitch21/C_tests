
#include <stdio.h>
#include <time.h>
#include "merge.h"
#include "selection.h"

#define ARRAY_SIZE 100000

void print_array(int arr[], int size)
{
    int i;
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void print_current_time()
{
    time_t raw_time;
    struct tm* time_info;
    time(&raw_time);
    time_info = localtime(&raw_time);
    printf("%d:%d:%d\n",time_info->tm_hour, time_info->tm_min, time_info->tm_sec);
}

int main(int argc, char** argv)
{
    int* arr = (int*) malloc(ARRAY_SIZE * sizeof(int));

    int* arr2 = (int*) malloc(ARRAY_SIZE * sizeof(int));

    int i;
    for (i = 0; i < ARRAY_SIZE; i++)
    {
        int val = ARRAY_SIZE - i;
        arr[i] = val;
        arr2[i] = val;
    }

    float start_ms, end_ms;

    printf("\nArray element count: %d\n\n", ARRAY_SIZE);

    printf("Both arrays are in descending order from %d to 1\n\n", ARRAY_SIZE);

    printf("Performing selection sort...\n");
    selection_sort(arr, ARRAY_SIZE);
    printf("selection sort finished\n\n");

    printf("Performing merge sort...\n");
    merge_sort(arr, 0, ARRAY_SIZE - 1);
    printf("merge sort finished\n\n");

    free(arr);
    free(arr2);
    return 0;
}
