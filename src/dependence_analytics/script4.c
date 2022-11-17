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
 * Dependences:
 * i=0 | a[0] = a[-1] + b[0][8]
 * i=1 | a[1] = a[0] + b[1][8]
 * 
 *              < i, k >
 * Distance:    < 1, * >
 * Direction:   < <, * > 
 */
void a4(){
    int k = 8;
    for(int i = 1; i < N; i++){
        a[i] = a[i-1] + b[i][k];
    }
}

int main(void){
    init_1d_array(a, N);
    init_2d_array(b, N, N);

    a4();
    return 0;

}