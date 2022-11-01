#include "utils.h"

#ifndef N
#define N 1000
#endif


int a[N];
int b[N][N];

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