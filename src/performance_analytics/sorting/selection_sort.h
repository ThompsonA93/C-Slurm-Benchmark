#ifndef SELECTION_SORT
#define SELECTION_SORT

#include "utils_sort.h"

/**
 * Implementation for simple selection sort
 * @param arr as array to sort
 * @param n as amount of elements in the array
 */
void selection_sort(int arr[], int n)
{
    int i, j, minimum;
    for (i = 0; i < n - 1; i++)
    {
        minimum = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[minimum] > arr[j])
                minimum = j;
        }
        if (minimum != i)
            swap(&arr[minimum], &arr[i]);
    }
}

#endif