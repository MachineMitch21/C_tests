
#include "util.h"

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
