#include "utils.h"

#ifndef N
#define N 1000
#endif


int a[N];
int b[N][N];

void a5(){
    int k = 8;
    for(int i = 0; i < N-abs(k); i++){
        b[i][k] = b[i+abs(k)][k] - a[i];
    }
}

int main(void){
    init_1d_array(a, N);
    init_2d_array(b, N, N);
    a5();
    return 0;

}