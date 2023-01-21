#include <omp.h>
#include <stdio.h>
#include <limits.h>

// Set 1 to use printer
#define DEBUG 0

#define NUM_THREADS 2
#define DIM 100000000
#define MAX_ELEMENT_RANGE INT_MAX

FILE *fp;
int a_seq[DIM];
int a_par[DIM];

void initialize();
int isqrt(int value);
void sieve_sequential();
void sieve_parallel();
int test_equality();

/**
 * @note: https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
 * 
 * Given an integer n > 1 (DIM), let A be an array of boolean values (0 || 1) indexed by n.
 * Initialize all boolean values to true
 * 
 * Despite convention, assume 0 is true
 * @dev: Fails to complete initialization on 1, FIXME
 */
int main(void){
    omp_set_num_threads(NUM_THREADS);
    if(DEBUG) printf("! Utilizing %d threads\n", NUM_THREADS);

    initialize();
    sieve_sequential();
    sieve_parallel();
    int res = test_equality();

    if(DEBUG) printf("! Gauss success: %d\n", res);
    return 0;
}




void initialize(){
    if(DEBUG) printf("! Initializing arrays\n");
    for(int i = 0; i < DIM; i++){
        if(DEBUG) printf("\tOverwriting arrays with 0 at %d\n", i);
        a_seq[i] = 0;
        a_par[i] = 0;
    }
}





int isqrt(int value){
    int res = 0;
    while ((res + 1) * (res + 1) <= value)
    {
        res = res + 1;
        if(DEBUG) printf("\tRunning sqrt: %d\n", res);
    }
    if(DEBUG) printf("\tSQRT(%d) = %d\n", DIM, res);
    return res;
}





/**
 *  O(n log(log(n)))
 * 
 *  for i = 2, 3, 4, ..., not exceeding √n do
 *      if A[i] is true
 *          for j = i2, i2+i, i2+2i, i2+3i, ..., not exceeding n do
 *              set A[j] := false
 * 
 * FIXME :: J is not getting updated ?
*/
void sieve_sequential(){
    if(DEBUG) printf("! Executing sequential sieve.\n");
    double start_time = omp_get_wtime();


    int limit = isqrt(DIM);
    for(int i = 2; i < limit; i++){
        if(DEBUG) printf("\tIterating at %d\n", i);
        if(a_seq[i] == 0){
            int count = 0;
            for(int j = i*i+i*count; i*i+i*count < DIM; count++){
                a_seq[i*i+i*count] = 1;
                if(DEBUG) printf("\t\t%d is not prime.\n", i*i+i*count );
            }
        }
    }


    double time = omp_get_wtime() - start_time;
    
    fp = fopen("log/c_std.csv", "a");
    fprintf(fp, "Sieve of Erastothenes, %d, %d, %f, %d\n", DIM, 1, time, 1);
    fclose(fp);

    if(DEBUG) printf("! Executing sequential sieve: %f\n", time);
}





void sieve_parallel(){
    double start_time = omp_get_wtime();

    int limit = isqrt(DIM);
    for(int i = 2; i < limit; i++){
        if(DEBUG) printf("\tIterating at %d\n", i);
        if(a_par[i] == 0){
            int count = 0;
            for(int j = i*i+i*count; i*i+i*count < DIM; count++){
                a_par[i*i+i*count] = 1;
                if(DEBUG) printf("\t\t%d is not prime.\n", i*i+i*count );
            }
        }
    }

    double time = omp_get_wtime() - start_time;
    fp = fopen("log/c_std.csv", "a");
    fprintf(fp, "Sieve of Erastothenes, %d, %d, %f, %d\n", DIM, NUM_THREADS, time, 1);
    fclose(fp);

    if(DEBUG) printf("! Executing parallelized sieve: %f\n", time);
}





int test_equality(){
    if(DEBUG) printf("! Asserting equality of results\n");
    if(DEBUG) printf("\ta_seq\t|\ta_par\n");
    for(int i = 0; i < DIM; i++){
        if(DEBUG) printf("%d\t%d\t|\t %d\n", i, a_seq[i], a_par[i]);
        if(a_seq[i] != a_par[i]){
            return 1;
        }
    }
    return 0;
}









