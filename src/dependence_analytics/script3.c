#include "utils.h"

#ifndef N
#define N 1000
#endif


int a[N];
int b[N][N];

/**
 * Dynamic indezes: i
 * Static indezes: k
 * Dependences ( Assuming a[i] = math.random() ): 
 *  b[i][k] = b[a[i]][k]
 *  b[1][8] = b[a[1]][k]
 *  b[1][8] = b[0..100][8]
 * Distance: < 
 *  a[i] = i <=> 0
 *  a[i] < i <=> 1
 *  a[i] > i <=> -1    
 * >
 * Direction: < 
 *  dist(0)  <=> =
 *  dist(1)  <=> <
 *  dist(-1) <=> >
 * > 
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