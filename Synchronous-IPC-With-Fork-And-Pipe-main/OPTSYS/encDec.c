#include "encDec.h"
#include <stdio.h>
#include <string.h>

char* charToBinary(char s)
{
    char *binary = malloc(9); // 8 bits + null terminator
    strcpy(binary, "");
    int i;

    for(i = 7; i >= 0; --i)
    {
        if (s & (1 << i))
        {
            strcat(binary, "1");
        }
        else
        {
            strcat(binary, "0");
        }
    }

    addParityBit(binary);
    return binary;
}

void addParityBit(char *arr)
{
    int s = strlen(arr);
    int i, c = 0;
    for(i = 0; i < s; i++)
    {
        if(arr[i] == '1')
        {
            c++;
        }
    }
    if(c % 2 == 0)
    {
        arr[0] = '1';
    }
}

void removeParityBit(char *arr)
{
    int s = strlen(arr);
    int i, c = 0;
    for(i = 1; i < s; i++)
    {
        if(arr[i] == '1')
        {
            c++;
        }
    }
    if(c % 2 == 0)
    {
        arr[0] = '0';
    }
}

int binaryToDecimal(char* n)
{
    int dec_value = 0;
    int base = 1; // Initializing base value to 1, i.e., 2^0
    removeParityBit(n);

    int len = strlen(n);
    for (int i = len - 1; i >= 0; i--)
    {
        if (n[i] == '1')
        {
            dec_value += base;
        }
        base = base * 2;
    }

    return dec_value;
}

char *readFile(const char *fileName)
{
    FILE *file = fopen(fileName, "r");
    char *code;
    size_t n = 0;
    int c;

    if (file == NULL)
    {
        printf("Not Open\n");
        return NULL; // Could not open file
    }

    code = malloc(1000);

    while ((c = fgetc(file)) != EOF)
    {
        code[n++] = (char) c;
    }

    // Don't forget to terminate with the null character
    code[n] = '\0';
    fclose(file);
    return code;
}

void writeFile(const char *fileName, const char *str)
{
    FILE *file = fopen(fileName, "a");
    size_t n = strlen(str);
    int i;

    if (file == NULL)
    {
        return; // Could not open file
    }

    for(i = 0; i < n; i++)
    {
        fprintf(file, "%c", str[i]);
    }
    fclose(file);
}
