#include "utils.h"

#ifndef N
#define N 1000
#endif

int a[N];
int b[N][N];


/**
 * Dynamic indezes: i
 * 
 * Dependences: 
 * i=0 | a[0] = a[1]
 * i=1 | a[1] = a[2]
 * i=2 | a[2] = a[3]
 *  
 *              <  i   >
 * Distance:    <  -1  >
 * Direction:   <  >   >
 */
void a12(){
    for(int i = 0; i < N-1; i+=2){
        a[i] = a[i+1];
    }
}

int main(void){
    init_1d_array(a, N);
    a12();
    return 0;
}