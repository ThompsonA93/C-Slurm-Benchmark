#ifndef OMP_INSERTION_SORT
#define OMP_INSERTION_SORT

#include <omp.h>
#include "../utils/utils_sort.h"

/** Amount of threads to use **/
#ifndef OMP_THREADS
#define OMP_THREADS 2
#endif

// insertion sort effectively evolves into a bucket sort variant

/**
 * Implementation for simple insertion sort using OpenMP Pragmas
 * @param arr as array to sort
 * @param n as amount of elements in the array
 */
void omp_insertion_sort(int arr[], int n)
{

    int cur_el, j;

    // Not parallelizable
    //#pragma omp parallel for schedule(static)
    for(int i = 1; i < n; i++){
        cur_el = arr[i];
        for(j = i-1; j >= 0 && arr[j] > cur_el; ){
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = cur_el;
    }
    
    /*
    int bucket_count = OMP_THREADS;
    int bucket_interval = n / bucket_count;

    // Increase offset in order not to lose any values
    while (bucket_count * bucket_interval < n)
    {
        bucket_interval += 1;
    }

    int buckets[bucket_count][n]; // how should be best assign the size of each bucket??
    int bucket_index_count[bucket_count];
    for (int i = 0; i < bucket_count; i++)
        bucket_index_count[i] = 0;

    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }
    max++;

    // printf("bucket_count: %d,  max: %d\n", bucket_count, max);
    //  Create buckets

    for (int i = 0; i < n; i++)
    {
        int bucket_index = (bucket_count * arr[i]) / (max);
        buckets[bucket_index][bucket_index_count[bucket_index]] = arr[i];
        bucket_index_count[bucket_index]++;
        ////printf("Inserting value  %d, into bucket %d, bucket size new: %d\n", arr[i], ((bucket_count * arr[i]) / (max)), bucket_index_count[bucket_index]);
    }

    int cur_el, j;
    #pragma omp parallel for schedule(static) private(cur_el,j)
    for (int b = 0; b < bucket_count; b++)
    {
        for (int i = 1; i < bucket_index_count[b]; i++)
        {
            cur_el = buckets[b][i]; 

            j = i - 1;
            while (j >= 0 && buckets[b][j] > cur_el)
            {                        
                buckets[b][j + 1] = buckets[b][j]; 
                j = j - 1;
            }

            buckets[b][j + 1] = cur_el; 
        }
    }

    int arr_index = 0;
    for (int i = 0; i < bucket_count; i++)
    {
        for (int j = 0; j < bucket_index_count[i]; j++) 
        {
            arr[arr_index] = buckets[i][j];
            arr_index++;
        }
    }
    */
}

#endif
