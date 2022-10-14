#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "utils_1d_array.h"
#include "utils_sort.h"
#include "quick_sort.h"
FILE *fp;
int arr[MAX_ARRAY_ELEMENTS];

int main(void){
    srand(time(NULL));  // Initialization for randomization process
                        // Should only be called once.
    print_array(arr, MAX_ARRAY_ELEMENTS);
    randomize_array(arr, MAX_ARRAY_ELEMENTS);
    print_array(arr, MAX_ARRAY_ELEMENTS);

    double time_spent = 0.0;
    clock_t begin = clock();
    quick_sort(arr, 0, MAX_ARRAY_ELEMENTS);
    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;


    print_array(arr, MAX_ARRAY_ELEMENTS);
    
    int status = is_sorted(arr, MAX_ARRAY_ELEMENTS);
    if(status){
        printf("! Sorting array was successfull.\n");
    }else{
        printf("! Sorting array was not successfull.\n");
    }
    
    fp = fopen("log/c_std.log", "a");
    fprintf(fp, "Quick Sort, %d, %f, %d\n", MAX_ARRAY_ELEMENTS, time_spent, status);
    fclose(fp);

}