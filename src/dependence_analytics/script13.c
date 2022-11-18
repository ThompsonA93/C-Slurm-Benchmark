#include "utils.h"

#ifndef N
#define N 1000
#endif

#ifndef M
#define M 1000
#endif

int a[N];
int b[N][M];

// FIXME Segfaults. Not sure whether due to Indezes or faulty dimension assignment
/**
 * Dynamic indezes: i, j
 * Static indezes: x, y
 * 
 * Dependences: 
 * i=2,j=0  | a[2] = b[3][-2] - 99;
 *          | b[1][2] = 12 + 18 * 2;
 * i=2,j=1  | a[2] = b[4][-2] - 99;
 *          | b[2][2] = 12 + 18 * 2;
 * i=2,j=2  | a[2] = b[5][-2] - 99;
 *          | b[3][2] = 12 + 18 * 2;
 * 
 *              < i,  j  >
 * Distance:    < 2, -2  >
 * Direction:   < <,  >  > 
 *
 * a.: True dep
 * b.: Anti dep
 */
void a13(){
    int x = 12;
    int y = 18;
    for(int i = 2; i < N; i++){
        for(int j = 0; j < M; j++){
            a[i] = b[j+3][i-2] - 99;
            b[j+1][i] = x + y * i;
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
void a13_normalized(){
    int i = 0;
    int j = 0;
    int x = 12;
    int y = 18;

    int Li = 2;
    int Ui = N;
    int Si = 1;
    int i_factor = Si - Si + Li;

    int Lj = 0; 
    int Uj = M;
    int Sj = 1;
    int j_factor = Sj - Sj + Lj;

    for(i = 2; i < (Ui - Li + 1) / Si; i++){
        for(j = 0; j < (Uj - Lj + 1) / Sj; j++){
            a[i*i_factor] = b[j*j_factor+3][i*i_factor-2] - 99;
            b[j*j_factor+1][i*i_factor] = x + y * i;
        }
        j = j * j_factor;
    }
    i = i * i_factor;
}

int main(void){
    init_1d_array(a, N);
    init_2d_array(b, M, N);

    //a13();

    init_1d_array(a, N);
    init_2d_array(b, M, N);

    //a13_normalized();
    return 0;
}