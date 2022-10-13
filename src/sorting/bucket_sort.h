#ifndef BUCKET_SORT
#define BUCKET_SORT

#include "utils_sort.h"


/**
 * Approximates square root for given value
 * @see https://en.wikipedia.org/wiki/Integer_square_root#Algorithm_using_linear_search
 * @param value as parameter to sqrt
 * @return square root of value, rounded down
 */
int isqrt(int value){
    int res = 0;
    while((res + 1) * (res + 1) <= value){
        res += 1;
    }
    return res;
}


/**
 * Implementation for simple bucket sort
 * @param arr as array to sort
 * @param n as amount of elements in the array
 */
void bucketSort(int arr[], int n){
    
    int bucket_count = (isqrt(n));
    int bucket_interval = n / buckets;

    // Increase offset in order not to lose any values
    while( buckets*bucket_interval < n){
        bucket_interval+=1;
    }

    printf("Using %d Buckets over intervals of %d for %d elements\n", bucket_count, bucket_interval, MAX_ARRAY_ELEMENTS);
    
}


#endif