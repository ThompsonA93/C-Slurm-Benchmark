#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <omp.h>
#include <string.h>

#include "utils_1d_array.h"
#include "utils_sort.h"
#include "brick_sort.h"

FILE *fp;
int arr[MAX_ARRAY_ELEMENTS];

int main(void){
    srand(time(NULL));  // Initialization for randomization process
                        // Should only be called once.

    //print_array(arr, MAX_ARRAY_ELEMENTS);
    randomize_array(arr, MAX_ARRAY_ELEMENTS);
    //print_array(arr, MAX_ARRAY_ELEMENTS);
    
    int orig[MAX_ARRAY_ELEMENTS];
    memcpy(orig, arr, MAX_ARRAY_ELEMENTS*sizeof(int));

    // Start measuring time
    struct timeval begin, end;
    gettimeofday(&begin, 0);
    
    brick_sort(arr, MAX_ARRAY_ELEMENTS);

    // Stop measuring time and calculate the elapsed time
    gettimeofday(&end, 0);
    long seconds = end.tv_sec - begin.tv_sec;
    long microseconds = end.tv_usec - begin.tv_usec;
    double time_spent = seconds + microseconds*1e-6;

    //print_array(arr, MAX_ARRAY_ELEMENTS);

    int status = is_sorted(arr,orig, MAX_ARRAY_ELEMENTS);
    if(status){
        printf("! Sorting array was successfull.\n");
    }else{
        printf("! Sorting array was not successfull.\n");
    }

    const char* nthreads = getenv("OMP_NUM_THREADS");

    printf("AAAAAAAAAA: %s", nthreads);

    fp = fopen("log/c_std.log", "a");
    fprintf(fp, "Brick Sort, %d, %s, %f, %d\n", MAX_ARRAY_ELEMENTS, nthreads, time_spent, status);
    fclose(fp);

}
