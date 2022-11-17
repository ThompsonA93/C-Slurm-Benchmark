#include "utils.h"

#ifndef N
#define N 1000
#endif


int a[N];


/**
 * Dynamic indezes: i
 * Static indezes: k
 * 
 * Dependences: 
 * i=0 | a[250] = a[250+8]
 * i=1 | a[251] = a[251+8]
 * 
 *              < i, k >
 * Distance:    < *, * >
 * Direction:   < *, * > 
 */
void a6(){
    int k = 8;
    for(int i = N/4; i < N/2-k; i++){
        a[i] = a[i+k];
    }
}

int main(void){
    init_1d_array(a, N);
    a6();
    return 0;
}