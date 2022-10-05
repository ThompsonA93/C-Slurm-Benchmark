#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ARRAY_ELEMENTS 100

// Rows x Columns
int a[1][3];
int b[3][1];

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
void randomize(int arr[][MAX_ARRAY_ELEMENTS], int x, int y){
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

/**
 * Multiply 2 2d-arrays, interpreted as pointers
 * @param a as first matrix
 * @param a_x as x-dimension of a
 * @param a_y as y-dimension of a
 * @param b as second matrix
 * @param b_x as x-dimension of b
 * @param b_y as y-dimension of b
 * @return a new matrix c = a x b
 */
int* multiply_2d_array(int a[][MAX_ARRAY_ELEMENTS], int a_x, int a_y, int b[][MAX_ARRAY_ELEMENTS], int b_x, int b_y){

    printf("Multiplying %dx%d with %dx%d array\n", a_x, a_y, b_x, b_y);

    int c[a_y][b_x];


    // For each row of array 1
      // For each column of array 2
        // For each row of array 2 (= the element)
          // Do something


    for(int i = 0; i < a_x; i++){
        for(int j = 0; j < b_y; j++){
            for(int k = 0; k < b_x; k++){


            }
        }
    }



}

/**
 * Main entry point. Multiplies 2 matrices a,b as specified in global scope.
 * @return 0 on success, 1 on error
 */
int main(void){
    srand(time(NULL));  // Initialization for randomization process
                        // Should only be called once.

    int a_x = sizeof(a)/sizeof(a[0]);
    int a_y = sizeof(a[0])/sizeof(a[0][0]);
    printf("a_x: %d\ta_y: %d\n", a_x, a_y);

    int b_x = sizeof(b)/sizeof(b[0]);
    int b_y = sizeof(b[0])/sizeof(b[0][0]);
    printf("b_x: %d\tb_y: %d\n", b_x, b_y);

    printArray(a, a_x, a_y);
    printArray(b, b_x, b_y);

    randomize(a, a_x, a_y);
    randomize(b, b_x, b_y);

    printArray(a, a_x, a_y);
    printArray(b, b_x, b_y);

    int c = multiply_2d_array(a, a_x, a_y, b, b_x, b_y);
    
    return 0;
}

