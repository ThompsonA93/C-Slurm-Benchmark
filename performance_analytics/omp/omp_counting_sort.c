#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <omp.h>
#include <string.h>

#include "omp_counting_sort.h"

#include "../utils/utils_1d_array.h"
#include "../utils/utils_sort.h"
#include "../sorting/quick_sort.h"

FILE *fp;
int arr[MAX_ARRAY_ELEMENTS];

/**
 *
 */
int main(void){
    srand(time(NULL));  // Initialization for randomization process
                        // Should only be called once.
    //print_array(arr, MAX_ARRAY_ELEMENTS);
    randomize_array(arr, MAX_ARRAY_ELEMENTS);
    //print_array(arr, MAX_ARRAY_ELEMENTS);

    // Copy and sort array for later comparison
    int orig[MAX_ARRAY_ELEMENTS];
    memcpy(orig, arr, MAX_ARRAY_ELEMENTS*sizeof(int));
    quick_sort(orig, 0, MAX_ARRAY_ELEMENTS-1);

    // Start measuring time
    struct timeval begin, end;
    gettimeofday(&begin, 0);

    omp_counting_sort(arr, MAX_ARRAY_ELEMENTS);

    // Stop measuring time and calculate the elapsed time
    gettimeofday(&end, 0);
    long seconds = end.tv_sec - begin.tv_sec;
    long microseconds = end.tv_usec - begin.tv_usec;
    double time_spent = seconds + microseconds*1e-6;

    //print_array(arr, MAX_ARRAY_ELEMENTS);
    
    int status = is_equal(arr, orig, MAX_ARRAY_ELEMENTS);
    if(status){
        printf("! Sorting array was successfull.\n");
    }else{
        printf("! Sorting array was not successfull.\n");
    }
    
    fp = fopen("log/c_std.log", "a");
    fprintf(fp, "OMP Counting Sort, %d, %f, %d\n", MAX_ARRAY_ELEMENTS, time_spent, status);
    fclose(fp);
}