#ifndef QUICK_SORT
#define QUICK_SORT

#include "utils_sort.h"



/*
 * FIXME not quite working
 */
int assemblePartition(int arr[], int low, int high){
    int pt = low;
    for(int i = low; i < high; i++){
        if(arr[i] <= arr[high]){
            printf("\tSwapping %d with %d\n", arr[pt], arr[i]);
            swap(&arr[pt], &arr[i]);
        }
    }
    return pt;
}

/**
 * Implementation for simple quick sort
 * @param arr as array to sort
 * @param p1 as partition point 1 (lower limit)
 * @param p2 as partition point 2 (higher limit)
 */
void quickSort(int arr[], int p1, int p2){
    if(p1 < p2){
        int pt = assemblePartition(arr, p1, p2);
        quickSort(arr, p1, pt-1);
        quickSort(arr, pt+1, p2);
    }
}

#endif