#include "utils.h"

#ifndef N
#define N 1000
#endif


int a[N];
int b[N][N];


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