#ifndef N
#define N 1000
#endif

int a[N];

/**
 * ''If loop index does not appear in subscript of source or sink, its distance is unconstrained and its direction is *''
 * 
 * Dependences: 
 *  i=0 | a[0] = 0
 *  i=1 | a[1] = 1 
 *  ...
 *
 * Distance:  < * >
 * Direction: < * > 
 */
void a1(){
    for(int i = 0; i < N; i++){
        a[i] = i;
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
void a1_normalized(){
    int i = 0;

    int L = 0;
    int U = N;
    int S = 1;
    int i_factor = S - S + L;

    for(i = 0; i < (U - L + 1) / S; i++){
        a[i*i_factor] = i;
    }
    i = i * i_factor;
}

int main(void){
    a1();
    a1_normalized();
    return 0;
}