#ifndef OMP_SELECTION_SORT
#define OMP_SELECTION_SORT

#include <omp.h>
#include "../utils/utils_sort.h"

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

        // Must use reduction using struct ! FIXME :: Reduction throws error
        #pragma omp parallel for schedule(static) // reduction(=:minimum)
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