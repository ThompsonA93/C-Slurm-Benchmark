#ifndef UTILS_1D_ARRAY
#define UTILS_1D_ARRAY
#include <stdio.h>

/** Highest allowed value per array element**/
#ifndef ELEMENT_VALUE_RANGE
#define ELEMENT_VALUE_RANGE 100
#endif

/** Length of arrays to use **/
#ifndef MAX_ARRAY_ELEMENTS
#define MAX_ARRAY_ELEMENTS 25000
#endif


/**
 * Prints the content of a 1d-array
 * @param arr as passed array
 * @param x as dimension x
 * @attention '0' as array-parameter will cause error
 */
void print_array(int arr[MAX_ARRAY_ELEMENTS], int x){
    //printf("Printing array:\n\t");
    for(int i = 0; i < x; i++){
        //printf("%d ", arr[i]);
    }
    //printf("\n");
}

/**
 * Randomizes the content of a 1d-array
 * @param arr as passed array
 * @param x as dimension x
 * @attention '0' as array-parameter will cause error
 */
void randomize_array(int arr[MAX_ARRAY_ELEMENTS], int x){
    //printf("Randomizing %d array with elements\n\t", x);
    for(int i = 0; i < x; i++){
        int el = rand() % ELEMENT_VALUE_RANGE;
        arr[i] = el;
        //printf("%d ", el);
    }
    //printf("\n");
}


#endif