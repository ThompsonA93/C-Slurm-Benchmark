#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <sys/time.h>

#define MAX_VAL 100
#define M 250
#define N 250
#define P 250


FILE *fp;

int a[M][N];
int b[N][P];
int c[M][P];

void initialize_2d_array(){
    printf("Initializing Array with randomized values.\n");
    for(int m = 0; m < M; m++){
        for(int n = 0; n < N; n++){
            for(int p = 0; p < P; p++){
                c[m][p] = 0;
                b[n][p] = rand() % MAX_VAL;
            }
            a[m][n] = rand() % MAX_VAL; 
        }
    }
}

void print_2d_array(int* arr, int x, int y){
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

void multiply_matrices(){
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

    initialize_2d_array();

    print_2d_array(a, M, N);
    print_2d_array(b, N, P);


    // Start measuring time
    struct timeval begin, end;
    gettimeofday(&begin, 0);
    

    multiply_matrices();

    // Stop measuring time and calculate the elapsed time
    gettimeofday(&end, 0);
    long seconds = end.tv_sec - begin.tv_sec;
    long microseconds = end.tv_usec - begin.tv_usec;
    double time_spent = seconds + microseconds*1e-6;


    fp = fopen("log/c_std.log", "a");
    fprintf(fp, "Matrix multiplication, %dx%dx%d, %f, %d\n", M,N,P , time_spent, 1);  // If at this point, likely was successfull hence 1.
    fclose(fp);

    return 0;
}