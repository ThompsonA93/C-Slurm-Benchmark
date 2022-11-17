#include "utils.h"

#ifndef N
#define N 1000
#endif


int a[N];
int b[N][N];


/**
 * FIXME :: This might be wrong.
 * Dynamic indezes: i
 * Static indezes: k
 * 
 * Dependences: 
 * i=0  | b[1][8] = a[1];
        |    a[0] = b[0][8];
 * i=1  | b[2][8] = a[2];
        |    a[1] = b[1][8];
 * i=2  | b[3][8] = a[3];
        |    a[2] = b[2][8];
 * 
 *              <  i, k  >
 * Distance:    <  0, 0  >
 * Direction:   <  =, =  >
 */
void a10(){
    int k = 8;
    for(int i = 0; i < N-1; i++){
        b[i+1][k] = a[i+1];
        a[i] = b[i][k];
    }
}

int main(void){
    init_1d_array(a, N);
    init_2d_array(b, N, N);
    a10();
    return 0;
}