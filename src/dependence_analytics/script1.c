#ifndef N
#define N 1000
#endif

int a[N];

/**
 * Dependences: a[0] = 0, a[1] = 1, ...
 * Distance: < 0 >
 * Direction: < = > 
 */
void a1(){
    for(int i = 0; i < N; i++){
        a[i] = i;
    }
}

int main(void){
    a1();
    return 0;
}