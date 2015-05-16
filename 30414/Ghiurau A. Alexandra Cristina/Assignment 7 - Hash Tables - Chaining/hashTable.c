#include "hashTable.h"
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
//ascii a : 97, z: 122

void initHashTable(int N, int nrOfBuckets)
{
    //! initialize hash table with length "INITIAL_HT_SIZE_FACTOR" of N (1/3 of N)
    //! also the size variable has to be initialized

    int i;
    hashTable=(listT*)malloc(sizeof(listT)*nrOfBuckets);
    //! https://imgflip.com/i/ll5so  OR
    //! https://imgflip.com/i/ll5wy
    for(i=0; i<nrOfBuckets; i++)
    {
        hashTable[i].head = NULL;
        hashTable[i].tail = NULL;
        hashTable[i].size = 0;
    }
}

void insertElement(char * element, int nrOfBuckets)
{
    //! insert an element

    int index = hashFunction(element, nrOfBuckets);
    addToList(&hashTable[index], element);
}
/*
int hashFunction(char * content, int i)
{
    //! keep in mind, size in this case simply means the number of buckets

    return i % size;
}
*/
int hashFunction(char * content, int nrOfBuckets)
{
    int length = strlen(content);
    int k, sum;
    for (sum=0, k=0; k < length; k++)
    {
        sum += content[k];
    }
    return  sum % nrOfBuckets;
}

double square(double x)
{
    return x * x;
}

void computeDistributionsPerBucket(int N, int nrOfBuckets)
{
    int i;

    int maxElements = 0;
    for(i=0; i<nrOfBuckets; i++)
    {
        if(maxElements< hashTable[i].size)
            maxElements = hashTable[i].size;
    }

    /** regula de 3 simplă:
    maxElements -> maxStars
    hashTable[i].size -> x
    */

    int maxStars = 30;
    int x;
    int j;

    for(i=0; i<nrOfBuckets; i++)
    {
        printf("%3d: ", i);
        x = (double)hashTable[i].size * ((double)maxStars / (double)maxElements);

        for(j=0; j<x; j++)
        {
            printf("$");
        }
        for(j=x; j<maxStars; j++)
        {
            printf(" ");
        }
        printf("# ~%8.2lf%% full\n", 100 * (double)hashTable[i].size /(double)maxElements);
    }
    /*
    printf("\n maxStarts = %d",maxStars );
    printf("\n maxElements =  %d",maxElements );

    printf("\n x= %d", x);
    */

    //! to compute the distribution: sum -> average -> sum of deviations -> variance -> std deviation

    int sum = 0;
    double average = 0.0;
    double deviationsSum = 0.0;
    double variance = 0.0, stdDeviation = 0.0;

    for(i=0; i<nrOfBuckets; i++)
    {
        sum+= hashTable[i].size;
    }

    average = (double)sum / (double)N;

    for(i=0; i<nrOfBuckets; i++)
    {
        deviationsSum += square(hashTable[i].size - average);
    }

    variance = deviationsSum / (double)N;

    stdDeviation = sqrt(variance);

    printf("\nstdDev: %f", stdDeviation);
}
