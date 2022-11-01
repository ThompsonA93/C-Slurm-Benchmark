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

int main(void){
    init_3d_array(a, N, M, P);
    init_3d_array(b, N, M, P);
    a15();
    return 0;
}