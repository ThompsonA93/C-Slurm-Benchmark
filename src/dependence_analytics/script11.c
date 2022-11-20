#include "utils.h"

#ifndef N
#define N 1000
#endif

int a[N];


/**
 * Dynamic indezes: i
 * 
 * Dependences: 
 * i=0  | a[500-500] = a[500]
 *      | sum += a[500];
 * i=1  | a[501-500] = a[501]
 *      | sum += a[501];
 * i=2  | a[502-500] = a[502]
 *      | sum += a[502]; 
 *  
 *              <  i  >
 * Distance:    <  N/2  >
 * Direction:   <  >  >
 */
void a11(){
    int sum = 0;
    for(int i = N/2; i < N; i++){
        a[i-N/2] = a[i];
        sum += a[i];
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
void a11_normalized(){
    int sum = 0;
    int i = 0;

    int Li = N/2;
    int Ui = N;
    int Si = 1;         
    int max_iteration = (Ui - Li + 1) / Si;
    int i_factor = Si - Si + Li;

    for(i = 0; i < max_iteration; i++){
        a[i*i_factor-N/2] = a[i*i_factor];
        sum += a[i*i_factor];
    }
    i = i*i_factor;
}


int main(void){
    init_1d_array(a, N);
    a11();

    init_1d_array(a, N);
    //a11_normalized();
    return 0;
}