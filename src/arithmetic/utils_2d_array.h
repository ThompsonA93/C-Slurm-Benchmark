#ifndef D2_ARRAY_UTILS
#define D2_ARRAY_UTILS
#include <stdio.h>

#define MAX_ARRAY_ELEMENTS 100

/**
 * Prints the content of a 2d-array
 * @param arr as passed array
 * @param x as dimension x
 * @param y as dimension y 
 * @attention '0' as array-parameter will cause error
 */
void printArray(int arr[][MAX_ARRAY_ELEMENTS], int x, int y){
    printf("Printing array:\n\t");
    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n\t");
    }
    printf("\n");
}

/* 
 * Alternative using pointer 
 *
 *//*
void printArray(int* arr, int x, int y){
    printf("Printing array:\n\t");
    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            printf("%d ", *arr);
            arr++;
        }
        printf("\n\t");
    }
    printf("\n");
}
*/

/**
 * Randomizes the content of a 2d-array
 * @param arr as passed array
 * @param x as dimension x
 * @param y as dimension y 
 * @attention '0' as array-parameter will cause error
 */
void randomizeArray(int arr[][MAX_ARRAY_ELEMENTS], int x, int y){
    printf("Randomizing %dx%d array with elements\n\t", x, y);
    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            int el = rand() % 10;
            arr[i][j] = el;
            printf("%d ", el);
        }
        printf("\n\t");
    }
    printf("\n");
}

/* 
 * Alternative using pointer 
 *
 *//*
void randomize(int* arr, int x, int y){
    printf("Randomizing %dx%d array\n", x, y);
    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            *arr = rand() % 10;
            arr++;
        }
    }
}
*/

#endif