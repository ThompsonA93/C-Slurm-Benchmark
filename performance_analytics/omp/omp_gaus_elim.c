#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include "../utils/utils_sort.h"
#include "../utils/utils_1d_array.h"


#ifndef OMP_THREADS
#define OMP_THREADS 2
#endif

#ifndef MAX_ELEMENT_RANGE
#define MAX_ELEMENT_RANGE 100
#endif

#ifndef M
#define M 125
#endif

#ifndef N
#define N 125
#endif

int a[M][N];
int b[M][N];

FILE *fp;


void initialize() {
    for(int i = 0; i < M; i++){
        for(int j = 0;  j < M; j++){
            int r  = rand() % 100;
            a[i][j] = r;
            b[i][j] = r;
        }
    }
}

void gauss_sequential(){
    int h = 0;
    int k = 0;

    while (h < M && k < M) {
        int i_max = h;
        for (int i = h; i < M; i++) {
            if (fabs(a[i_max][k]) < fabs(a[i][k])) {
                i_max = i;
            }
        }

        if (a[i_max][k] == 0) {
            k++;
            continue;
        }

        for (int i = 0; i < M; i++) {
            dswap(&a[h][i], &a[i_max][i]);
        }

        for (int i = h + 1; i < M; i++) {
            double f = (double) a[i][k] / a[h][k];

            a[i][k] = 0;
            for (int j = k + 1; j < M; j++) {
                a[i][j] -= a[h][j] * f;
            }
        }

        h++;
        k++;
    }
}

void gauss_parallel() {
    int h = 0;
    int k = 0;

    while (h < M && k < M) {

        // Find the k-th pivot:
        int i_max = h;
        for (int i = h; i < M; i++) {
            if (fabs(b[i_max][k]) < fabs(b[i][k])) {
                i_max = i;
            }
        }

        if (b[i_max][k] == 0) {
            k++;
            continue;
        }

        for (int i = 0; i < M; i++) {
            dswap(&b[h][i], &b[i_max][i]);
        }

        #pragma omp parallel for schedule(static) default(none) shared(b) firstprivate(h, k)
        for (int i = h + 1; i < M; i++) {
            double f = (double) b[i][k] / b[h][k];

            b[i][k] = 0;
            for (int j = k + 1; j < M; j++) {
                b[i][j] -= b[h][j] * f;
            }
        }

        h++;
        k++;
    }
}


int test_equality()
{
   
    for (int i = 0; i < M; i++)
    {
        for(int j = 0; j < N; j++){
            if (a[i][j] != b[i][j])
            {
                return 1;
            }
        }
    }

    return 0;
}

int main() {
    omp_set_num_threads(OMP_THREADS);
    printf("! Utilizing %d threads over %d elements\n", OMP_THREADS, M);

    initialize();
    srand(time(0));
    double start_time, time;

    start_time = omp_get_wtime();
    gauss_sequential();
    time = omp_get_wtime() - start_time;
    printf("! Executed sequential Gauss: %f\n", time);

    start_time = omp_get_wtime();
    gauss_parallel();
    time = omp_get_wtime() - start_time;
    printf("! Executed parallelized Gauss: %f\n", time);


    int res = test_equality();
    printf("! Gauss exit: %d\n", res);
    if (res != 0)
    {
        fp = fopen("log/c_std.csv", "a");
        fprintf(fp, "Gauss error: Parallel and Sequential results differ.");
        fclose(fp);
    }
    else
    {
        fp = fopen("log/c_std.csv", "a");
        fprintf(fp, "Gauss, %d, %d, %f\n", M, OMP_THREADS, time);
        fclose(fp);
    }


    return 0;
}