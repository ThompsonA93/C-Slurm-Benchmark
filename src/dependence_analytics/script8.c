#include "utils.h"

#ifndef N
#define N 1000
#endif


int b[N][N];

/**
 * Dynamic indezes: j
 * Static indezes: i
 * 
 * Dependences: 
 * j=0 | b[42][0] = b[41][0]
 * j=1 | b[42][1] = b[41][1]
 * j=2 | b[42][2] = b[41][2]
 * 
 *              < j, i >
 * Distance:    < 0, 1 >
 * Direction:   < =, < > 
 */
void a8(){
    int i = 42;
    for(int j = 0; j < N; j++){
        b[i][j] = b[i-1][j];
    }
}

int main(void){
    init_2d_array(b, N, N);
    a8();
    return 0;
}