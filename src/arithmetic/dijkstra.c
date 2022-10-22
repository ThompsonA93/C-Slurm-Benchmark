#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_PATH_COST 10

#define GOAL_X 3
#define GOAL_Y 3

int paths[GOAL_X][GOAL_Y];

FILE *fp;

/**
 * Returns the amount of total possible paths in any given x*y matrix
 * TODO Find iterative alternative
 */
int number_of_paths(int x, int y){
    if(x == 1 || y == 1){
        return 1;
    }
    return number_of_paths(x - 1, y) + number_of_paths(x, y-1);
}


// Assume: 2 Dimensional array
// Assume: May only move to neighbouring cell (Horizontal, Vertical)
// Assume: Start always at 0,0
int main(void){
    // Initialization for randomization process. Should only be called once.
    srand(time(NULL)); 

    // Only need to calculate paths from 0,0 to X,Y - else redundant calc
    printf("Initiating path costs.\n");
    for(int m = 0; m < GOAL_X; m++){
        for(int n = 0; n < GOAL_Y; n++){
            paths[m][n] = rand() % MAX_PATH_COST + 1; // Minimum cost of 1
            printf("\t%d ", paths[m][n]);
        }
        printf("\n");
    }

    // Start Time
    double time_spent = 0.0;
    clock_t begin = clock();


    // Dijkstra -- #1 Calculate all possible paths. Remember cost + movements
    int num_paths = number_of_paths(GOAL_X, GOAL_Y);
    char pathways[num_paths];
    int sum_paths[num_paths];
    printf("\tCounted %d possible paths.\n", num_paths);

    // Dijkstra -- #2 Calculate costs of all possible paths
    for(int i = 0; i < GOAL_X; i++){
        for(int j = 0; j < GOAL_Y; j++){
            // TODO score all paths
        }
    }
    


    // Dijkstra -- #3 Return cheapest path
    // TODO Search lowest element in sum_paths
    // TODO Return pathways.lowest_element



    // End time, log & return
    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;

    fp = fopen("log/c_std.log", "a");
    fprintf(fp, "Dijkstra, %dx%d, %f, %d\n", GOAL_X, GOAL_Y, time_spent, 1);
    fclose(fp);

    return 0;
}