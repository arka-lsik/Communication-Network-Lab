#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX_VERTICES 100
#define MAX_EDGES 100
// Structure to represent an edge in the graph
struct Edge {
       int src, dest, weight;
};

// Structure to represent the graph
struct Graph {
       int V, E;
       struct Edge edges[MAX_EDGES];
};

// Function to initialize the graph
void initializeGraph(struct Graph *graph, int V, int E) {
       graph->V = V;
       graph->E = E;
}

// Function to relax an edge
void relax(struct Graph *graph, int dist[], int parent[], int u, int v, int weight) {
      if (dist[u] + weight < dist[v]) {
      dist[v] = dist[u] + weight;
      parent[v] = u;
   }
}

// Bellman-Ford algorithm
void bellmanFord(struct Graph *graph, int src) {
 int V = graph->V;
 int E = graph->E;
 int dist[MAX_VERTICES];
 int parent[MAX_VERTICES];
 // Initialize distances and parents
 for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        parent[i] = -1;
 }
       dist[src] = 0;
 // Relax all edges V-1 times
 for (int i = 1; i <= V - 1; i++) {
     for (int j = 0; j < E; j++) {
         int u = graph->edges[j].src;
         int v = graph->edges[j].dest;
         int weight = graph->edges[j].weight;
         relax(graph, dist, parent, u, v, weight);
     }
 }
 // Check for negative weight cycles
 for (int i = 0; i < E; i++) {
     int u = graph->edges[i].src;
     int v = graph->edges[i].dest;
     int weight = graph->edges[i].weight;
 if (dist[u] + weight < dist[v]) {
     printf("Graph contains a negative weight cycle\n");
 return;
  }
}
// Print the result
 printf("Vertex Distance from Source Parent\n");
 for (int i = 0; i < V; i++) {
     printf("%d \t\t %d \t\t\t\t\t\t %d \n", i, dist[i], parent[i]);
 }
}


int main() {
 struct Graph graph;
 int V = 6; // Number of vertices
 int E = 9; // Number of edges
 initializeGraph(&graph, V, E);
 // Example edges with weights
 graph.edges[0].src = 0; 
 graph.edges[0].dest = 1; 
 graph.edges[0].weight = 6;
 
 graph.edges[1].src = 0; 
 graph.edges[1].dest = 2; 
 graph.edges[1].weight = 4;
 
 graph.edges[2].src = 0; 
 graph.edges[2].dest = 3; 
 graph.edges[2].weight = 5;
 
 graph.edges[3].src = 1; 
 graph.edges[3].dest = 4; 
 graph.edges[3].weight = -1;
 
 graph.edges[4].src = 2; 
 graph.edges[4].dest = 4; 
 graph.edges[4].weight = 3;
 
 graph.edges[5].src = 3; 
 graph.edges[5].dest = 5; 
 graph.edges[5].weight = 3;
 
 graph.edges[6].src = 3; 
 graph.edges[6].dest = 2; 
 graph.edges[6].weight = -2;
 
 graph.edges[7].src = 2; 
 graph.edges[7].dest = 1; 
 graph.edges[7].weight = -2;
 
 graph.edges[8].src = 4; 
 graph.edges[8].dest = 5; 
 graph.edges[8].weight = 1;
 
 
 int sourceVertex = 0; // Source vertex
 bellmanFord(&graph, sourceVertex);
 return 0;
}
