#include "hashTable.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

const float INITIAL_HT_SIZE_FACTOR = .33;

void initHashTable(int N)
{
    //! initialize hash table with length "INITIAL_HT_SIZE_FACTOR" of N (1/3 of N)
    //! also the size variable has to be initialized
    size=INITIAL_HT_SIZE_FACTOR*N;
    hashTable=(listT*)malloc(size*sizeof(listT));
    int i;
    for(i=0;i<size;i++)
    {
        hashTable[i].head=hashTable[i].tail=NULL;
        hashTable[i].size=0;
    }
}

void insertElement(char * element)
{
    //! insert an element
    int i=0;
    int key=hashFunction(element,i);
    addToList(&hashTable[key],element);
}

int hashFunction(char * content, int i)
{
    //! keep in mind, size in this case simply means the number of buckets
    long sum=0;
    int j;
    for(j=0;j<strlen(content);j++)
    {
        sum+=content[j];
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
    int size_max=0;
    int i,j;
    for(i=0;i<size;i++)
        if(hashTable[i].size>size_max)
            size_max=hashTable[i].size;
    for(i=0;i<size;i++)
    {
        printf("B%d: ",i);
        int a=(float)hashTable[i].size/size_max*40.0;
        for(j=0;j<a;j++)
            printf("*");
        printf("\n");
    }

}
