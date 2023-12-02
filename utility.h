#ifndef UTILITY_H
#define UTILITY_H

typedef struct {
    char* graphFileName;
    char* direction;
} CommandLineArgs;

// Function to parse command line arguments
CommandLineArgs parseCommandLine(int argc, char* argv[]);

// Function to print error message for invalid find query
void printQueryError();

// Function to print error message for no path computation done
void printPathError();

// Function to print error message for invalid source destination pair
void printInvalidSourceDestError();

#endif /* UTILITY_H */
