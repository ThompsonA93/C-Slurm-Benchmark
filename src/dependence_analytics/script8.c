#include "utils.h"

#ifndef N
#define N 1000
#endif


int b[N][N];

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