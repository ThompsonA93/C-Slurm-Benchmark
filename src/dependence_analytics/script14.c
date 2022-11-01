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
void a14(){
    for(int i = 2; i < N; i++){
        for(int j = 1; j < M; j++){
            for(int k = 0; k < P; k++){
                a[i-2][2*j][3*k+3] = a[i][2*j-2][3*k+15] + 4;
            }
        }
    }
}

int main(void){
    init_3d_array(a, N, M, P);
    //a14();
    return 0;
}