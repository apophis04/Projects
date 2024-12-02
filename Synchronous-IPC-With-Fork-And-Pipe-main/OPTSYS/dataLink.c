#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "encDec.h"
#define MAX_FRAME_LENGTH 100
#define SYN 22

// Function to frame data (put SYN characters, LENGTH character, and data into a frame)
void frameData(const char* data, char* framedData, int* frameLength) {
    int dataLength = strlen(data);

    // Check data length; frame can't exceed MAX_FRAME_LENGTH
    if (dataLength > MAX_FRAME_LENGTH - 3) {
        fprintf(stderr, "Data too long to frame\n");
        exit(1);
    }

    // Add SYN characters and LENGTH character
    framedData[0] = SYN;
    framedData[1] = SYN;
    framedData[2] = (char)dataLength;

    // Copy data into the frame
    strcpy(&framedData[3], data);

    // Calculate the frame length
    *frameLength = dataLength + 3;
}

// Function to deframe data (separate control characters from data characters)
void deframeData(const char* framedData, char* data) {
    // Check for SYN characters at the beginning of the frame
    if (framedData[0] != SYN || framedData[1] != SYN) {
        fprintf(stderr, "Invalid frame format\n");
        exit(1);
    }

    int dataLength = (int)framedData[2];

    // Check data length; frame can't exceed MAX_FRAME_LENGTH
    if (dataLength > MAX_FRAME_LENGTH - 3) {
        fprintf(stderr, "Data too long to deframe\n");
        exit(1);
    }

    // Copy data from the frame (excluding control characters)
    strcpy(data, &framedData[3]);
    data[dataLength] = '\0'; // Null-terminate the data
}
