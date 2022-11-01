#include "utils.h"

#ifndef N
#define N 1000
#endif


int a[N];

void a6(){
    int k = 8;
    for(int i = N/4; i < N/2-k; i++){
        a[i] = a[i+k];
    }
}

int main(void){
    init_1d_array(a, N);
    a6();
    return 0;
}