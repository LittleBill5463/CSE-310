#ifndef UTIL_H
#define UTIL_H

#include "data_structures.h"

void readInputFile(const char *filename, ELEMENT ***V, HEAP **pHeap);
void printArray(ELEMENT **V, int n);
void printHeap(HEAP *pHeap, ELEMENT **V);
void writeOutputFile(const char *filename, ELEMENT **V, int n);

#endif // UTIL_H


