#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

// Set 1 to use printer
#define DEBUG 0

#ifndef THREADS
#define THREADS 1
#endif

#ifndef DIM
#define DIM 10
#endif

FILE *fp;
int a_seq[DIM];
int a_par[DIM];

void initialize();
void quick_sequential();
void quick_parallel();
int test_equality();

static int chunksize = 10;
/**
 * @note: https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
 */
int main(void)
{
    omp_set_num_threads(THREADS);
    printf("! Utilizing %d threads over %d elements\n", THREADS, DIM);

    initialize();

    double start_time, time;
    start_time = omp_get_wtime();
    quick_sequential(a_seq, 0, DIM - 1);
    time = omp_get_wtime() - start_time;
    printf("! Executed sequential quicksort: %f\n", time);

    start_time = omp_get_wtime();
    chunksize = DIM / THREADS;
    #pragma omp parallel
    {
        #pragma omp single
        quick_parallel(a_par, 0, DIM - 1);
    }

    time = omp_get_wtime() - start_time;
    printf("! Executed parallelized quicksort: %f\n", time);

    int res = test_equality();
    printf("! Quicksort exit: %d\n", res);
    if (res != 0)
    {
        fp = fopen("log/c_std.csv", "a");
        fprintf(fp, "Quicksort error: Parallel and Sequential results differ.");
        fclose(fp);
    }
    else
    {
        fp = fopen("log/c_std.csv", "a");
        fprintf(fp, "Quicksort, %d, %d, %f\n", DIM, THREADS, time);
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
        int r = rand() % 20 + 1; // Returns a pseudo-random integer between 0 and RAND_MAX.
        a_seq[i] = r;
        a_par[i] = r;
        if (DEBUG)
            printf("\tOverwriting arrays with %d at %d\n", i, r);
    }
}

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quick_sequential(int arr[], int low, int high)
{
    if (low < high)
    {
        int pt = partition(arr, low, high);
        quick_sequential(arr, low, pt - 1);
        quick_sequential(arr, pt + 1, high);
    }
}

/**
 * Src.: https://stackoverflow.com/questions/68502197/how-do-omp-single-and-omp-task-provide-parallelism
 * 
 * First, when encountering the parallel construct, the main thread spawns the parallel region and creates a bunch of worker threads. 
 *  Then you have n threads running and executing the parallel region.
 * Second, the single construct picks any one of the n threads and executes the code inside the curly braces of the single construct. 
 *  All other n-1 threads will proceed to the barrier in line 10. 
 *  There, they will wait for the last thread to catch up and complete the barrier synchronization. 
 *  While these threads are waiting there, they are not only wasting time but also wait for work to arrive.
 * Third, the thread that was picked by the single construct (the "producer") executes the for loop and for each iteration it creates a new task. 
 *  This task is then put into a task pool so that another thread (one of the ones in the barrier) can pick it up and execute it. 
 *  Once the producer is done creating tasks, it will join the barrier and if there are still tasks in the task pool waiting for execution, it will help the other threads execute tasks.
 * Fourth, once all tasks have been generated and executed that way, all threads are done and the barrier synchronization is complete.
 * 
 * **/
void quick_parallel(int arr[], int low, int high)
{
    /*
    if (low < high)
    {
        int pt = partition(arr, low, high);
        #pragma omp parallel sections
        {
            #pragma omp section
            quick_sequential(arr, low, pt - 1);
            #pragma omp section
            quick_sequential(arr, pt + 1, high);
        }
    }
    */
    if (low < high)
    {
        int pt = partition(arr, low, high);
        #pragma omp task shared(arr) //if(high-low > chunksize)
        quick_parallel(arr, low, pt - 1);
        #pragma omp task shared(arr) //if(high-low > chunksize)
        quick_parallel(arr, pt + 1, high);
    }


}

/**
 * Compare each element of a_seq and a_par.
 * @return 1 immediately if a mismatch was detected. Otherwise 0.
 */
int test_equality()
{
    if (DEBUG)
        printf("! Asserting equality of results\n");
    if (DEBUG)
        printf("\ta_seq\t|\ta_par\n");
    for (int i = 0; i < DIM; i++)
    {
        if (DEBUG)
            printf("%d\t%d\t|\t %d\n", i, a_seq[i], a_par[i]);
        if (a_seq[i] != a_par[i])
        {
            return 1;
        }
    }
    return 0;
}