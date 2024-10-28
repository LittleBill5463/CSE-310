#include "heap.h"
#include "data_structures.h" // Include data_structures.h to use ELEMENT and HEAP
#include <cstdio>

// Function to maintain the heap property by moving the element at index i down the heap
void heapifyDown(HEAP *pHeap, ELEMENT **V, int i) {
    int smallest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left <= pHeap->size && V[pHeap->H[left]]->key < V[pHeap->H[smallest]]->key) {
        smallest = left;
    }
    if (right <= pHeap->size && V[pHeap->H[right]]->key < V[pHeap->H[smallest]]->key) {
        smallest = right;
    }
    if (smallest != i) {
        int temp = pHeap->H[i];
        pHeap->H[i] = pHeap->H[smallest];
        pHeap->H[smallest] = temp;

        V[pHeap->H[i]]->pos = i;
        V[pHeap->H[smallest]]->pos = smallest;

        heapifyDown(pHeap, V, smallest);
    }
}

// Function to maintain the heap property by moving the element at index i up the heap
void heapifyUp(HEAP *pHeap, ELEMENT **V, int i) {
    while (i > 1 && V[pHeap->H[i]]->key < V[pHeap->H[i / 2]]->key) {
        int temp = pHeap->H[i];
        pHeap->H[i] = pHeap->H[i / 2];
        pHeap->H[i / 2] = temp;

        V[pHeap->H[i]]->pos = i;
        V[pHeap->H[i / 2]]->pos = i / 2;

        i = i / 2;
    }
}

// Function to build a heap from an unordered array
void buildHeap(HEAP *pHeap, ELEMENT **V) {
    printf("Instruction: BuildHeap\n");
    fflush(stdout);

    // Set the heap size to the number of elements
    pHeap->size = pHeap->capacity;

    // Initialize the heap array
    for (int i = 1; i <= pHeap->size; ++i) {
        pHeap->H[i] = i;
        V[i]->pos = i;
    }

    // Apply the heapify process from the last non-leaf node up to the root
    for (int i = pHeap->size / 2; i >= 1; --i) {
        heapifyDown(pHeap, V, i);
    }
}


// Function to insert an element into the heap
void insertElement(HEAP *pHeap, ELEMENT **V, int index) {
    if (index < 1 || index > pHeap->capacity) {
        fprintf(stderr, "Error: index out of bound\n");
        return;
    }
    if (V[index]->pos != 0) {
        fprintf(stderr, "Error: V[index] already in the heap\n");
        return;
    }
    pHeap->size++;
    pHeap->H[pHeap->size] = index;
    V[index]->pos = pHeap->size;
    heapifyUp(pHeap, V, pHeap->size);
    printf("Element V[%d] inserted into the heap\n", index);
}

// Function to extract the minimum element from the heap
void extractMin(HEAP *pHeap, ELEMENT **V) {
    printf("Instruction: ExtractMin\n");
    if (pHeap == NULL) {
        fprintf(stderr, "Error: heap is NULL\n");
        return;
    }
    if (pHeap->size == 0) {
        fprintf(stderr, "Error: heap is empty\n");
        return;
    }
    int minIndex = pHeap->H[1];
    pHeap->H[1] = pHeap->H[pHeap->size];
    V[pHeap->H[1]]->pos = 1;
    pHeap->size--;
    heapifyDown(pHeap, V, 1);
    V[minIndex]->pos = 0;
    printf("Element V[%d] extracted from the heap\n", minIndex);
}

// Function to decrease the key of an element in the heap
void decreaseKey(HEAP *pHeap, ELEMENT **V, int index, double newKey) {
    printf("Instruction: DecreaseKey %d %lf\n", index, newKey);
    if (index < 1 || index > pHeap->capacity || newKey >= V[index]->key) {
        fprintf(stderr, "Error: invalid call to DecreaseKey\n");
        return;
    }
    if (V[index]->pos == 0) {
        fprintf(stderr, "Error: V[index] not in the heap\n");
        return;
    }
    V[index]->key = newKey;
    heapifyUp(pHeap, V, V[index]->pos);
}
