#include "utility.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

CommandLineArgs parseCommandLine(int argc, char* argv[]) {
    CommandLineArgs args;

    // Check if the correct number of command line arguments is provided
    if (argc != 3) {
        fprintf(stderr, "Error: Invalid command line arguments.\n");
        fprintf(stderr, "Usage: %s <graph> <direction>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Store the graph file name
    args.graphFileName = strdup(argv[1]);

    // Store the direction (either "directed" or "undirected")
    args.direction = strdup(argv[2]);

    // Validate the direction argument
    if (strcmp(args.direction, "directed") != 0 && strcmp(args.direction, "undirected") != 0) {
        fprintf(stderr, "Error: Invalid direction argument. Use 'directed' or 'undirected'.\n");
        exit(EXIT_FAILURE);
    }

    return args;
}

void printQueryError() {
    fprintf(stderr, "Error: invalid find query\n");
}

void printPathError() {
    fprintf(stderr, "Error: no path computation done\n");
}

void printInvalidSourceDestError() {
    fprintf(stderr, "Error: invalid source destination pair\n");
}
