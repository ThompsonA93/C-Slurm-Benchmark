#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "utils_1d_array.h"
#include "utils_sort.h"
#include "counting_sort.h"
FILE *fp;
int arr[MAX_ARRAY_ELEMENTS];

/**
 * FIXME -- For some reason, time required shows as 0.000000 for counting sort
 */
int main(void){
    srand(time(NULL));  // Initialization for randomization process
                        // Should only be called once.
    printArray(arr, MAX_ARRAY_ELEMENTS);
    randomizeArray(arr, MAX_ARRAY_ELEMENTS);
    printArray(arr, MAX_ARRAY_ELEMENTS);

    double time_spent = 0.0;
    clock_t begin = clock();
    countingSort(arr, MAX_ARRAY_ELEMENTS);
    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;

    printArray(arr, MAX_ARRAY_ELEMENTS);
    
    int status = isSorted(arr, MAX_ARRAY_ELEMENTS);
    if(status){
        printf("! Sorting array was successfull.\n");
    }else{
        printf("! Sorting array was not successfull.\n");
    }
    
    fp = fopen("log/c_std.log", "a");
    fprintf(fp, "Counting Sort, %d, %f, %d\n", MAX_ARRAY_ELEMENTS, time_spent, status);
    fclose(fp);
}