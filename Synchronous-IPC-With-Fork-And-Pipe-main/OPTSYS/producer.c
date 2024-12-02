#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include "encDec.h"

#define MAX_BUF 1024

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Usage: %s input_filename output_filename\n", argv[0]);
        return 1;
    }

    char *inputFileName = argv[1];
    char *outputFileName = argv[2];

    // Read data from the input file
    char *input = readFile(inputFileName);
    if (input == NULL)
    {
        printf("Error reading input file.\n");
        return 1;
    }

    int charSize = strlen(input);

    for (int i = 0; i < charSize; i++)
    {
        char *binaryChar = charToBinary(input[i]);

        // Write the binary character to the output file
        writeFile(outputFileName, binaryChar);

        // Free the memory allocated for binaryChar
        free(binaryChar);

        sleep(1); // Sleep for 1 second (adjust as needed)
    }

    return 0;
}
