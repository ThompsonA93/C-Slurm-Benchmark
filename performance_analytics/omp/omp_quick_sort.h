#ifndef OMP_QUICK_SORT
#define OMP_QUICK_SORT

#include <omp.h>
#include "../utils/utils_sort.h"
#include "../sorting/quick_sort.h"

/** Amount of threads to use **/
#ifndef OMP_THREADS
#define OMP_THREADS 2
#endif

int omp_assemble_partition(int arr[], int low, int high)
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

void omp_quick_sort_task(int arr[], int p1, int p2)
{
    if (p1 >= p2 || p1 < 0)
    {
        return;
    }
    int pt = omp_assemble_partition(arr, p1, p2);

    int low_limit = 1000;
    // if sub array size is very small -> sequential
    if (p2 - p1 < low_limit)
    {
        quick_sort(arr, p1, p2);
    }
    else
    {
#pragma omp parallel sections
        {
#pragma omp section
            omp_quick_sort_task(arr, p1, pt - 1);

#pragma omp section
            omp_quick_sort_task(arr, pt + 1, p2);
        }
    }
}
/**
 * Implementation for simple quick sort
 * @param arr as array to sort
 * @param p1 as partition point 1 (lower limit)
 * @param p2 as partition point 2 (higher limit)
 */
void omp_quick_sort(int arr[], int p1, int p2)
{
    omp_quick_sort_task(arr, p1, p2);
}

#endif