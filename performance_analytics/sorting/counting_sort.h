#ifndef COUNTING_SORT
#define COUNTING_SORT

#include "../utils/utils_sort.h"

/**
 * Implementation for simple counting sort
 * @param arr as arr to sort
 * @param n as amount of elements in the arr
 */
void counting_sort(int arr[], int n){

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
    for (int i = 0; i <= max; i++) {
        count[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        int j = arr[i];
        count[j] -= 1;
        output[count[j]] = arr[i];
    }

    // Overwrite original array with sorted output. Alternatively as return arr[]
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}



#endif