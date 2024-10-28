#include "util.h"
#include "data_structures.h"
#include <cstdio>

// Function to read input from a file and initialize the heap and elements
void readInputFile(const char *filename, ELEMENT ***V, HEAP **pHeap) {
    FILE *infile = fopen(filename, "r");
    if (!infile) {
        fprintf(stderr, "Error: Cannot open input file\n");
        return;
    }

    int n;
    fscanf(infile, "%d", &n);

    *V = new ELEMENT*[n + 1];
    for (int i = 1; i <= n; ++i) {
        (*V)[i] = new ELEMENT;
        fscanf(infile, "%lf", &(*V)[i]->key);
        (*V)[i]->index = i;
        (*V)[i]->pos = 0;
    }

    fclose(infile);

    *pHeap = new HEAP;
    (*pHeap)->capacity = n;
    (*pHeap)->size = 0;
    (*pHeap)->H = new int[n + 1];
}

// Function to print the array of elements
void printArray(ELEMENT **V, int n) {
    if (V == NULL) {
        fprintf(stderr, "Error: array is NULL\n");
        return;
    }
    printf("Instruction: PrintArray\n");
    for (int i = 1; i <= n; ++i) {
        printf("%d %lf %d\n", i, V[i]->key, V[i]->pos);
    }
}

// Function to print the heap structure
void printHeap(HEAP *pHeap, ELEMENT **V) {
    if (pHeap == NULL) {
        fprintf(stderr, "Error: heap is NULL\n");
        return;
    }
    printf("Instruction: PrintHeap\n");
    printf("Capacity = %d, size = %d\n", pHeap->capacity, pHeap->size);
    for (int i = 1; i <= pHeap->size; ++i) {
        printf("H[%d] = %d\n", i, pHeap->H[i]);
    }
}

// Function to write the array of elements to an output file
void writeOutputFile(const char *filename, ELEMENT **V, int n) {
    FILE *outfile = fopen(filename, "w");
    if (!outfile) {
        fprintf(stderr, "Error: Cannot open output file\n");
        return;
    }
    printf("Instruction: Write\n");
    for (int i = 1; i <= n; ++i) {
        fprintf(outfile, "%d %lf %d\n", i, V[i]->key, V[i]->pos);
    }
    fclose(outfile);
}
