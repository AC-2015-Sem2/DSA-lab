#include "hashTable.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void initHashTable(int N)
{

    int i;
    size=INITIAL_HT_SIZE_FACTOR * N;
    hashTable = (char**)malloc(size*sizeof(char*));
    for (i=0; i<size; i++)
        hashTable[i]=NULL;
}

float getFillFactor()
{
    float fillFactor = -1;
    int filledSlotsOnHashTable = 0, i;
    for (i=0; i<size; i++)
    {
        if (hashTable[i]!=NULL)
            filledSlotsOnHashTable++;
    }
    float filledSlotsOnHashTableConvToFloat = (float)filledSlotsOnHashTable;
    float sizeConvToFloat = (float)size;
    if(filledSlotsOnHashTable!=0)
        fillFactor = filledSlotsOnHashTableConvToFloat/sizeConvToFloat;
    return fillFactor;
}
void resizeHashTable()
{
    int i=0;
    char ** oldHashTable = hashTable;
    size *=2;
    hashTable = (char**) malloc(size * sizeof(char*));

    for (i=0; i<size; i++)
        hashTable[i] = NULL;

    for (i=0; i<size/2; i++)
    {
        if (oldHashTable[i] != NULL)
            insertElement(oldHashTable[i]); // disperses the ellements in the new hasshtable
    }

    printf("\n The hash table size was doubled\n\n");
    nrOfResizes++;
}
int insertElement(char * element)
{
    int i=0;
    float fillFactor = getFillFactor();
    if (fillFactor> MAX_FILL_FACTOR)
        resizeHashTable();


    while(hashTable[hashFunction3(element, i)] != NULL)
        i++;
    hashTable[hashFunction3(element, i)] = element;
    return i;
}


int hashFunction1(char * content, int i)     //!-the starting one
{
    int length = strlen(content);
    int k, sum=0;
    for (k=0; k < length; k++)
    {
        sum+=content[k];
    }
    return (sum+i) % size;
}

int hashFunction2(char * content, int i) // xor hash
{
    int sum=0,j;
    for(j=0; j<strlen(content); j++)
    {
        sum ^= content[j];
    }
    return (sum+i) % size;
}

int hashFunction3(char * content, int j) // The shift add xor hash , seems to be the best for what I§ve  tried
{

    unsigned h = 0;
    int i;

    for (i = 0; i < strlen(content); i++)
    {
        h ^= (h << 5) + (h >> 2) + content[i];
    }

    return (h+j) % size;
}
int hashFunction4(char * content, int j) // The elf hash , seems to be the second best after the shift add xor
{
    unsigned h = 0, g;
    int i;

    for (i = 0; i < strlen(content); i++)
    {
        h = (h << 4) + content[i];
        g = h & 0xf0000000L;

        if (g != 0)
        {
            h ^= g >> 24;
        }

        h &= ~g;
    }


    return (h+j) % size;

}

