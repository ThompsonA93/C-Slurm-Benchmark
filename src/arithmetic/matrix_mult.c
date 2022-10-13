#include <stdlib.h>
#include <time.h>

#include "utils_2d_array.h"

/**
 * FIXME Requires some major refactoring
 * - Focus on sorting algorithms for now
 */


// Multiplication of m x n * n x p produces m x p 
// <=> a_y = b_x !
#define M 2
#define N 3
#define P 2

int a[M][N];
int b[N][P];
int c[M][P];

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
void multiply_2d_array(int a[][MAX_ARRAY_ELEMENTS], int a_x, int a_y, int b[][MAX_ARRAY_ELEMENTS], int b_x, int b_y){
    printf("Multiplying %dx%d with %dx%d array to generate %dx%d array\n", a_x, a_y, b_x, b_y, a_x, b_y);

    // For each row of array 1
      // For each column of array 2
        // For each row of array 2 (= the element)
          // Do something
    for(int i = 0; i < a_x; i++){
        for(int j = 0; j < b_y; j++){
            c[i][j] = 0; // FIXME :: Otherwise bugs?
            for(int k = 0; k < b_x; k++){
                c[i][j] += a[i][k] * b[k][j];
                printf("\n\tc[%d][%d] += a[%d][%d] * b[%d][%d] ... %d * %d = %d", i,j,i,k,k,j, a[i][k], b[k][j], c[i][j]);
            }
        }
    }
    printf("\n"); 
}

/**
 * Main entry point. Multiplies 2 matrices a,b as specified in global scope, stores result in c.
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

    randomizeArray(a, a_x, a_y);
    randomizeArray(b, b_x, b_y);

    printArray(a, a_x, a_y);
    printArray(b, b_x, b_y);

    multiply_2d_array(a, a_x, a_y, b, b_x, b_y);
    printArray(c, a_x, b_y);

    return 0;
}

