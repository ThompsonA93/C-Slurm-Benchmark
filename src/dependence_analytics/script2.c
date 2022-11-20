#ifndef N
#define N 1000
#endif

#ifndef M
#define M 1000 // Required at 13,14,15 -- Just keep equal to N.
#endif

int b[N][N];

int function_call(){
    return 42;
}

/**
 * ''If loop index does not appear in subscript of source or sink, its distance is unconstrained and its direction is *''
 * 
 * Dependences:
 * i=0,j=0 | b[0][0] = 42
 * i=0,j=1 | b[0][1] = 42 
 *
 * There are no dependencies
 */
void a2(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            b[i][j] = function_call();
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
void a2_normalized(){
    int i = 0;
    int j = 0;

    int Li = 0;
    int Ui = N;
    int Si = 1;
    int i_factor = Si - Si + Li;

    int Lj = 0; 
    int Uj = N;
    int Sj = 1;
    int j_factor = Sj - Sj + Lj;

    for(i = 0; i < (Ui - Li + 1) / Si; i++){
        for(j = 0; j < (Uj - Lj + 1) / Sj; j++){
            b[i*i_factor][j*j_factor] = function_call();
        }
        j = j * j_factor;
    }
    i = i * i_factor;
}

int main(void){
    a2();
    a2_normalized();
    return 0;
}