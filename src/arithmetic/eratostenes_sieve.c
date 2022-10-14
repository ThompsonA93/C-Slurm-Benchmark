#include <stdlib.h>
#include <stdio.h>

#define MAX_VALUE 1000

void filter_primes(int limit){
    printf("Scanning values up to %d to be prime.\n", limit);

    int isPrime = 0;
    for(int i = 0; i <= limit; i++){
        for(int j = 2; j <= i/2; j++){  // Don't start with zero
            if(i % j == 0){
                isPrime = 1;
                break;
            }else{
                isPrime = 0;
            }       
        }
        if(!isPrime){
            printf("\t%d is prime\n", i);
        }
    }
}

int main(void){

    int max_val = MAX_VALUE;

    filter_primes(MAX_VALUE);

    return 0;
}