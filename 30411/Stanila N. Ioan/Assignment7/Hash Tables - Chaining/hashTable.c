#include "hashTable.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void initHashTable(int N)
{
    //! initialize hash table with length "INITIAL_HT_SIZE_FACTOR" of N (1/3 of N)
    //! also the size variable has to be initialized
    size = INITIAL_HT_SIZE_FACTOR*N;
    hashTable = (listT*)malloc(size*sizeof(listT));
    for (int i = 0; i < size; i++) {
        hashTable[i].head = hashTable[i].tail = NULL;
        hashTable[i].size = 0;
    }
}

void insertElement(char * element)
{
    //! insert an element
    int i = 0;
    int key = hashFunction(element, i);
    addToList(&hashTable[key], element);
}

int hashFunction(char * content, int i)
{
    //! keep in mind, size in this case simply means the number of buckets
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
    /*
    int sum = 0;
    for (int j = 0; j < 64; j++)
        sum += (int)content[j];
    */
    return (abs(sum) + i) % size;
}

void computeDistributionsPerBucket()
{
    //! computes the distribution of elements for each bucket
    //! the output should look something like:
    /**
        MAX = 'x' * 20

        B0: ********** (~50%)
        B1: ************ (~60%)
        B2: ****** (~30%)
        B3: ******* (~35%)
        .....


        hint : the bigger you choose X, the better approximation
        hint2: choose it somewhere between 20-40 such that it fits in one row in the console nicely
    */
    int maxSize = 0;
    for (int i = 0; i < size; i++)
        if (hashTable[i].size > maxSize)
            maxSize = hashTable[i].size;
    for (int i = 0; i < size; i++) {
        printf("B%i: ", i);
        int lev = (float)hashTable[i].size/maxSize * 40.0;
        for (int j = 0; j < lev; j++)
            printf("*");
        printf("\n");
    }
}
