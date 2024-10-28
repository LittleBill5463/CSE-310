#ifndef HEAP_H
#define HEAP_H

#include "data_structures.h"

void heapifyDown(HEAP *pHeap, ELEMENT **V, int i);
void heapifyUp(HEAP *pHeap, ELEMENT **V, int i);
void buildHeap(HEAP *pHeap, ELEMENT **V);
void insertElement(HEAP *pHeap, ELEMENT **V, int index);
void extractMin(HEAP *pHeap, ELEMENT **V);
void decreaseKey(HEAP *pHeap, ELEMENT **V, int index, double newKey);

#endif // HEAP_H

