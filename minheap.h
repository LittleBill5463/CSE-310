// minheap.h

#ifndef MINHEAP_H
#define MINHEAP_H

// Structure to represent a node in the min heap
typedef struct HeapNode {
    int vertex;
    float key;
} HeapNode;

// Structure to represent a min heap
typedef struct MinHeap {
    int size;
    int capacity;
    HeapNode** array;
} MinHeap;

// Function prototypes
HeapNode* createHeapNode(int vertex, float key);
MinHeap* createMinHeap(int capacity);
void insertHeap(MinHeap* heap, int vertex, float key);
void decreaseKey(MinHeap* heap, int vertex, float newKey);
HeapNode* extractMin(MinHeap* heap);
int isInHeap(MinHeap* heap, int vertex);
int isEmptyHeap(MinHeap* heap);
void freeMinHeap(MinHeap* heap);

#endif // MINHEAP_H
