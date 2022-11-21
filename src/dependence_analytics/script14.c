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

// FIXME Segfaults. Not sure whether due to Indezes or faulty dimension assignment
/**
 * Dynamic indezes: i, j, k
 * 
 * Dependences: 
 *              < i,  j,  k  >
 * Distance:    < 2, -2, 12  >
 * Direction:   < <,  >,  <  >  
 * 
 * First index: Read then write, Anti-Dependency
 **/
void a14(){
    for(int i = 2; i < N; i++){
        for(int j = 1; j < M; j++){
            for(int k = 0; k < P; k++){
                a[i-2][2*j][3*k+3] = a[i][2*j-2][3*k+15] + 4;
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
void a14_normalized(){
    int i = 0, j = 0, k = 0;

    int Li = 2;
    int Ui = N;
    int Si = 1;
    int i_factor = Si - Si + Li;

    int Lj = 1; 
    int Uj = M;
    int Sj = 1;
    int j_factor = Sj - Sj + Lj;

    int Lk = 0; 
    int Uk = P;
    int Sk = 1;
    int k_factor = Sk - Sk + Lk;


    for(i = 0; i < (Ui - Li + 1) / Si; i++){
        for(j = 0; j < (Uj - Lj + 1) / Sj; j++){
            for(k = 0; k < (Uk - Lk + 1) / Sk; k++){
                a[i*i_factor-2][2*j*j_factor][3*k*k_factor+3] = a[i*i_factor][2*j*j_factor-2][3*k*k_factor+15] + 4;
            }
            k = k*k_factor;
        }
        j = j*j_factor;
    }
    i = i*i_factor;
}

int main(void){
    init_3d_array(a, N, M, P);
    //a14();
    init_3d_array(a, N, M, P);
    //a14_normalized();
    return 0;
}