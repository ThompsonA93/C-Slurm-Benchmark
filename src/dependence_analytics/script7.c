#include "utils.h"

#ifndef N
#define N 1000
#endif

int a[N];

// @Note: expected segfault given invalid index access (i > N)
/**
 * Dynamic indezes: i
 * 
 * Dependences: 
 * i=0 | a[4*0] = a[2*0-1] <=> a[0] = a[-1] 
 * i=1 | a[4*1] = a[2*1-1] <=> a[4] = a[1]
 * i=2 | a[4*2] = a[2*2-1] <=> a[8] = a[3]
 * 
 *              < i >
 * Distance:    < 1 >
 * Direction:   < < >
 * 
 * i*4 > i*2-1 <=> write before read 
 */
void a7(){
    for(int i = 0; i < N; i++){
        a[4*i] = a[2*i-1];
    }
}


int main(void){
    init_1d_array(a, N);

    //a7();
    return 0;
}