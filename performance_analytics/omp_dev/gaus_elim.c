#include <omp.h>
#include <stdio.h>
#include <limits.h>
#include <time.h>

// Set 1 to use printer
#define DEBUG 1

#define NUM_THREADS 2
#define DIM 3
#define MAX_ELEMENT_RANGE INT_MAX

FILE *fp;
int a_seq[DIM][DIM];
int a_par[DIM][DIM];

void initialize();
void gauss_sequential();
void gauss_parallel();
void transpose_matrix();
int test_equality();


/**
 * @note: https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
 */
int main(void){
    omp_set_num_threads(NUM_THREADS);
    printf("! Utilizing %d threads\n", NUM_THREADS);

    srand(time(NULL));   // Initialization, should only be called once.
    
    initialize();
    gauss_sequential();
    gauss_parallel();
    int res = test_equality();

    printf("! Gauss success: %d\n", res);
    if(res != 0){
        fp = fopen("log/c_std.csv", "a");
        fprintf(fp, "Gauss error: Parallel and Sequential results differ.");
        fclose(fp);
    }
    return 0;
}



/**
 * Given an integer n > 1 (DIM), let A be an array of boolean values (0 || 1) indexed by n.
 * Initialize all boolean values to true
 * 
 * @Note: Despite convention, assumed that 0 is true (FIXME)
 */
void initialize(){
    if(DEBUG) printf("\tInitializing arrays\n");
    for(int i = 0; i < DIM; i++){
        for(int j = 0; j < DIM; j++){
            int r = rand() % 9 + 1;      // Returns a pseudo-random integer between 0 and RAND_MAX.
            a_seq[i][j] = r;
            a_par[i][j] = r;
            if(DEBUG) printf("\tOverwriting arrays with %d at [%d,%d]\n", r, i,j);
        }
    }
}

/**
 * Transposes a matrix using XOR-swap 
 */
void transpose_matrix(){
    printf("\tTransposing Matrices\n");
    for(int i = 0; i < DIM; i++){
        for(int j = i; j < DIM; j++){
            // Swap i,j with j,i
            if(a_seq[i][j] != a_seq[j][i]){
                a_seq[i][j] ^= a_seq[j][i];
                a_seq[j][i] ^= a_seq[i][j];
                a_seq[i][j] ^= a_seq[j][i];
            }
            if(a_par[i][j] != a_par[j][i]){
                a_par[i][j] ^= a_par[j][i];
                a_par[j][i] ^= a_par[i][j];
                a_par[i][j] ^= a_par[j][i];

            }
        }
    }

}

/**
 * Executed Gauss elimination
 * @note Performance consideration: To avoid cache misses by horizontal traversal, transpose the matrix before and after elimination 
 */
void gauss_sequential(){
    double start_time = omp_get_wtime();

    // @note: We consider transponing matrix as part of the algorithm.
    transpose_matrix();


    /** TODO :: Tomorrow **/
    for(int i = 0; i < DIM; i++){
        printf("\tSelecting element %d = a_seq[%d][%d]\n", a_seq[i][i], i, i);
        

        for(int j = i; j < DIM; j++){
            printf("\t\tSubselecting element %d\n", a_seq[i][j]);
        }


    }

    //transpose_matrix();
    double time = omp_get_wtime() - start_time;

    printf("! Executed sequential gauss: %f\n", time);
}




/**
 * Executes Sieve of Erastothenes parallel, using openmp
 * @note: 
 */
void gauss_parallel(){
    double start_time = omp_get_wtime();





    double time = omp_get_wtime() - start_time;
    fp = fopen("log/c_std.csv", "a");
    fprintf(fp, "Gauss, %d, %d, %f\n", DIM, NUM_THREADS, time);
    fclose(fp);

    printf("! Executed parallelized gauss: %f\n", time);
}



/**
 * Compare each element of a_seq and a_par. 
 * @return 1 immediately if a mismatch was detected. Otherwise 0.
 */
int test_equality(){
    if(DEBUG) printf("! Asserting equality of results\n");
    for(int i = 0; i < DIM; i++){
        for(int j = 0; j < DIM; j++){
            if(DEBUG) printf("\t%d = %d", a_seq[i][j], a_par[i][j]);
            if(a_seq[i][j] != a_par[i][j]){
                return 1;
            }

        }
        if(DEBUG) printf("\n");
    }
    return 0;
}









