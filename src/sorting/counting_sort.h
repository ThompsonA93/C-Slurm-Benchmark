#ifndef BUCKET_SORT
#define BUCKET_SORT

#include "utils_sort.h"

/**
 * Returns highest value of an array 
 * @param arr as array to search
 * @param n as array length
 * @return highest value of an array 
 */
int get_max_value(int arr[], int n){
    int max_element = 0;
    for(int i = 0; i < n; i++){
        if(max_element < arr[i]){
            max_element = arr[i];
        }
    }
    return max_element;
}

/**
 * Implementation for simple counting sort
 * @param arr as arr to sort
 * @param n as amount of elements in the arr
 */
void counting_sort(int arr[], int n){

    // Find the largest element of the arr
    const int max = get_max_value(arr, n);
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