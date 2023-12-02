// graph.c

#include "graph.h"
#include "minheap.h"
#include <stdio.h>
#include <stdlib.h>

Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    if (graph == NULL) {
        fprintf(stderr, "Memory allocation error\n");
        exit(EXIT_FAILURE);
    }

    graph->vertices = vertices;
    graph->adjList = (Node**)malloc(vertices * sizeof(Node*));
    graph->distance = (float*)malloc(vertices * sizeof(float));
    graph->predecessor = (int*)malloc(vertices * sizeof(int));

    if (graph->adjList == NULL || graph->distance == NULL || graph->predecessor == NULL) {
        fprintf(stderr, "Memory allocation error\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < vertices; ++i) {
        graph->adjList[i] = NULL;
        graph->distance[i] = INFINITY;
        graph->predecessor[i] = -1;
    }

    return graph;
}

void addEdge(Graph* graph, int edgeId, int u, int v, float weight) {
    Node* newNode = createNode(edgeId, v, weight);
    newNode->next = graph->adjList[u];
    graph->adjList[u] = newNode;
}

MinHeap* initializeMinHeap(int capacity) {
    MinHeap* heap = (MinHeap*)malloc(sizeof(MinHeap));
    if (heap == NULL) {
        fprintf(stderr, "Memory allocation error\n");
        exit(EXIT_FAILURE);
    }

    heap->capacity = capacity;
    heap->size = 0;
    heap->array = (HeapNode**)malloc(capacity * sizeof(HeapNode*));
    if (heap->array == NULL) {
        fprintf(stderr, "Memory allocation error\n");
        exit(EXIT_FAILURE);
    }

    return heap;
}

void processDijkstra(Graph* graph, int source, int destination, int flag, MinHeap* heap) {
    int vertices = graph->vertices;

    if (source < 0 || source >= vertices || destination < 0 || destination >= vertices) {
        fprintf(stderr, "Invalid source or destination\n");
        exit(EXIT_FAILURE);
    }

    // Initialize distance, predecessor arrays, and min heap
    graph->distance[source] = 0;
    insertHeap(heap, source, graph->distance[source]);

    // Dijkstra's algorithm
    while (!isEmptyHeap(heap)) {
        int u = extractMin(heap);
        Node* current = graph->adjList[u];
        while (current != NULL) {
            int v = current->vertex;
            float weight = current->weight;

            // Relaxation
            if (graph->distance[v] > graph->distance[u] + weight) {
                graph->distance[v] = graph->distance[u] + weight;
                graph->predecessor[v] = u;

                // If flag=1, print min-heap operations
                if (flag == 1) {
                    // Print min-heap operations
                    if (graph->distance[v] == INFINITY) {
                        printf("Insert vertex %d, key= INFINITY\n", v);
                    }
                    else {
                        printf("Decrease key of vertex %d, from %12.4f to %12.4f\n", v,
                            graph->distance[v] + weight, graph->distance[v]);
                    }
                }

                // If destination is extracted, terminate without relaxations
                if (u == destination) {
                    break;
                }
                if (!isInHeap(heap, v)) {
                    insertHeap(heap, v, graph->distance[v]);
                }
                current = current->next;
            }

        }
        if (flag == 1) {
            printf("Delete vertex %d, key=%12.4f\n", u, graph->distance[u]);
        }
    }
}


    

void writePath(Graph* graph, int s, int d) {
    // Write the path based on the computed information
    if (graph->distance[d] == INFINITY) {
        printf("No %d-%d path exists.\n", s, d);
    }
    else if (graph->predecessor[d] == -1) {
        printf("No %d-%d path has been computed.\n", s, d);
    }
    else {
        printf("Shortest path: <%d", d);

        int predecessor = graph->predecessor[d];
        while (predecessor != -1) {
            printf(", %d", predecessor);
            predecessor = graph->predecessor[predecessor];
        }

        printf(">\n");
        printf("The path weight is: %12.4f\n", graph->distance[d]);
    }
}

void freeGraph(Graph* graph) {
    // Free allocated memory for graph
    for (int i = 0; i < graph->vertices; ++i) {
        Node* current = graph->adjList[i];
        while (current != NULL) {
            Node* next = current->next;
            free(current);
            current = next;
        }
    }

    free(graph->adjList);
    free(graph->distance);
    free(graph->predecessor);
    free(graph);
}

void freeMinHeap(MinHeap* heap) {
    // Free allocated memory for min heap
    free(heap->array);
    free(heap);
}
