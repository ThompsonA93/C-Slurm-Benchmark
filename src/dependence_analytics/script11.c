#include "utils.h"

#ifndef N
#define N 1000
#endif

int a[N];


/**
 * Dynamic indezes: i
 * 
 * Dependences: 
 * i=0  | a[500-500] = a[500]
 *      | sum += a[500];
 * i=1  | a[501-500] = a[501]
 *      | sum += a[501];
 * i=2  | a[502-500] = a[502]
 *      | sum += a[502]; 
 *  
 *              <  i  >
 * Distance:    <  -1  >
 * Direction:   <  >  >
 */
void a11(){
    int sum = 0;
    for(int i = N/2; i < N; i++){
        a[i-N/2] = a[i];
        sum += a[i];
    }
}

int main(void){
    init_1d_array(a, N);
    a11();
    return 0;
}