#ifndef UTILS_SORT
#define UTILS_SORT


/**
 * Swap 2 elements. Implements XOR-Swap
 * @see https://en.wikipedia.org/wiki/XOR_swap_algorithm#Code_example
 */ 
void swap(int* x, int* y){
    int t = *x;
    *x = *y;
    *y = t;
}

/**
 * Checks if an 1d-array is sorted
 * @param arr as array to check
 * @param n as array lenght
 * @return 1 if sorted, 0 if not sorted
 */
int is_sorted(int arr[], int n){

    for(int i = 1; i < n; i++){
        for(int j = 0; j < i; j++){
            if(arr[j] > arr[i]){
                return 0;
            }
        }
    }
    return 1;
}



#endif