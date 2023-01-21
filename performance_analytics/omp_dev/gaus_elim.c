#include <omp.h>
#include <stdio.h>
#include <limits.h>

#define NUM_THREADS 2
#define DIM 500
#define MAX_ELEMENT_RANGE INT_MAX

FILE *fp;
int a_seq[DIM][DIM];
int a_par[DIM][DIM];

void initialize(){
    printf("! Initializing arrays using maximum element value %d\n", MAX_ELEMENT_RANGE);
    for(int i = 0; i < DIM; i++){
        for(int j = 0; j < DIM; j++){
            a_seq[i][j] = 0;
            a_par[i][j] = 0; 
        }
    }
}

void gauss_sequential(){
    double start_time = omp_get_wtime();



    for(int k = 0; k < DIM; k++){
        for(int i = 0; i <= DIM; i++){
            int pivot = a_seq[i][k];
            for(int j = 0; j <= DIM; j++){
                if(i != k){
                    int pivot_mult = pivot*a_seq[k][j];
                    int el_mult = a_seq[k][k]*a_seq[i][j];
                    a_seq[i][j] = el_mult-pivot_mult;
                }
            }
        }
    }

    double time = omp_get_wtime() - start_time;
    fp = fopen("log/c_std.csv", "a");
    fprintf(fp, "Gaussian Elimination, %dx%d, %d, %f, %d\n", DIM, DIM, 1, time, 1);
    fclose(fp);

    printf("! Executing sequential gauss: %f\n", time);
}


void gauss_parallel(){
    double start_time = omp_get_wtime();

    // FIXME :: This likely needs major rewriting for performance boosts
    for(int k = 0; k < DIM; k++){             
        for(int i = 0; i <= DIM; i++){
            int pivot = a_par[i][k];
            for(int j = 0; j <= DIM; j++){
                if(i != k){
                    int pivot_mult = pivot*a_par[k][j];
                    int el_mult = a_par[k][k]*a_par[i][j];
                    a_par[i][j] = el_mult-pivot_mult;
                }
            }
        }
    }

    double time = omp_get_wtime() - start_time;
    fp = fopen("log/c_std.csv", "a");
    fprintf(fp, "Gaussian Elimination, %dx%d, %d, %f, %d\n", DIM, DIM, NUM_THREADS, time, 1);
    fclose(fp);

    printf("! Executing parallelized gauss %f\n", time);

}


int test_equality(){
    printf("! Asserting equality of results\n");
    for(int i = 0; i < DIM; i++){
        for(int j = 0; j < DIM; j++){
            if(a_seq[i][j] != a_par[i][j]){
                return 1;
            }
        }
    }
    return 0;
}

int main(void){
    omp_set_num_threads(NUM_THREADS);
    printf("! Utilizing %d threads\n", NUM_THREADS);

    initialize();
    gauss_sequential();
    gauss_parallel();
    int res = test_equality();

    printf("! Gauss success: %d\n", res);
    return 0;
}