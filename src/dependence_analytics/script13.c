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
 *              < i, j >
 * Distance:    <  >
 * Direction:   <  > 
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

int main(void){
    init_1d_array(a, N);
    init_2d_array(b, M, N);

    //a13();
    return 0;
}