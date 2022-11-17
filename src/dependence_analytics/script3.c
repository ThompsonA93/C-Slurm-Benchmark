#include "utils.h"

#ifndef N
#define N 1000
#endif


int a[N];
int b[N][N];

/**
 * Dynamic indezes: i
 * Static indezes: k
 * 
 * Dependences ( Assuming a[i] = math.random() ): 
 *  i=0 | b[0][8] = b[a[0]][8]
 *  i=1 | b[1][8] = b[a[1]][8]
 * 
 * ... where a[1] = [0..100]
 * 
 *              < i, k >
 * Distance:    < *, 0 >
 * Direction:   < *, = >
 * 
 */
void a3(){
    int k = 8;
    for(int i = 0; i < N; i++){
        b[i][k] = b[a[i]][k];
    }
}

int main(void){
    init_1d_array(a, N);
    init_2d_array(b, N, N);
    a3();
    return 0;
}