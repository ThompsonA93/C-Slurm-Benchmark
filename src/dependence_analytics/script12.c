#include "utils.h"

#ifndef N
#define N 1000
#endif

int a[N];
int b[N][N];

void a12(){
    for(int i = 0; i < N-1; i+=2){
        a[i] = a[i+1];
    }
}

int main(void){
    init_1d_array(a, N);
    a12();
    return 0;
}