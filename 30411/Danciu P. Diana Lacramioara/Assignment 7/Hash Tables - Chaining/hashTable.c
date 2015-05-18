#include "hashTable.h"
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

listT * hashTable;
int size;

void initHashTable(int N)
{
    //! initialize hash table with length "INITIAL_HT_SIZE_FACTOR" of N (1/3 of N)
    //! also the size variable has to be initialized
    int i;

    size = N*INITIAL_HT_SIZE_FACTOR;
    hashTable = (listT *)calloc(size, sizeof(listT));
    for (i=0; i<size; i++)
    {
        hashTable[i].head = NULL;
        hashTable[i].tail = NULL;
        hashTable[i].size = 0;
    }
}

void insertElement(char * element)
{
    //! insert an element
    int pos;

    pos = hashFunction(element, 0);
    addToList(&hashTable[pos], element);
}

int hashFunction(char * content, int i)
{
    //! keep in mind, size in this case simply means the number of buckets
    int length = strlen(content);
    int k, sum;
    sum = 0;
    for (k=0; k < length; k++)
    {
        sum += content[k];
    }
    return (sum % size);
}

void computeDistributionsPerBucket()
{
    //! computes the distribution of elements for each bucket
    //! the output should look something like this:
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
    int MAX,i;
    int j, pro;
    MAX = 0;
    for (i=0; i<size; i++)
    {
        if (hashTable[i].size > MAX)
            MAX = hashTable[i].size;
    }
    for (i=0; i<size; i++)
    {
        printf ("B%d : ", i);
        pro = hashTable[i].size/MAX * 20;
        for (j=0; j<pro; j++)
            printf("*");
        printf("   (~%g%%) \n", (float)pro);
    }
}
