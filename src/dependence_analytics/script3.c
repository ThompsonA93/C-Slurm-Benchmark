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
 * Dependences ( Assuming a[i] = math.random() ): 
 *  i=0 | b[0][8] = b[a[0]][8]
 *  i=1 | b[1][8] = b[a[1]][8]
 * 
 * ... where a[1] = [0..100]
 * 
 *              < i, k >
 * Distance:    < *, 0 >
 * Direction:   < *, = >
 * 
 * If
 *  a[i] < i <=> True
 *  a[i] > i <=> Anti
 *  a[i] = i <=> Output
 */
void a3(){
    int k = 8;
    for(int i = 0; i < N; i++){
        b[i][k] = b[a[i]][k];
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
void a3_normalized(){
    int Li = 0;
    int Ui = N;
    int Si = 1;

    int i_factor = Si - Si + Li;

    int i = 0;
    int k = 8;
    for(i = 0; i < (Ui - Li + 1) / Si; i++){
        b[i*i_factor][k] = b[a[i*i_factor]][k];
    }
    i = i * i_factor;
}

int main(void){
    init_1d_array(a, N);
    init_2d_array(b, N, N);
    a3();

    init_1d_array(a, N);
    init_2d_array(b, N, N);
    a3_normalized();
    return 0;
}