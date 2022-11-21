#include "utils.h"

#ifndef N
#define N 1000
#endif


int a[N];
int b[N][N];


/**
 * FIXME :: This might be wrong.
 * Dynamic indezes: i
 * Static indezes: k
 * 
 * Dependences: 
 * i=0  | b[1][8] = a[1];
        |    a[0] = b[0][8];
 * i=1  | b[2][8] = a[2];
        |    a[1] = b[1][8];
 * i=2  | b[3][8] = a[3];
        |    a[2] = b[2][8];
 * 
 * Array B: Anti-Dependency
 * Distance = -1
 * Direction = >
 * 
 * Array A: True-Dependency
 * Distance = 1
 * Direction = <
 * 
 */
void a10(){
    int k = 8;
    for(int i = 0; i < N-1; i++){
        b[i+1][k] = a[i+1];
        a[i] = b[i][k]; // b[i][k] is replacable by a[i]
                        // Splitting loop is also possible
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
void a10_normalized(){
    int k = 8;
    int i = 0;

    int Li = 0;
    int Ui = N-1;
    int Si = 1;         
    int max_iteration = (Ui - Li + 1) / Si;
    int i_factor = Si - Si + Li;

    for(i = 0; i < max_iteration; i++){
        b[i*i_factor+1][k] = a[i*i_factor+1];
        a[i*i_factor] = b[i*i_factor][k];
    }
    i = i*i_factor;
}


int main(void){
    init_1d_array(a, N);
    init_2d_array(b, N, N);
    a10();

    init_1d_array(a, N);
    init_2d_array(b, N, N);
    a10_normalized();
    return 0;
}