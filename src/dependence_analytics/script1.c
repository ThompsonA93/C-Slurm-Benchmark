#ifndef N
#define N 1000
#endif

int a[N];

/**
 * ''If loop index does not appear in subscript of source or sink, its distance is unconstrained and its direction is *''
 * 
 * Dependences: 
 *  i=0 | a[0] = 0
 *  i=1 | a[1] = 1 
 *  ...
 *
 * Distance: < * >
 * Direction: < * > 
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