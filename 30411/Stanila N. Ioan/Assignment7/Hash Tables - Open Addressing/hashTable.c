#include "hashTable.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>


void initHashTable(int N)
{
    //! initialize hash table with length "INITIAL_HT_SIZE_FACTOR" of N (1/4 of N)
    size = INITIAL_HT_SIZE_FACTOR*N;
    hashTable = (char**)malloc(size*sizeof(char*));
    for (int i = 0; i < size; i++) {
        *(hashTable + i) = (char*)malloc(65*sizeof(char));
        hashTable[i][0] = '\0';
    }
}

float getFillFactor()
{
    //! return the fill factor of the hash table
    float fillFactor = -1;
    int positionsOccupied = 0;
    for (int i = 0; i < size; i++)
        if (hashTable[i][0] != '\0')
            positionsOccupied++;
    fillFactor = (float)positionsOccupied/(float)size;
    return fillFactor;
}

void resizeHashTable()
{
    //! reconstruct the hash table by (usually) doubling its size
    //! only call this when the current fill factor of your hash table > MAX_FILL_FACTOR

    //! careful, when resizing, the 'size' variable should be changed as well such that the 'hashFunction's distribution will work
    //! be double careful! all the elements which are already in the hash table have to  be RE-hashed! (explanation @ lab)
    printf("Expanding the table and rehashing\n");
    int initSize = size;
    size *= 2;
    char** hashTableAux = (char**)malloc(size*sizeof(char*));
    for (int i = 0; i < size; i++) {
        *(hashTableAux + i) = (char*)malloc(66*sizeof(char));
        hashTableAux[i][0] = '\0';
    }
    char** aux = hashTable;
    hashTable = hashTableAux; //new one
    hashTableAux = aux; //old one
    for (int i = 0; i < initSize; i++) {
        insertElement(hashTableAux[i]);
    }
    for (int i = 0; i < initSize; i++)
            free(hashTableAux[i]);
    free(hashTableAux);
    printf("Done!\n");
}

int insertElement(char * element)
{
    //! insert an element
    //! returns the number of collisions which occurred before the element was inserted
    int i = 0;
    int key = hashFunction4(element, i);
    while (i < size && hashTable[key][0] != '\0') {
        i++;
        key = hashFunction4(element, i);
    }
    strcpy(hashTable[key], element);
    return i;
}

int hashFunction1(char * content, int i)
{
    int length = strlen(content);
    int k, sum;
    for (sum=0, k=0; k < length; k++)
    {
        sum += content[k];
    }
    return (sum + i) % size;
}

int hashFunction2(char * content, int i)
{
    long sum = 0;
    long mult = 1;
    for (int j = 0; j < 16; j++) {
        mult = 1;
        for (int k = 0; k < 3; k++) {
            sum += content[j + k] * mult;
            mult += 256;
        }
    }
    mult = 1;
    for (int j = 0; j < 63; j++) {
        sum += content[j]*mult;
        mult *= 256;
    }
    return (abs(sum) + i) % size;
}

int hashFunction3(char* content, int i) {
    /* Bernstein hash */
    long hash = 5381;
    char* str = content;

    while (*str) {
        hash = ((hash << 5) + hash) + (int)(*str); /* hash * 33 + c */
        str++;
    }
    return (abs(hash) + i)%size;
}

int hashFunction4(char * content, int i) {
    /* Modified One-at-a-Time hash */
    unsigned long hash = 186526133;
    for (int i = 0; i < 64; i++) {
        hash += content[i];
        hash += hash<<10;
        hash ^= hash<<6;
    }
    hash += (hash << 3);
    hash ^= (hash >> 11);
    hash += (hash << 15);
    return (abs(hash) + i)%size;
}