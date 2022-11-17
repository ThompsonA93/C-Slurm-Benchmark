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
 * ...
 * Distance: < *, * >
 * Direction: < *, * > 
 */
void a2(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            b[i][j] = function_call();
        }
    }
}

int main(void){
    a2();
    return 0;
}