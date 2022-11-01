#include "utils.h"

#ifndef N
#define N 1000
#endif

int b[N][N];

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