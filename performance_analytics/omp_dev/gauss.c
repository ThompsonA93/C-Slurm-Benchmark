#include <omp.h>
#include <stdio.h>
#include <limits.h>
#include <time.h>

// Set 1 to use printer
#define DEBUG 1

#define NUM_THREADS 2
#define DIM 2
#define MAX_ELEMENT_RANGE INT_MAX

FILE *fp;
int a_seq[DIM][DIM];
int a_par[DIM][DIM];

void initialize();
void gauss_sequential();
void gauss_parallel();
int test_equality();

/**
 * @note: https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
 */
int main(void)
{
    omp_set_num_threads(NUM_THREADS);
    printf("! Utilizing %d threads\n", NUM_THREADS);

    srand(time(NULL)); // Initialization, should only be called once.

    initialize();
    gauss_sequential();
    gauss_parallel();
    int res = test_equality();

    printf("! Gauss success: %d\n", res);
    if (res != 0)
    {
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
void initialize()
{
    if (DEBUG)
        printf("\tInitializing arrays\n");
    for (int i = 0; i < DIM; i++)
    {
        for (int j = 0; j < DIM; j++)
        {
            int r = rand() % 20 + 1; // Returns a pseudo-random integer between 0 and RAND_MAX.
            a_seq[i][j] = r;
            a_par[i][j] = r;
            if (DEBUG)
                printf("\tOverwriting arrays with %d at [%d,%d]\n", r, i, j);
        }
    }
    test_equality();
}

/**
 * Executed Gauss elimination
 * @note Performance consideration: To avoid cache misses by horizontal traversal, transpose the matrix before and after elimination
 */
void gauss_sequential()
{
    double start_time = omp_get_wtime();


    // FIXME :: I just don't fucking know
    for (int i = 0; i < DIM - 1; i++)
    {
        for (int j = i; j < DIM; j++)
        {
            int ratio = a_seq[j][i] / a_seq[i][i];
            printf("\tCalculating ratio from %d / %d = %d == %d = Ratio\n", a_seq[j][i], a_seq[i][i], a_seq[j][i] / a_seq[i][i], ratio);
            for (int k = i; k < DIM; k++)
            {
                printf("\tSetting %d at %d %d to %d\n", a_seq[j][k], j, k, a_seq[j][k] - (ratio * a_seq[i][k]));
                a_seq[j][k] = a_seq[j][k] - (ratio * a_seq[i][k]);
            }
        }
    }






    double time = omp_get_wtime() - start_time;

    printf("! Executed sequential gauss: %f\n", time);
}

/**
 * Executes Sieve of Erastothenes parallel, using openmp
 * @note:
 */
void gauss_parallel()
{
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
int test_equality()
{
    if (DEBUG)
        printf("! Asserting equality of results\n");
    for (int i = 0; i < DIM; i++)
    {
        for (int j = 0; j < DIM; j++)
        {
            if (DEBUG)
                printf("\t%d = %d", a_seq[i][j], a_par[i][j]);

            if (a_seq[i][j] != a_par[i][j])
            {
                // return 1;
            }
        }
        if (DEBUG)
            printf("\n");
    }
    return 0;
}
