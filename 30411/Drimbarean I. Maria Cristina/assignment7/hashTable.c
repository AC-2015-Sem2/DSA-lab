#include "hashTable.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
void initHashTable(int N)
{
    //! initialize hash table with length "INITIAL_HT_SIZE_FACTOR" of N (1/3 of N)
    //! also the size variable has to be initialized
    size=N*INITIAL_HT_SIZE_FACTOR;
    hashTable=(listT*) malloc(sizeof(listT)*size);
    int i;
    for (i=0;i<size;i++)
    {
        hashTable[i].head=NULL;
        hashTable[i].tail=NULL;
        hashTable[i].size=0;
    }
}

void insertElement(char * element)
{
    //! insert an element
    int key=hashFunction(element,0);
    addToList(&hashTable[key],element);
}

int hashFunction(char * content, int i)
{
    //! keep in mind, size in this case simply means the number of buckets
    int length=strlen(content);
    int k;
    for (k=0;k<length;k++)
    {
      i+=content[k]*2654435761 % 2^32;
    }
    return i % size;
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
  FILE *f=fopen("out.txt","w");
   int i;
   int max=0;
   for (i=0;i<size;i++)
    if (max<hashTable[i].size)
      max=hashTable[i].size;
   for (i=0;i<size;i++)
    {
        int k=(float)hashTable[i].size /max*20.00;
        int j;
        fprintf(f,"\nB%d:",i);
        for (j=0;j<k;j++)
            fprintf(f,"*");
        fprintf(f,"(%d percent)",hashTable[i].size*100/max);
    }

}
