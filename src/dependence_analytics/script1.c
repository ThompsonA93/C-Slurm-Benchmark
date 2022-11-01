#ifndef N
#define N 1000
#endif

int a[N];

void a1(){
    for(int i = 0; i < N; i++){
        a[i] = i;
    }
}

int main(void){
    a1();
    return 0;
}