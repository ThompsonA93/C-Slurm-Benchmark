#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_INTEGER_RANGE 255
#define M 5
#define N 5

int a[M][N];

FILE *fp;

int main(void){
    srand(time(NULL));  // Initialization for randomization process
                        // Should only be called once.
    printf("Initiating Array.\n");
    for(int m = 0; m < M; m++){
        for(int n = 0; n < N; n++){
            a[m][n] = rand() % MAX_INTEGER_RANGE;
            printf("\t%d ", a[m][n]);
        }
        printf("\n");
    }

    printf("Executing Gauss-Jordan Elimination.\n");
    for(int k = 0; k < M; k++){
        for(int i = 0; i <= M; i++){
            int pivot = a[i][k];
            printf("\tUsing Pivot %d at a[%d][%d]\n", pivot, i, k);
            for(int j = 0; j <= M; j++){
                printf("\t\tChecking row %d = %d\n", i, k);
                if(i != k){
                    int pivot_mult = pivot*a[k][j];
                    int el_mult = a[k][k]*a[i][j];
                    a[i][j] = el_mult-pivot_mult;
                    printf("\t\tCalculating: %d * %d = %d\n", pivot_mult, el_mult, a[i][j]);
                }
            }
        }
    }

    printf("Printing resulting array.\n");
    for(int m = 0; m < M; m++){
        for(int n = 0; n < N; n++){
            printf("\t%d ", a[m][n]);
        }
        printf("\n");
    }

}

/* Bugs the array to 0 on higher dimensions for some reasons. Keeping for reference.
    printf("Executing Gauss-Jordan Elimination.\n");
    for(int k = 0; k < M; k++){
        for(int i = 0; i <= M; i++){
            int pivot = a[i][k];
            printf("\tUsing Pivot %d at a[%d][%d]\n", pivot, i, k);
            for(int j = 0; j <= M; j++){
                printf("\t\tChecking row %d = %d\n", i, k);
                if(i != k){
                    int pivot_mult = pivot*a[k][j];
                    int el_mult = a[k][k]*a[i][j];
                    a[i][j] = el_mult-pivot_mult;
                    printf("\t\tCalculating: %d * %d = %d\n", pivot_mult, el_mult, a[i][j]);
                }
            }
        }
    }
*/