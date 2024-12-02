#ifndef ENCDEC_H
#define ENCDEC_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert a character to its 8-bit binary representation with a parity bit
char* charToBinary(char s);

// Function to convert an 8-bit binary string to its decimal value (with a parity bit)
int binaryToDecimal(char* n);

// Function to read the content of a file and return it as a string
char* readFile(const char *fileName);

// Function to write a string to a file
void writeFile(const char *fileName, const char *str);

// Function to add a parity bit to an 8-bit binary string
void addParityBit(char *arr);

// Function to remove the parity bit from an 8-bit binary string
void removeParityBit(char *arr);

#endif
