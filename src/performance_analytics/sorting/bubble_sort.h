#ifndef BUBBLE_SORT
#define BUBBLE_SORT

#include "utils_sort.h"

/**
 * Implementation for simple bubble sort
 * @param arr as array to sort
 * @param n as amount of elements in the array
 */
void bubble_sort(int arr[], int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - 1; j++ ){
            if(arr[j] > arr[j+1]){
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}


#endif