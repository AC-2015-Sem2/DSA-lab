#include "hashTable.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

void initHashTable(int N)
{
    //! initialize hash table with length "INITIAL_HT_SIZE_FACTOR" of N (1/3 of N)
    //! also the size variable has to be initialized

    size = INITIAL_HT_SIZE_FACTOR * N;
    hashTable = (listT*)malloc(sizeof(listT)*size);

    int i;

    for(i=0; i<size; i++)
    {
        hashTable[i].head = NULL;
        hashTable[i].tail = NULL;
        hashTable[i].size = 0;
    }

}

void insertElement(char * element)
{
    //! insert an element

    int resPos;

    resPos = hashFunction3(element, 0);

    addToList(&hashTable[resPos], element);

}

int hashFunction3(char * content, int i)
{
    int h = 0, k;
    for(k = strlen(content)-1; k >= 0; k--)
        h = (content[i] + 128 * h) % size;
    return (h+i)%size;
}

int hashFunction2(char * content, int i)
{
    int hash=0;
    hash += content[0];
    hash += (hash << 3);
    hash ^= (hash >> 11);
    hash += (hash << 15);
    hash += content[1];
    hash += 2;
    return (hash+i)%size;
}

int hashFunction0(char * content, int i)
{
    return 2%size;
}
int hashFunction1(char * content, int i)
{
    int length = strlen(content);
    int k, sum;
    for (sum=0, k=0; k < length; k++)
    {
        sum += content[k];
    }
    return (sum+i) % size;
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
    int totalSize=0, i;
    float meanSize;

    for(i=0; i<size; i++)
        totalSize += hashTable[i].size;

    meanSize = (float)totalSize / (float)size;

    float sqTotal=0, variance;

    for(i=0; i<size; i++)
        sqTotal += (hashTable[i].size - meanSize) * (hashTable[i].size - meanSize);

    variance = sqTotal / (float)size;

    float fillPerBucket, maxFill=0;

    for(i=0; i<size; i++)
        if(hashTable[i].size > maxFill)
            maxFill = hashTable[i].size;

    for(i=0; i<size; i++)
    {
        printf("%d: ", i);
        fillPerBucket = hashTable[i].size / maxFill * 40.00;
        int j;
        for(j=0; j<fillPerBucket; j++)
            printf("*");
        printf(" (%.1f %%)\n", fillPerBucket / 40.00 * 100.00);
    }


    printf("Variance: %.3f\n", variance);
    printf("Standard deviation: %.3f", sqrt(variance));
}
