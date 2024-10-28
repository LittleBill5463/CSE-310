#include "main.h"
#include "heap.h"
#include "util.h"
#include "data_structures.h"
#include <cstdio>
#include <cstring>

// Function to process instructions from standard input
void processInstructions(const char *inputFile, const char *outputFile) {
    ELEMENT **V = nullptr;
    HEAP *pHeap = nullptr;

    char instruction[20];
    while (scanf("%s", instruction) != EOF) {
        if (strcmp(instruction, "Stop") == 0) {
            printf("Instruction: Stop\n");
            break;
        } else if (strcmp(instruction, "Read") == 0) {
            printf("Instruction: Read\n");
            readInputFile(inputFile, &V, &pHeap);
        } else if (strcmp(instruction, "PrintArray") == 0) {
            printArray(V, pHeap->capacity);
        } else if (strcmp(instruction, "PrintHeap") == 0) {
            printHeap(pHeap, V);
        } else if (strcmp(instruction, "BuildHeap") == 0) {
            fflush(stdout);
            buildHeap(pHeap, V);
        } else if (strcmp(instruction, "Insert") == 0) {
            int index;
            scanf("%d", &index);
            insertElement(pHeap, V, index);
        } else if (strcmp(instruction, "ExtractMin") == 0) {
            extractMin(pHeap, V);
        } else if (strcmp(instruction, "DecreaseKey") == 0) {
            int index;
            double newKey;
            scanf("%d %lf", &index, &newKey);
            decreaseKey(pHeap, V, index, newKey);
        } else if (strcmp(instruction, "Write") == 0) {
            writeOutputFile(outputFile, V, pHeap->capacity);
        } else {
            printf("Warning: Invalid Instruction\n");
        }
    }

    // Free allocated memory
    for (int i = 1; i <= pHeap->capacity; ++i) {
        delete V[i];
    }
    delete[] V;
    delete[] pHeap->H;
    delete pHeap;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: ./PJ3 <I-File> <O-File>\n\n <I-File> is the input file\n\n <O-File> is the output file\n");
        return 1;
    }

    processInstructions(argv[1], argv[2]);

    return 0;
}
