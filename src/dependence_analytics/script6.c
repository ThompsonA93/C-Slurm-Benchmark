#include "utils.h"

#ifndef N
#define N 1000
#endif


int a[N];


/**
 * Dynamic indezes: i
 * Static indezes: k
 * 
 * Dependences: 
 * i=0 | a[250] = a[250+8]
 * i=1 | a[251] = a[251+8]
 * 
 *              < i >
 * Distance:    < * >
 * Direction:   < * > 
 * 
 * if
 *  k <= 0     <=> True
 *  k >  0     <=> Anti
 */
void a6(){
    int k = 8;
    for(int i = N/4; i < N/2-k; i++){
        a[i] = a[i+k];
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
void a6_normalized(){
    int k = 8;
    int i = 0;

    int Li = N/4;       // 250
    int Ui = N/2-k;     // 492
    int Si = 1;         
    int i_factor = Si - Si + Li;
    for(i = 0; i < (Ui - Li + 1) / Si; i++){    // i < 242+1/1
        a[i*i_factor] = a[i*i_factor+k];        // i*1-1+250 ~???
    }
    i = i*i_factor;
}

int main(void){
    init_1d_array(a, N);
    a6();
    
    init_1d_array(a, N);
    //a6_normalized();
    return 0;
}