// minheap.c

#include "minheap.h"
#include <stdio.h>
#include <stdlib.h>

// Function to create a new heap node
HeapNode* createHeapNode(int vertex, float key) {
    HeapNode* node = (HeapNode*)malloc(sizeof(HeapNode));
    if (node == NULL) {
        fprintf(stderr, "Memory allocation error\n");
        exit(EXIT_FAILURE);
    }

    node->vertex = vertex;
    node->key = key;

    return node;
}

// Function to create a new min heap
MinHeap* createMinHeap(int capacity) {
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

// Function to swap two heap nodes
void swapHeapNodes(HeapNode** a, HeapNode** b) {
    HeapNode* temp = *a;
    *a = *b;
    *b = temp;
}

// Function to heapify a subtree with the root at the given index
void heapify(MinHeap* heap, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < heap->size && heap->array[left]->key < heap->array[smallest]->key) {
        smallest = left;
    }

    if (right < heap->size && heap->array[right]->key < heap->array[smallest]->key) {
        smallest = right;
    }

    if (smallest != index) {
        swapHeapNodes(&heap->array[index], &heap->array[smallest]);
        heapify(heap, smallest);
    }
}

// Function to insert a new key into the min heap
void insertHeap(MinHeap* heap, int vertex, float key) {
    if (heap->size == heap->capacity) {
        fprintf(stderr, "Heap overflow\n");
        exit(EXIT_FAILURE);
    }

    HeapNode* node = createHeapNode(vertex, key);
    heap->size++;
    int i = heap->size - 1;
    heap->array[i] = node;

    // Fix the min heap property if it is violated
    while (i != 0 && heap->array[(i - 1) / 2]->key > heap->array[i]->key) {
        swapHeapNodes(&heap->array[i], &heap->array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Function to decrease the key value of a given vertex
void decreaseKey(MinHeap* heap, int vertex, float newKey) {
    int i;
    for (i = 0; i < heap->size; i++) {
        if (heap->array[i]->vertex == vertex) {
            break;
        }
    }

    heap->array[i]->key = newKey;

    // Fix the min heap property if it is violated
    while (i != 0 && heap->array[(i - 1) / 2]->key > heap->array[i]->key) {
        swapHeapNodes(&heap->array[i], &heap->array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Function to extract the node with the minimum key value
HeapNode* extractMin(MinHeap* heap) {
    if (heap->size == 0) {
        return NULL;
    }

    if (heap->size == 1) {
        heap->size--;
        return heap->array[0];
    }

    HeapNode* root = heap->array[0];
    heap->array[0] = heap->array[heap->size - 1];
    heap->size--;
    heapify(heap, 0);

    return root;
}

// Function to check if the given vertex is in the min heap
int isInHeap(MinHeap* heap, int vertex) {
    for (int i = 0; i < heap->size; i++) {
        if (heap->array[i]->vertex == vertex) {
            return 1;
        }
    }
    return 0;
}

// Function to check if the min heap is empty
int isEmptyHeap(MinHeap* heap) {
    return heap->size == 0;
}

// Function to free allocated memory for the min heap
void freeMinHeap(MinHeap* heap) {
    free(heap->array);
    free(heap);
}

