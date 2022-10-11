#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "utils_1d_array.h"
#include "utils_sort.h"
#include "utils_log.h"
#include "counting_sort.h"

int arr[MAX_ARRAY_ELEMENTS];

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
    
    if(isSorted(arr, MAX_ARRAY_ELEMENTS)){
        printf("! Sorting array was successfull.\n");
    }else{
        printf("! Sorting array was not successfull.\n");
    }

    printf("\tRequired time: %f\n", time_spent);
}