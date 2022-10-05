#include <stdio.h>
#include <stdlib.h>


int a[2][4];
int b[3][6];

void printArray(int* arr, int x, int y){

    for(int i = 0; i <= x; i++){
        for(int j = 0; j <= y; j++){
            printf("%d, ", *arr[i][j]);
            arr++;
        }
        printf("\n");
    }
    printf("\n");
}

int main(void){



    int a_x = sizeof(a)/sizeof(a[0]);
    int a_y = sizeof(a[0])/sizeof(a[0][0]);
    printf("a_x: %d\ta_y: %d\n", a_x, a_y);

    int b_x = sizeof(b)/sizeof(b[0]);
    int b_y = sizeof(b[0])/sizeof(b[0][0]);
    printf("b_x: %d\tb_y: %d\n", b_x, b_y);
    //printArray(*a, a_x, a_y);
    //printArray(*b, b_x, b_y);

    printArray(a, a_x, a_y);

    return 0;
}

