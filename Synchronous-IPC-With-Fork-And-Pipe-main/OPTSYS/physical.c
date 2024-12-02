#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "encDec.h"

// Function to convert a character to a binary bit pattern
void charToBinary(char c, char* binary) {
    for (int i = 7; i >= 0; i--) {
        binary[7 - i] = ((c >> i) & 1) ? '1' : '0';
    }
    binary[8] = '\0';
}

// Function to convert a binary bit pattern to a character
char binaryToChar(const char* binary) {
    char c = 0;
    for (int i = 0; i < 8; i++) {
        c = (c << 1) | (binary[i] - '0');
    }
    return c;
}

// Function to include a parity bit in a binary pattern
void includeParityBit(char* binary) {
    int count = 0;
    for (int i = 0; i < 8; i++) {
        if (binary[i] == '1') {
            count++;
        }
    }

    // Set the parity bit to '0' or '1' based on even or odd count
    if (count % 2 == 0) {
        binary[8] = '0';
    } else {
        binary[8] = '1';
    }
}

// Function to check and remove the parity bit from a binary pattern
char checkAndRemoveParity(char* binary) {
    int count = 0;
    for (int i = 0; i < 8; i++) {
        if (binary[i] == '1') {
            count++;
        }
    }

    // Check parity bit
    if ((count % 2 == 0 && binary[8] == '0') || (count % 2 == 1 && binary[8] == '1')) {
        // Parity bit is valid, remove it
        binary[8] = '\0';
        return binaryToChar(binary);
    } else {
        // Parity error, return an error character or handle as needed
        return '?'; // Replace with appropriate error handling
    }
}
