#include "hashTable.h"
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void initHashTable(int N)
{
    //! initialize hash table with length "INITIAL_HT_SIZE_FACTOR" of N (1/3 of N)
    //! also the size variable has to be initialized
    size=0.33*N;
    int i;
    hashTable=(listT*)malloc(size *sizeof(listT));
    for(i=0; i<size; i++)
    {
        hashTable[i].head = NULL;
        hashTable[i].tail = NULL;
        hashTable[i].size = 0;
    }
}
void insertElement(char * element) //! insert an element
{

    int k=hashFunction(element);
    addToList(&hashTable[k],element);
}
int hashFunction(char* content)
{
    int k;
    int sum=0;
    int length = strlen(content);
    for (k=0; k < length; k++)
        sum =sum+ content[k];
    return sum % size;

}
void computeDistributionsPerBucket()
{
    int maxsize=0;
    int i;
    for (i=0; i<size; i++)
        if (hashTable[i].size>maxsize)
            maxsize=hashTable[i].size;
    for (i=0; i<size; i++)
    {
        printf("B%i: ", i);
        int y=(hashTable[i].size*30)/maxsize;  //! seems like 30 works pretty well
        int j;
        for (j = 0; j < y; j++)
            printf("*");
        printf("\n");

    }

}
double standardDeviation()
{
    int i;
    double average = 0;
    for (i = 0; i < size; i++)
        average=average+ hashTable[i].size;
    average=average/size;
    double averageDeviation = 0;
   for (i = 0; i < size; i++)
        averageDeviation=averageDeviation+ (hashTable[i].size - average)*(hashTable[i].size - average);
    averageDeviation /= size;
    return sqrt(averageDeviation);
}


