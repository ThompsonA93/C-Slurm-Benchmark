#include "utils.h"

#ifndef N
#define N 1000
#endif


int a[N];
int b[N][N];

/**
 * Dynamic indezes: i
 * Static indezes: k
 * 
 * Dependences:
 * i=0 | a[0] = a[-1] + b[0][8]
 * i=1 | a[1] = a[0] + b[1][8]
 * 
 *              < i >
 * Distance:    < 1 >
 * Direction:   < < > 
 */
void a4(){
    int k = 8;
    for(int i = 1; i < N; i++){
        a[i] = a[i-1] + b[i][k];
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
void a4_normalized(){
    int Li = 1;
    int Ui = N;
    int Si = 1;
    int i_factor = Si - Si + Li;

    int k = 8;
    int i = 0;
    for(i = 1; i < N; i++){
        a[i*i_factor] = a[i*i_factor-1] + b[i*i_factor][k];
    }
    i = i*i_factor;
}

int main(void){
    init_1d_array(a, N);
    init_2d_array(b, N, N);
    a4();

    init_1d_array(a, N);
    init_2d_array(b, N, N);
    a4_normalized();

    return 0;

}