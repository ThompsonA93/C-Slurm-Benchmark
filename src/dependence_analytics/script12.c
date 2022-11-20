#include "utils.h"

#ifndef N
#define N 1000
#endif

int a[N];
int b[N][N];


/**
 * Dynamic indezes: i
 * 
 * Dependences: 
 * i=0 | a[0] = a[1]
 * i=2 | a[2] = a[3]
 * i=4 | a[4] = a[5]
 *  
 *              <  i   >
 * Distance:    <  -1  >
 * Direction:   <  >   >
 *
 * ALTERNATIVE:
 * Referenced indezes never truly depend, since even index is written, uneven index is read.
 */
void a12(){
    for(int i = 0; i < N-1; i+=2){
        a[i] = a[i+1];
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
void a12_normalized(){
    int i = 0;
    
    int Li = 0;
    int Ui = N-1;
    int Si = 2;     
    int max_iteration = (Ui - Li + 1) / Si;
    int i_factor = Si - Si + Li;

    for(i = 0; i < max_iteration; i++){
        a[i*i_factor] = a[i*i_factor+1];
    }
    i = i*i_factor;
}

int main(void){
    init_1d_array(a, N);
    a12();

    init_1d_array(a, N);
    a12_normalized();
    return 0;
}