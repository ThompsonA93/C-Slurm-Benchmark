#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

#define MAX_PATH_COST 100
#define VERTICE 250

int graph[VERTICE][VERTICE];
FILE *fp;

int minDistance(int dist[], bool sptSet[]){
    int min = INT_MAX; 
    int min_index;
 
    for (int v = 0; v < VERTICE; v++){
        if (sptSet[v] == false && dist[v] <= min){
            min = dist[v], min_index = v;
        }
    }
    return min_index;
}
 
void printSolution(int dist[]){
    //printf("Vertex \t\t Distance from Source\n");
    for (int i = 0; i < VERTICE; i++){
        //printf("%d \t\t\t\t %d\n", i, dist[i]);
    }
}
 
void dijkstra(int graph[VERTICE][VERTICE], int src){
    int dist[VERTICE];      // The output array.  dist[i] will hold the
                            // shortest
                            // distance from src to i
 
    bool sptSet[VERTICE];   // sptSet[i] will be true if vertex i is
                            // included in shortest
                            // path tree or shortest distance from src to i is
                            // finalized
 
    // Initialize all distances as INFINITE and stpSet[] as false
    for (int i = 0; i < VERTICE; i++){
        dist[i] = INT_MAX, sptSet[i] = false;
    }
 
    // Distance of source vertex from itself is always 0
    dist[src] = 0;
 
    // Find shortest path for all vertices
    for (int count = 0; count < VERTICE - 1; count++) {
        // Pick the minimum distance vertex from the set of
        // vertices not yet processed. u is always equal to
        // src in the first iteration.
        int u = minDistance(dist, sptSet);
 
        // Mark the picked vertex as processed
        sptSet[u] = true;
 
        // Update dist value of the adjacent vertices of the
        // picked vertex.
        for (int v = 0; v < VERTICE; v++){
            // Update dist[v] only if is not in sptSet,
            // there is an edge from u to v, and total
            // weight of path from src to  v through u is
            // smaller than current value of dist[v]
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]){
                dist[v] = dist[u] + graph[u][v];
            }
        } 
    }
 
    // print the constructed distance array
    printSolution(dist);
}
 
int main(){
    srand(time(NULL));  // Initialization for randomization process
                        // Should only be called once.

    //printf("Initiating cost array\n");
    int count = 0;
    for(int m = 0; m < VERTICE; m++){
        for(int n = count; n < VERTICE; n++){
            if(m == n){
                graph[m][n] = 0;
                graph[n][m] = 0;
            } else if(rand() % 4 == 0){
                graph[m][n] = 0;
                graph[n][m] = 0;
            } else {
                graph[m][n] = rand() % MAX_PATH_COST;
                graph[n][m] = graph[m][n];
            }
        }
        count += 1;
    }

    for(int i = 0; i < VERTICE; i++){
        for(int j = 0; j < VERTICE; j++){
            //printf("\t%d", graph[i][j]);
        }
        //printf("\n");
    }

    // Start measuring time
    struct timeval begin, end;
    gettimeofday(&begin, 0);
    

    dijkstra(graph, 0);

    // Stop measuring time and calculate the elapsed time
    gettimeofday(&end, 0);
    long seconds = end.tv_sec - begin.tv_sec;
    long microseconds = end.tv_usec - begin.tv_usec;
    double time_spent = seconds + microseconds*1e-6;

    fp = fopen("log/c_std.log", "a");
    fprintf(fp, "Dijkstra, %dx%d, %f, %d\n", VERTICE, VERTICE, time_spent, 1);
    fclose(fp);

    return 0;
}