// graph.h

#ifndef GRAPH_H
#define GRAPH_H

#define INFINITY 999999.99

// Structure to represent a node in the adjacency list
typedef struct Node {
    int edgeId;
    int vertex;
    float weight;
    struct Node* next;
} Node;

// Structure to represent the graph
typedef struct Graph {
    int vertices;
    Node** adjList;
    float* distance;
    int* predecessor;
} Graph;

// Function to create a new graph with a given number of vertices
Graph* createGraph(int vertices);

// Function to add an edge to the graph
void addEdge(Graph* graph, int edgeId, int u, int v, float weight);

// Function to process Dijkstra's algorithm
void processDijkstra(Graph* graph, int source, int destination, int flag);

// Function to write the path based on computed information
void writePath(Graph* graph, int s, int d);

// Function to free allocated memory for the graph
void freeGraph(Graph* graph);

#endif  // GRAPH_H
