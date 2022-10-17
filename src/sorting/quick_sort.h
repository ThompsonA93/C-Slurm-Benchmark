#ifndef QUICK_SORT
#define QUICK_SORT

#include "utils_sort.h"

int assemble_partition(int arr[], int low, int high)
{
    int pt, flag;
    pt = low;
    flag = 0;
    while (flag != 1)
    {
        while ((arr[pt] <= arr[high] && (pt != high)))
            high--;
        if (pt == high)
            flag = 1;
        else if (arr[pt] > arr[high])
        {
            swap(&arr[pt], &arr[high]);
            pt = high;
        }
        if (flag != 1)
        {
            while ((arr[pt] >= arr[low]) && (pt != low))
                low++;
            if (pt == low)
                flag = 1;
            else if (arr[pt] < arr[low])
            {
                swap(&arr[pt], &arr[low]);
                pt = low;
            }
        }
    }
    return pt;
}

/**
 * Implementation for simple quick sort
 * @param arr as array to sort
 * @param p1 as partition point 1 (lower limit)
 * @param p2 as partition point 2 (higher limit)
 */
void quick_sort(int arr[], int p1, int p2)
{
    if (p1 < p2)
    {
        int pt = assemble_partition(arr, p1, p2);
        quick_sort(arr, p1, pt - 1);
        quick_sort(arr, pt + 1, p2);
    }
}

#endif