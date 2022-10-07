#ifndef SORT_UTILS
#define SORT_UTILS


/**
 * Swap 2 elements. Implements XOR-Swap
 * @see https://en.wikipedia.org/wiki/XOR_swap_algorithm#Code_example
 */ 
void swap(int* x, int* y){
    *x ^= *y;
    *y ^= *x;
    *x ^= *y;
}




#endif