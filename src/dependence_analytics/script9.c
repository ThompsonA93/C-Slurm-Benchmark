#include "utils.h"

#ifndef N
#define N 1000
#endif

int b[N][N];


/**
 * Dynamic indezes: i, j
 * 
 * Dependences: 
 * i=0,j=0 | b[0][0] = b[1][-1]
 * i=0,j=1 | b[0][1] = b[1][0]
 * i=0,j=2 | b[0][2] = b[1][1]
 * 
 *              <  i, j  >
 * Distance:    < -1, 1  >
 * Direction:   <  >, <  > 
 * 
 * ALT:
 * i hat keine dependency weil gerade & ungerade angesprochen werden
 * True dependency mit J
 * Distance: < 0,1 >
 * Direction: < =,< >
 * 
 */
void a9(){
    for(int i = 0; i < N-1; i+=2){
        for(int j = i; j < N; j++){
            b[i][j] = b[i+1][j-1];
        }
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
void a9_normalized(){
    int i = 0;
    int j = 0;

    int Li = 0;
    int Ui = N-1;
    int Si = 2;
    int i_factor = Si - Si + Li;

    // Can't use Copy+Paste with this example given j = i
    //int Lj = 0; // = i 
    int Uj = N;
    int Sj = 1;
    //int j_factor = Sj - Sj + Lj;

    for(i = 0; i < (Ui - Li + 1) / Si; i++){
        for(j = 0; j < (Uj - i + 1) / Sj; j++){
            b[i*i_factor][j*Sj-Sj+i] = b[i*i_factor+1][(j*Sj-Sj+i)-1];
        }
        j = j * Sj - Sj + i;
    }
    i = i*i_factor;
}

int main(void){
    init_2d_array(b, N, N);
    a9();

    init_2d_array(b, N, N);
    a9_normalized();
    return 0;
}