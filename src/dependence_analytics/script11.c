#include "utils.h"

#ifndef N
#define N 1000
#endif

int a[N];

void a11(){
    int sum = 0;
    for(int i = N/2; i < N; i++){
        a[i-N/2] = a[i];
        sum += a[i];
    }
}

int main(void){
    init_1d_array(a, N);
    a11();
    return 0;
}