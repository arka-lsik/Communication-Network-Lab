#include <stdio.h>
#include <limits.h>

//Number of vertices in the network graph
#define NUM_VERTICES 8

// A function to find the vertex with minimum distance value
//from the set of vertices not yet included in that tree
int findMinDistanceIndex(int distance[], int shortestPathTreeSet[]) {
//intiliaze the min value
int minDistance = INT_MAX, minIndex;
    for (int vertex = 0; vertex < NUM_VERTICES; vertex++) {
       if (!shortestPathTreeSet[vertex] && distance[vertex] <= minDistance) {
          minDistance = distance[vertex];
          minIndex = vertex;
          }
       }
   return minIndex;
}

//that function to print the constructe distance array
void printSolution(int distance[], int n) {
    printf("Vertex Distance from Source\n");
        for (int i = 0; i < NUM_VERTICES; i++)
            printf("%d \t\t %d\n", i, distance[i]);
        }

//This function that can implements the algo for single source
//shortest path algorithm for a graph represented using that cost matrix
void dijkstra(int graph[NUM_VERTICES][NUM_VERTICES], int sourceVertex) {
//this output array, distance[i] will hold the shortest
//distance form source to 1.
int distance[NUM_VERTICES];
int shortestPathTreeSet[NUM_VERTICES];
    for (int i = 0; i < NUM_VERTICES; i++) {
        distance[i] = INT_MAX;
        shortestPathTreeSet[i] = false;
        }
     distance[sourceVertex] = 0

    for (int count = 0; count < NUM_VERTICES - 1; count++) {
        int currentVertex = findMinDistanceIndex(distance, shortestPathTreeSet);
        shortestPathTreeSet[currentVertex] = true;
       
// update distance[i] only if is not in shortestpathTreeset,
// there is an edge from current vertex to adjacent vertex and total
// weight of path from source to current vertex through ajacent vertex is
// smaller than cuurent value of distance[curren vertex]
    for (int adjacentVertex = 0; adjacentVertex < NUM_VERTICES; adjacentVertex++) 
    {
        if (!shortestPathTreeSet[adjacentVertex] && 
            graph[currentVertex][adjacentVertex] &&
              distance[currentVertex] != INT_MAX &&
              distance[currentVertex] + graph[currentVertex][adjacentVertex] < 
              distance[adjacentVertex]) {
              distance[adjacentVertex] = distance[currentVertex] + 
              graph[currentVertex][adjacentVertex];
              }
         }
    }

// print the constructed distance array
printSolution(distance, NUM_VERTICES);
}
int main() {
// let us create the example graph discussed above
int adjacencyMatrix[NUM_VERTICES][NUM_VERTICES] = {
{0, 10, 20, 0, 0, 0, 0, 1},
{10, 0, 11, 9, 7, 0, 0, 0},
{20, 11, 0, 0, 0, 5, 4, 0},
{0, 9, 0, 0, 8, 0, 0, 0},
{0, 7, 0, 8, 0, 6, 15, 0},
{0, 0, 5, 0, 6, 0, 0, 2},
{0, 0, 4, 0, 15, 0, 0, 0},
{1, 0, 0, 0, 0, 2, 0, 0}};
// Function call
dijkstra(adjacencyMatrix, 0);
return 0;
}
