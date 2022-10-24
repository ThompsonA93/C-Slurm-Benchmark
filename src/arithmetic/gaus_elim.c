#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <sys/time.h>

#define MAX_INTEGER_RANGE 100
#define M 250
#define N 250

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



    // Start measuring time
    struct timeval begin, end;
    gettimeofday(&begin, 0);

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

    // Stop measuring time and calculate the elapsed time
    gettimeofday(&end, 0);
    long seconds = end.tv_sec - begin.tv_sec;
    long microseconds = end.tv_usec - begin.tv_usec;
    double time_spent = seconds + microseconds*1e-6;

    printf("Printing resulting array.\n");
    for(int m = 0; m < M; m++){
        for(int n = 0; n < N; n++){
            printf("\t%d ", a[m][n]);
        }
        printf("\n");
    }

    fp = fopen("log/c_std.log", "a");
    fprintf(fp, "Gaussian Elimination, %dx%d, %f, %d\n", M, N, time_spent, 1);
    fclose(fp);

    return 0;
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