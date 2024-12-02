#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "encDec.h"
#define MAX_FRAME_LENGTH 100
// Function to read data to be transmitted from input data files in the producer
void readDataFromFile(const char* filename, char* data) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening input file %s\n", filename);
        exit(1);
    }

    // Read data from the file
    if (fgets(data, MAX_FRAME_LENGTH, file) == NULL) {
        fprintf(stderr, "Error reading data from input file %s\n", filename);
        fclose(file);
        exit(1);
    }

    fclose(file);
}

// Function to write received data into an output data file in the consumer
void writeDataToFile(const char* filename, const char* data) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        fprintf(stderr, "Error opening output file %s\n", filename);
        exit(1);
    }

    // Write data to the file
    if (fputs(data, file) == EOF) {
        fprintf(stderr, "Error writing data to output file %s\n", filename);
        fclose(file);
        exit(1);
    }

    fclose(file);
}
