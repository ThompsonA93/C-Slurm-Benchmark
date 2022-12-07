#ifndef INSERTION_SORT
#define INSERTION_SORT

#include "utils_sort.h"

/** Amount of threads to use **/
#ifndef OMP_THREADS
#define OMP_THREADS 2
#endif

/**
 * Implementation for simple quick sort
 * @param arr as array to sort
 * @param n as amount of elements in the array
 */

void insertion_sort(int arr[], int n){
    int cur_el, j;
    for(int i = 1; i < n; i++){
        cur_el = arr[i];

        for(j = i-1; j >= 0 && arr[j] > cur_el; ){
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = cur_el;
    }
}

#endif
