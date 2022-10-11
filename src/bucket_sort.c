#include <stdlib.h>
#include <time.h>

#include "utils_1d_array.h"
#include "utils_sort.h"
#include "bucket_sort.h"

#define ARRAY_SIZE 100
int arr[ARRAY_SIZE];

int main(void){
    srand(time(NULL));  // Initialization for randomization process
                        // Should only be called once.

    printArray(arr, MAX_ARRAY_ELEMENTS);
    randomizeArray(arr, MAX_ARRAY_ELEMENTS);
    printArray(arr, MAX_ARRAY_ELEMENTS);
    bucketSort(arr, MAX_ARRAY_ELEMENTS);
    printArray(arr, MAX_ARRAY_ELEMENTS);

    if(isSorted(arr, MAX_ARRAY_ELEMENTS)){
        printf("! Sorting array was successfull.\n");
    }else{
        printf("! Sorting array was not successfull.\n");
    }
}