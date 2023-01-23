#include <math.h>
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>
#include <omp.h>
#include <sys/time.h>

#if !defined(OMP_THREADS)
#define OMP_THREADS 2
#endif // OMP_THREADS

#if !defined(N)
#define N 10
#define M 10
#endif 


double MATRIX[M][N];
double MATRIX_ORIG[M][N];
FILE *fp;

void dswap(double *a, double *b) {
    double t = *a;
    *a = *b;
    *b = t;
}

int is_equal_matrix(double arr[M][N], double orig[M][N], int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("arr_orig at %d %d is %f\n", i, j, orig[i][j]);
            printf("arr at %d %d is %f\n", i, j, arr[i][j]);

            if (arr[i][j] != orig[i][j])
            {
                //return 0;
            }
        }
    }
    return 1;
}

void swap_rows(int r1, int r2) {
    for (int i = 0; i < N; i++) {
        dswap(&MATRIX[r1][i], &MATRIX[r2][i]);
    }
}


void fill_with_randoms(){
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            double r = rand() % 10;
            MATRIX[i][j] = r;
            MATRIX_ORIG[i][j] = r;
        }
        
    }
    
}

// https://en.wikipedia.org/wiki/Gaussian_elimination#Pseudocode
void gauss(double matrix[M][N]) {
    int h = 0;
    int k = 0;

    while (h < M && k < N) {

        // Find the k-th pivot:
        int i_max = h;
        for (int i = h; i < M; i++) {
            if (fabs(matrix[i_max][k]) < fabs(matrix[i][k])) {
                i_max = i;
            }
        }

        if (matrix[i_max][k] == 0) {
            k++;
            continue;
        }

        swap_rows(h, i_max);


        #pragma omp parallel for schedule(static) default(none) shared(matrix,h,k) num_threads(OMP_THREADS)
        for (int i = h + 1; i < M; i++) {
            double f = (double) matrix[i][k] / matrix[h][k];

            matrix[i][k] = 0;
            for (int j = k + 1; j < N; j++) {
                matrix[i][j] -= matrix[h][j] * f;
            }
        }


        h++;
        k++;
    }
}

void sequential_gauss(double matrix[M][N]) {
    int h = 0;
    int k = 0;

    while (h < M && k < N) {

        // Find the k-th pivot:
        int i_max = h;
        for (int i = h; i < M; i++) {
            if (fabs(matrix[i_max][k]) < fabs(matrix[i][k])) {
                i_max = i;
            }
        }

        if (matrix[i_max][k] == 0) {
            k++;
            continue;
        }

        swap_rows(h, i_max);


        for (int i = h + 1; i < M; i++) {
            double f = (double) matrix[i][k] / matrix[h][k];

            matrix[i][k] = 0;
            for (int j = k + 1; j < N; j++) {
                matrix[i][j] -= matrix[h][j] * f;
            }
        }

        h++;
        k++;
    }
}

int main() {
    fill_with_randoms();
    sequential_gauss(MATRIX_ORIG);

    struct timeval begin, end;
    gettimeofday(&begin, 0);
    sequential_gauss(MATRIX);
    gettimeofday(&end, 0);
    long seconds = end.tv_sec - begin.tv_sec;
    long microseconds = end.tv_usec - begin.tv_usec;
    double time_spent = seconds + microseconds * 1e-6;

    int status = is_equal_matrix(MATRIX, MATRIX_ORIG, M, N);

    fp = fopen("log/c_std.csv", "a");
    fprintf(fp, "OMP Gauss, %d, %d,%d, %f, %d\n", M,N, OMP_THREADS, time_spent, status);
    fclose(fp);

    return 0;
}