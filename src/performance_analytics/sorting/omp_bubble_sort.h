#ifndef OMP_BUBBLE_SORT
#define OMP_BUBBLE_SORT

#include "utils_sort.h"
#include <omp.h>

/**
 * Implementation for simple bubble sort
 * @param arr as array to sort
 * @param n as amount of elements in the array
 */

void omp_bubble_sort(int arr[], int n)
{
    #pragma omp parallel for schedule(static) num_threads(12)
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (arr[j] > arr[j + 1])  
            {
                int t = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = t;
            }
        }
    }
}

#endif