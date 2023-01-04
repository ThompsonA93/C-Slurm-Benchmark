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
 * i=0 | b[0][8] = b[0+abs(8)][8] - a[0];
 * i=1 | b[1][8] = b[1+abs(8)][8] - a[1];
 * 
 *              < i >
 * Distance:    < * >
 * Direction:   < * > 
 * 
 * If
 *  abs(k) = 0 <=> =
 *  abs(k) > 0 <=> <
 */
void a5(){
    int k = 8;
    for(int i = 0; i < N-abs(k); i++){
        b[i][k] = b[i+abs(k)][k] - a[i];
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
void a5_normalized(){
    int k = 8;
    int i = 0;

    int Li = 0;
    int Ui = N-abs(k);
    int Si = 1;
    int i_factor = Si - Si + Li;

    for(i = 0; i < (Ui - Li + 1) / Si; i++){
        b[i*i_factor][k] = b[i*i_factor+abs(k)][k] - a[i*i_factor];
    }
    i = i*i_factor;

}


int main(void){
    init_1d_array(a, N);
    init_2d_array(b, N, N);
    a5();

    init_1d_array(a, N);
    init_2d_array(b, N, N);
    a5_normalized();
    return 0;

}