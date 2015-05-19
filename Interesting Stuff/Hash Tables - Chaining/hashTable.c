#include "hashTable.h"
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

void initHashTable(int N)
{
    size = INITIAL_HT_SIZE_FACTOR  * N;
    hashTable = (listT*)malloc(sizeof(listT)*size);
    int i;
    for(i=0;i<size;i++)
    {
        hashTable[i].head = NULL;
        hashTable[i].tail = NULL;
        hashTable[i].size = 0;
    }
    //! initialize hash table with length "INITIAL_HT_SIZE_FACTOR" of N (1/3 of N)
    //! also the size variable has to be initialized
}

void insertElement(char * element)
{
    int returned;
    returned = H3(element, 0);
    addToList(hashTable[returned], *element);
}

int H0(char *content, int i)
{
    const int nr = 5;
    return nr%size;
}

int H1(char *content, int i)
{
    int length = strlen(content);
    int k, sum;
    for (sum=0, k=0; k < length; k++)
   {
        sum += content[k];
    }
    return (sum+i) % size;
}

int H2(char *content, int i)
{
        int x;
        int c;
        while (c = *content++)
            x= c + (x << 6) + (x << 16) - x;
        return (x+i) % size;
    //idea from: http://www.cse.yorku.ca/~oz/hash.html
}

int H3(char *content, int i)
{
    int x = 0;
    int j;
    for(j = strlen(content)-1; j >= 0; j--)
        x = (content[i] + 128 * x) % size;
   return (x+i)%size;
   //source: http://courses.cs.washington.edu/courses/cse326/00wi/handouts/lecture15/sld013.htm
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
    float Mean;
    for(i=0; i<size; i++)
        totalSize += hashTable[i].size;
    Mean = (float)totalSize / (float)size;
    float sqTotal=0, variance;
    for(i=0; i<size; i++)
        sqTotal += (hashTable[i].size - Mean) * (hashTable[i].size - Mean);
    variance = sqTotal / (float)size;
    printf("Variance: %.2f\n", variance);
    printf("Standard deviation: %.2f", sqrt(variance));
}
