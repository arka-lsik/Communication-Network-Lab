#include <stdio.h>
#include <limits.h>
#define NUM_NODES 7
// NUmber of vertices in the graph
int findMinKey(int key[], int mstSet[]) {
int min = INT_MAX, minIndex;
    for (int node = 0; node < NUM_NODES; node++) {
        if (mstSet[node] == 0 && key[node] < min) {
          min = key[node];
          minIndex = node;
  }
}
return minIndex;
}

void printMinimumSpanningTree(int parent[], int graph[NUM_NODES][NUM_NODES]) {
     for (int i = 1; i < NUM_NODES; i++)
         printf("minimum cost of %d to %d is %d \n", parent[i], i, graph[i][parent[i]]);
}

void primMinimumSpanningTree(int graph[NUM_NODES][NUM_NODES]) {
int parent[NUM_NODES]; //array to store already made MST
int key[NUM_NODES]; // Key values for to pick min. cost
int mstSet[NUM_NODES]; //here represnt set of vertices included in MST
//Initialize all key
     for (int node = 0; node < NUM_NODES; node++) {
    key[node] = INT_MAX;
    mstSet[node] = 0;
}
// Alays include the first vertex in MST
key[0] = 0;
parent[0] = -1; // First node is Root of MST
//The MST will have Num__nodes Vertices
       for (int count = 0; count < NUM_NODES - 1; count++) {
// Pick the min key vertex from the set of vertices
            int u = findMinKey(key, mstSet);
// add the picked vertex to the MSTset
mstSet[u] = 1;
//Update the Key value and parent index of the adjacent
//Vetices of the picked vertex. Consier only that
//vertices which are not yet include in the MST
       for (int v = 0; v < NUM_NODES; v++) {
//graph[u][v] is non zero only for ajacent vertices of u
// mstSet[v] is false for vertices not yet include in MST
// update the key only if graph[u][v] is smaller than key[v]
           if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v]) {
               parent[v] = u;
               key[v] = graph[u][v];
    }
  }
}
// print the constructed MST
printMinimumSpanningTree(parent, graph);
}
int main() {
int graph[NUM_NODES][NUM_NODES] = {
{0, 7, 0, 5, 0, 0, 0},
{7, 0, 4, 9, 10, 0, 0},
{0, 4, 0, 0, 2, 0, 0},
{5, 9, 0, 0, 15, 6, 0},
{0, 10, 2, 15, 0, 13, 12},
{0, 0, 0, 6, 13, 0, 11},
{0, 0, 0, 0, 12, 11, 0}
};
primMinimumSpanningTree(graph);
return 0;
}
