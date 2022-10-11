#ifndef D1_ARRAY_UTILS
#define D1_ARRAY_UTILS
#include <stdio.h>

#define MAX_ARRAY_ELEMENTS 10000
#define ELEMENT_VALUE_RANGE 10

/**
 * Prints the content of a 1d-array
 * @param arr as passed array
 * @param x as dimension x
 * @attention '0' as array-parameter will cause error
 */
void printArray(int arr[MAX_ARRAY_ELEMENTS], int x){
    printf("Printing array:\n\t");
    for(int i = 0; i < x; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

/**
 * Randomizes the content of a 1d-array
 * @param arr as passed array
 * @param x as dimension x
 * @attention '0' as array-parameter will cause error
 */
void randomizeArray(int arr[MAX_ARRAY_ELEMENTS], int x){
    printf("Randomizing %d array with elements\n\t", x);
    for(int i = 0; i < x; i++){
        int el = rand() % ELEMENT_VALUE_RANGE;
        arr[i] = el;
        printf("%d ", el);
    }
    printf("\n");
}


#endif