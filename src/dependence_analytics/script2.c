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