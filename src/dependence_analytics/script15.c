#include "utils.h"

#ifndef N
#define N 250
#endif

#ifndef M
#define M 250
#endif

#ifndef P
#define P 250
#endif

int a[N][M][P];
int b[N][M][P];

/**
 * Dynamic indezes: k, j, i
 * 
 * Dependences: 
 *              < k,  j,  i >
 * Distance:    < 0,  *,  1 >
 * Direction:   < =,  *,  < >  
 * 
 * Case J:
 *  j >  50: Anti-Dep
 *  j <= 50: True-Dep
 * 
 **/
void a15(){
    for(int k = 1; k < 100; k++){
        for(int j = 1; j < 100; j++){
            b[1][j][k] = a[1][j-1][k];
            for(int i = 1; i < 100; i++){
                a[i+1][j][k] = b[i][100-j][k];
            }
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
void a15_normalized(){
    int k = 0, j = 0, i = 0;

    int Lk = 1; 
    int Uk = 100;
    int Sk = 1;
    int k_factor = Sk - Sk + Lk;

    int Lj = 1; 
    int Uj = 100;
    int Sj = 1;
    int j_factor = Sj - Sj + Lj;

    int Li = 1;
    int Ui = 100;
    int Si = 1;
    int i_factor = Si - Si + Li;

    for(k = 0; k < (Uk - Lk + 1) / Sk; k++){
        for(j = 0; j < (Uj - Lj + 1) / Sj; j++){
            b[1][j*j_factor][k*k_factor] = a[1][j*j_factor-1][k*k_factor];
            for(i = 0; i < (Ui - Li + 1) / Si; i++){
                a[i*i_factor+1][j*j_factor][k*k_factor] = b[i*i_factor][100-j*j_factor][k*k_factor];
            }
            i = i*i_factor;
        }
        j = j*j_factor;
    }
    k = k*k_factor;
}



int main(void){
    init_3d_array(a, N, M, P);
    init_3d_array(b, N, M, P);
    a15();

    init_3d_array(a, N, M, P);
    init_3d_array(b, N, M, P);
    a15_normalized();
    return 0;
}