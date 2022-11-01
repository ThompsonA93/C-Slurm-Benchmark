#include "utils.h"

#ifndef N
#define N 1000
#endif

int a[N];

// @Note: expected given invalid index access (i > N)
void a7(){
    for(int i = 0; i < N; i++){
        a[4*i] = a[2*i-1];
    }
}


int main(void){
    init_1d_array(a, N);

    //a7();
    return 0;
}