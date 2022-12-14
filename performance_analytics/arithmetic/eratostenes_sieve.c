#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <sys/time.h>


#ifndef MAX_VALUE
#define MAX_VALUE 100000
#endif

FILE *fp;

void filter_primes(int limit){
    //printf("Scanning values up to %d to be prime.\n", limit);

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
            //printf("\t%d is prime\n", i);
        }
    }
}

int main(void){
    int max_val = MAX_VALUE;
    
    // Start measuring time
    struct timeval begin, end;
    gettimeofday(&begin, 0);
    
    filter_primes(MAX_VALUE);

    // Stop measuring time and calculate the elapsed time
    gettimeofday(&end, 0);
    long seconds = end.tv_sec - begin.tv_sec;
    long microseconds = end.tv_usec - begin.tv_usec;
    double time_spent = seconds + microseconds*1e-6;


    fp = fopen("log/c_std.csv", "a");
    fprintf(fp, "Sieve of eratostenes, %d, %f, %d\n", MAX_VALUE, time_spent, 1);
    fclose(fp);

    return 0;
}