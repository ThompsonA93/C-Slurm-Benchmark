#include "utils.h"

#ifndef N
#define N 1000
#endif

int b[N][N];


/**
 * Dynamic indezes: i, j
 * 
 * Dependences: 
 * i=0,j=0 | b[0][0] = b[1][-1]
 * i=0,j=1 | b[0][1] = b[1][0]
 * i=0,j=2 | b[0][2] = b[1][1]
 * 
 *              <  i, j  >
 * Distance:    < -1, 1  >
 * Direction:   <  >, <  > 
 */
void a9(){
    for(int i = 0; i < N-1; i+=2){
        for(int j = i; j < N; j++){
            b[i][j] = b[i+1][j-1];
        }
    }
}

int main(void){
    init_2d_array(b, N, N);
    a9();
    return 0;
}