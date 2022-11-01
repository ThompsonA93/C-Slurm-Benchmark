#ifndef UTILS
#define UTILS

#include <stdlib.h>
#define ELEMENT_VALUE_RANGE 100


void init_1d_array(int* arr, int d1){
    for(int i = 0; i < d1; i++){
        *arr = rand() % ELEMENT_VALUE_RANGE;
        arr++;
    }
}

void init_2d_array(int* arr, int d1, int d2){
    for(int i = 0; i < d1; i++){
        for(int j = 0; j < d2; j++){
            *arr = rand() % ELEMENT_VALUE_RANGE;
            arr++;
        }
    }
}

void init_3d_array(int* arr, int d1, int d2, int d3){
    for(int i = 0; i < d1; i++){
        for(int j = 0; j < d2; j++){
            for(int k = 0; k < d3; k++){
                *arr = rand() % ELEMENT_VALUE_RANGE;
                arr++;
            }
        }
    }
}


#endif