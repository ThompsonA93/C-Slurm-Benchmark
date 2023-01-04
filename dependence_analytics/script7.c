#include "utils.h"

#ifndef N
#define N 1000
#endif

int a[N];

// @Note: expected segfault given invalid index access (i > N)
/**
 * Dynamic indezes: i
 * 
 * Dependences: 
 * i=0 | a[4*0] = a[2*0-1] <=> a[0] = a[-1] 
 * i=1 | a[4*1] = a[2*1-1] <=> a[4] = a[1]
 * i=2 | a[4*2] = a[2*2-1] <=> a[8] = a[3]
 * 
 *              < i >
 * Distance:    < 2*i+1 >
 * Direction:   < < >
 */
void a7(){
    for(int i = 0; i < N; i++){
        a[4*i] = a[2*i-1];
    }
}

/**
 * Replace Loop header for loop L_0
 *      for(i = L; i < U; i+= S)
 * with adjusted loop header
 *      for(i = 0; i < (U - L + 1) / S; i++)
 * Replace each reference to i in loop by
 *      i * S - S + L
 * Insert finalization assignment after loop
 *      i = i * S - S + L
 */
void a7_normalized(){
    int i = 0;

    int Li = 0;
    int Ui = N;
    int Si = 1;
    int i_factor = Si - Si + Li;

    for(i = 0; i < (Ui - Li + 1) / Si; i++){
        a[4*i*i_factor] = a[2*i*i_factor-1];
    }
    i = i * i_factor;

}


int main(void){
    init_1d_array(a, N);
    //a7();
    init_1d_array(a, N);
    //a7_normalized();
    return 0;
}