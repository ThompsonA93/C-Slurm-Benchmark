#include "utils.h"

#ifndef N
#define N 1000
#endif


int b[N][N];

/**
 * Dynamic indezes: j
 * Static indezes: i
 * 
 * Dependences: 
 * j=0 | b[42][0] = b[41][0]
 * j=1 | b[42][1] = b[41][1]
 * j=2 | b[42][2] = b[41][2]
 * 
 *              < j, i >
 * Distance:    < 0, 1 >
 * Direction:   < =, < > 
 * 
 * Output dep
 * Dist = 1
 * Dir = <
 */
void a8(){
    int i = 42;
    for(int j = 0; j < N; j++){
        b[i][j] = b[i-1][j];
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
void a8_normalized(){
    int i = 42;

    int Lj = 0; 
    int Uj = N;
    int Sj = 1;
    int j_factor = Sj - Sj + Lj;

    int j = 0;
    for(j = 0; j < (Uj - Lj + 1) / Sj; j++){
        b[i][j*j_factor] = b[i-1][j*j_factor];
    }
    j = j * j_factor;
}

int main(void){
    init_2d_array(b, N, N);
    a8();
    
    init_2d_array(b, N, N);
    a8_normalized();
    return 0;
}