#ifndef BUCKET_SORT
#define BUCKET_SORT

#include "utils_sort.h"
#include "insertion_sort.h"
#include "utils_1d_array.h"

/** Amount of threads to use **/
#ifndef OMP_THREADS
#define OMP_THREADS 2
#endif

/**
 * Approximates square root for given value
 * @see https://en.wikipedia.org/wiki/Integer_square_root#Algorithm_using_linear_search
 * @param value as parameter to sqrt
 * @return square root of value, rounded down
 */
int isqrt(int value)
{
    int res = 0;
    while ((res + 1) * (res + 1) <= value)
    {
        res += 1;
    }
    return res;
}

/**
 * Implementation for simple bucket sort
 * @param arr as array to sort
 * @param n as amount of elements in the array
 * 
 * Parallelization: https://www.sjsu.edu/people/robert.chun/courses/cs159/s3/N.pdf
 */
void bucket_sort(int arr[], int n)
{

    int bucket_count = (isqrt(n));
    int bucket_interval = n / bucket_count;

    // Increase offset in order not to lose any values
    while (bucket_count * bucket_interval < n)
    {
        bucket_interval += 1;
    }

    int buckets[bucket_count][bucket_interval*2]; // how should be best assign the size of each bucket??
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

    //printf("bucket_count: %d,  max: %d\n", bucket_count, max);
    // Create buckets
    for (int i = 0; i < n; i++)
    {
        int bucket_index = (bucket_count * arr[i]) / (max);
        buckets[bucket_index][bucket_index_count[bucket_index]] = arr[i];
        bucket_index_count[bucket_index]++;
        ////printf("Inserting value  %d, into bucket %d, bucket size new: %d\n", arr[i], ((bucket_count * arr[i]) / (max)), bucket_index_count[bucket_index]);
    }
    int arr_index = 0;

    for (int i = 0; i < bucket_count; i++)
    {
        insertion_sort(buckets[i], bucket_index_count[i]);
        for (int j = 0; j < bucket_index_count[i]; j++)
        {
            arr[arr_index] = buckets[i][j];
            arr_index++;
        }
    }
}

#endif