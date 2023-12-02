#include "utility.h"
#include "minheap.h"
#include "graph.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    // Parse command line arguments
    CommandLineArgs args = parseCommandLine(argc, argv);

    // Read the graph from the file
    FILE* file = fopen(args.graphFileName, "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Unable to open file %s\n", args.graphFileName);
        return EXIT_FAILURE;
    }

    int n, m;
    fscanf(file, "%d %d", &n, &m);

    Graph* graph = createGraph(n);
    MinHeap* heap = initializeMinHeap(n);

    int edgeId, u, v;
    float weight;
    for (int i = 0; i < m; ++i) {
        fscanf(file, "%d %d %d %f", &edgeId, &u, &v, &weight);
        addEdge(graph, edgeId, u, v, weight);
    }

    fclose(file);

    // Process queries
    while (1) {
        // Read query type
        char queryType[10];
        scanf("%s", queryType);

        if (strcmp(queryType, "find") == 0) {
            // Process find query
            int source, destination, flag;
            scanf("%d %d %d", &source, &destination, &flag);

            if (source < 0 || source >= n || destination < 0 || destination >= n || (flag != 0 && flag != 1)) {
                printQueryError();
                continue;
            }

            processDijkstra(graph, source, destination, flag, heap);
        } else if (strcmp(queryType, "write") == 0) {
            // Process write query
            char writeType[10];
            scanf("%s", writeType);

            if (strcmp(writeType, "path") == 0) {
                int s, d;
                scanf("%d %d", &s, &d);

                writePath(graph, s, d);
            } else {
                fprintf(stderr, "Error: Invalid write query\n");
            }
        } else if (strcmp(queryType, "stop") == 0) {
            // Free allocated memory and exit
            freeGraph(graph);
            freeMinHeap(heap);
            return EXIT_SUCCESS;
        } else {
            fprintf(stderr, "Error: Invalid query type\n");
        }
    }

    return EXIT_SUCCESS;
}
