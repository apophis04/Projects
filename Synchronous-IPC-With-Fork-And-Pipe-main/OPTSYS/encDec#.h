#ifndef ENCDEC_H
#define ENCDEC_H

// Function prototypes for the Physical Layer
void charToBinary(char character, char binary[8]);
char binaryToChar(const char binary[8]);
char addParityBit(char character);
char removeParityBit(char character);

#endif
