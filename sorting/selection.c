
#include "selection.h"
#include "util.h"

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selection_sort(int arr[], int size)
{
    int i, j, min_idx;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < size-1; i++)
    {
        unsigned int isSorted = 1;
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
                isSorted = 0;
            }
        }

        if (isSorted == 1)
        {
            return;
        }

        // Swap the found minimum element with the first element
        swap(&arr[min_idx], &arr[i]);
    }
}
