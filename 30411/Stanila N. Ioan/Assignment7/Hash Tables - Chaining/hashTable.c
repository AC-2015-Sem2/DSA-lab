#include "hashTable.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

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
    int key = hashFunction4(element);
    addToList(&hashTable[key], element);
}

int hashFunction0(char * content) {
    return content[0]/4 % size;
}

int hashFunction1(char * content)
{
    int length = strlen(content);
    int k, sum;
    for (sum=0, k=0; k < length; k++)
    {
        sum += content[k];
    }
    return sum%size;
}

int hashFunction2(char * content)
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
    return abs(sum)%size;
}

int hashFunction3(char* content) {
    /* Bernstein hash */
    long hash = 5381;
    char* str = content;

    while (*str) {
        hash = ((hash << 5) + hash) + (int)(*str); /* hash * 33 + c */
        str++;
    }
    return abs(hash)%size;
}

int hashFunction4(char * content) {
    /* Slightly modified One-at-a-Time hash */
    unsigned long hash = 186526133;//initially 0
    for (int i = 0; i < 64; i++) {
        hash += content[i];
        hash += hash<<10;
        hash ^= hash<<6;
    }
    hash += (hash << 3);
    hash ^= (hash >> 11);
    hash += (hash << 15);
    return hash%size;
}

int hashFunction5(char * content) {
    /* My hash function */
    unsigned long hash = 73;
    unsigned long mult = 1;
    for (int i = 0; i < 64; i++) {
        hash = hash*31 + (~content[i])*mult;
        mult += 256;
    }
    hash += (~content[7])*13;
    return hash%size;
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
        int lev = (float)hashTable[i].size/maxSize * 60.0;
        for (int j = 0; j < lev; j++)
            printf("*");
        printf("\n");
    }
}
