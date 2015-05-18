#include "hashTable.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void initHashTable(int N)
{
    //! initialize hash table with length "INITIAL_HT_SIZE_FACTOR" of N (1/4 of N)
    int i;

    size = N*INITIAL_HT_SIZE_FACTOR;

    hashTable=(char **)calloc(size, sizeof(char *));
    for (i=0; i<size; i++)
    {
        hashTable[i]=(char *)calloc(65, sizeof(char));
    }
}

float getFillFactor()
{
    //! return the fill factor of the hash table
    float fillFactor = -1;
    int full, i;

    full = 0;
    for (i=0; i<size; i++)
    {
        if (hashTable[i][0] != '\0') //as long as we find elements
            full++;
    }
    fillFactor=(float)((float)full/(float)size);
    return fillFactor;
}

void resizeHashTable()
{
    //! reconstruct the hash table by (usually) doubling its size
    //! only call this when the current fill factor of your hash table > MAX_FILL_FACTOR

    //! careful, when resizing, the 'size' variable should be changed as well such that the 'hashFunction's distribution will work
    //! be double careful! all the elements which are already in the hash table have to  be RE-hashed! (explanation @ lab)
    char **AuxHashTable;
    char **aux; //i use this to manage to interchange my tables without losing them
    int AuxSize, i;

    AuxSize = size;
    size = size*2;
    AuxHashTable=(char **)calloc(size, sizeof(char *));
    for (i=0; i<size; i++)
    {
        AuxHashTable[i]=(char *)calloc(65, sizeof(char));
    }
    aux = hashTable;
    hashTable=AuxHashTable;
    AuxHashTable = aux;

    for (i=0; i<size; i++)
    {
        if (hashTable[i][0] != 0)
            insertElement(AuxHashTable[i]);
    }
    for (i=0; i<AuxSize; i++)
    {
        free(AuxHashTable[i]);
    }
    free(AuxHashTable);
}

int insertElement(char * element)
{
    //! insert an element
    //! returns the number of collisions which occurred before the element was inserted
    int i, pos;

    i = 0;
    pos = hashFunction3(element, i);
    while (i<size && hashTable[pos][0] != 0)
    {
        i++; //number of collisions
        pos=hashFunction3(element,i);
    }
    hashTable[pos]=element;
    return i;
}

//hash Functions

int hashFunction1(char * content, int i)
{
    int j;
    unsigned int hash1 = 0;
    for (j = 0 ; content[j] != '\0' ; j++)
    {
        hash1 = 31*hash1 + content[j];
    }

    return (hash1 + i) % size;
}

int hashFunction2(char *content, int i)
{
    int hash1=0;
    int j;

    for (j=0; content[j]!='\0'; j++)
    {
        hash1=(hash1*121+ content[j])%9917;
    }
    return ((hash1 +i )% size);
}

int hashFunction3(char *content, int i)
{
    int hash1=7;
    int j;

    for (j=0; content[j]!='\0'; j++)
    {
        hash1=(hash1*239+ content[j])%98997;
    }
    return ((hash1 +i )% size);
}
