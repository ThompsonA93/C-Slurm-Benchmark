#ifndef OMP_COUNTING_SORT
#define OMP_COUNTING_SORT

#include "utils_sort.h"
#include <omp.h>
#include "utils_1d_array.h"

/** Amount of threads to use **/
#ifndef OMP_THREADS
#define OMP_THREADS 2
#endif

/**
 * Implementation for simple counting sort using OpenMP Pragmas
 * TODO
 * @param arr as arr to sort
 * @param n as amount of elements in the arr
 */
void omp_counting_sort(int arr[], int n)
{

    // Find the largest element of the arr
    int max = 0;
    for(int i = 0; i < n; i++){
        if(max < arr[i]){
            max = arr[i];
        }
    }
    int count[max+1];
    int output[n];


    // Initialize count with all zeros. SegFaults if omitted
    #pragma omp parallel for schedule(static)
    for (int i = 0; i <= max; i++) {
        count[i] = 0;
    }

    #pragma omp parallel for schedule(static) reduction(+:count[:])
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
         output[count[arr[i]]- 1] = arr[i];
         count[arr[i]]--;
    }

    // Overwrite original array with sorted output. Alternatively as return arr[]
    #pragma omp parallel for schedule(static)
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

#endif