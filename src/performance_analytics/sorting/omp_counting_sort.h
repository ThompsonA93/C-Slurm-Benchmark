#ifndef OMP_COUNTING_SORT
#define OMP_COUNTING_SORT

#include "utils_sort.h"
#include <omp.h>

/** Amount of threads to use **/
#ifndef OMP_THREADS
#define OMP_THREADS 2
#endif

/**
 * Implementation for simple counting sort
 * @param arr as arr to sort
 * @param n as amount of elements in the arr
 */
void omp_counting_sort(int arr[], int n)
{

    // Find the largest element of the arr
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
    }

    int num_threads = 12;
    omp_set_num_threads(num_threads);

    int count[num_threads][max + 1];
    int output[n];

    // Initialize count with all zeros. SegFaults if omitted
    for (int i = 0; i < num_threads; i++)
    {
        for (int j = 0; j <= max; j++)
        {
            count[i][j] = 0;
        }
    }

    #pragma omp parallel for schedule(static)
    for (int i = 0; i < n; i += num_threads)
    {
        int iam = omp_get_thread_num();
        count[iam][arr[i + iam]]++;
    }

    int count_final[max + 1];
    for (int i = 0; i < max; i++)
    {
        int temp_sum = 0;
        for (int j = 0; j < num_threads; j++)
        {
            temp_sum += count[j][i];
        }
        count_final[i] = temp_sum;
    }

    for (int i = 1; i <= max; i++)
    {
        count_final[i] += count_final[i - 1];
    }

    for (int i = n - 1; i >= 0; i--)
    {
        int j = arr[i];
        count_final[j] -= 1;
        output[count_final[j]] = arr[i];
    }

    // Overwrite original array with sorted output. Alternatively as return arr[]
    for (int i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }
}

#endif