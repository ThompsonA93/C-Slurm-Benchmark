#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_INTEGER_RANGE 254
#define M 3
#define N 3


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
    int i = 0, j = 0;

    while(i <= M && j <= N){
        int pivot = 1;
        

        i++; j++;
    }
    
}