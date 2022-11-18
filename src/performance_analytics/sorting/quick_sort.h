#ifndef QUICK_SORT
#define QUICK_SORT

#include "utils_sort.h"

int assemble_partition(int arr[], int low, int high)
{

    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    i++;
    swap(&arr[i], &arr[high]);
    return i;
}

/**
 * Implementation for simple quick sort
 * @param arr as array to sort
 * @param p1 as partition point 1 (lower limit)
 * @param p2 as partition point 2 (higher limit)
 */
void quick_sort(int arr[], int p1, int p2)
{
    if (p1 >= p2 || p1 < 0)
    {
        return;
    }
    int pt = assemble_partition(arr, p1, p2);
    quick_sort(arr, p1, pt - 1);
    quick_sort(arr, pt + 1, p2);
}

#endif