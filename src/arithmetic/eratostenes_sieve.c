#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_VALUE 100000

FILE *fp;

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
    
    double time_spent = 0.0;
    clock_t begin = clock();
    filter_primes(MAX_VALUE);
    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;

    fp = fopen("log/c_std.log", "a");
    fprintf(fp, "Sieve of eratostenes, %d, %f, %d\n", MAX_VALUE, time_spent, 1);
    fclose(fp);

    return 0;
}