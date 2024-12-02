#ifndef ENCDEC_H
#define ENCDEC_H

// Function prototypes
void frameData(const char *input, char *output, int *length);
void deframeData(const char *input, char *output);
char checkAndRemoveParity(char input);

// Add other function prototypes as needed

#endif
