#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define M 30
#define N 30
#define P 30

FILE *fp;

int a[M][N];
int b[N][P];
int c[M][P];

void initialize2DArray(){
    printf("Initializing Array with randomized values.\n");
    for(int m = 0; m < M; m++){
        for(int n = 0; n < N; n++){
            for(int p = 0; p < P; p++){
                c[m][p] = 0;
                b[n][p] = rand() % 10;
            }
            a[m][n] = rand() % 10; 
        }
    }
}

void print2DArray(int* arr, int x, int y){
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

void multiplyMatrices(){
    printf("Multiplying matrices.\n");
    for(int i = 0; i < M; i++){
        for(int j = 0; j < P; j++){
            for(int k = 0; k < N; k++){
                c[i][j] += a[i][k] * b[k][j];
                printf("\tc[%d][%d] += a[%d][%d] * b[%d][%d] ... %d * %d = %d\n", i,j,i,k,k,j, a[i][k], b[k][j], c[i][j]);
            }
            printf("\t\tc[%d][%d] = %d\n", i, j, c[i][j]);
        }
    }
}

int main(void){
    srand(time(NULL));  // Initialization for randomization process
                        // Should only be called once.

    initialize2DArray();

    print2DArray(a, M, N);
    print2DArray(b, N, P);


    double time_spent = 0.0;
    clock_t begin = clock();
    multiplyMatrices();
    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;

    fp = fopen("log/c_std.log", "a");
    fprintf(fp, "Matrix multiplication, %dx%dx%d, %f, %d\n", M,N,P , time_spent, 1);  // If at this point, likely was successfull hence 1.
    fclose(fp);

    return 0;
}