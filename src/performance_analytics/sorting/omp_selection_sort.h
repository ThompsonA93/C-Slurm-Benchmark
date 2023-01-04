#ifndef OMP_SELECTION_SORT
#define OMP_SELECTION_SORT

#include "utils_sort.h"
#include <omp.h>

/** Amount of threads to use **/
#ifndef OMP_THREADS
#define OMP_THREADS 2
#endif

/**
 * Implementation for simple selection sort using OpenMP Pragmas
 * @param arr as array to sort
 * @param n as amount of elements in the array
 */
void omp_selection_sort(int arr[], int n)
{
    int i, j, minimum;
    // Cannot be parallelized due to constant changes in the array
    for (i = 0; i < n - 1; i++)
    {
        minimum = i;

        // Seems to work: 0.55 -> 0.15 on 25000 elements
        #pragma omp parallel for
        for (j = i + 1; j < n; j++)
        {
            if (arr[minimum] > arr[j]){
                minimum = j;
            }
        }

        if (minimum != i){
            swap(&arr[minimum], &arr[i]);
        }
    }
}

#endif