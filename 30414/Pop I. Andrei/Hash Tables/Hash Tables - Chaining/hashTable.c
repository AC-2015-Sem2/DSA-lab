#include "hashTable.h"
#include "io.h"
#include "list.h"
#include <math.h>

void initHashTable(int N)
{
    //! initialize hash table with length "INITIAL_HT_SIZE_FACTOR" of N (1/3 of N)
    //! also the size variable has to be initialized
    size = N * INITIAL_HT_SIZE_FACTOR;

    hashTable = (listT *) malloc (size * sizeof(listT));

    int i;
    for(i=0; i<size; i++)
        hashTable[i].size = 0;
}

void printHashTableToConsole()
{
    int i, k;
    nodeT *p;

    for(i=0; i<size; i++)
    {
        printf("\nB%d of size %d: \n", i, hashTable[i].size);
        p = hashTable[i].head;
        for(k=0; k<hashTable[i].size; k++)
        {
            puts(p->content);
            p = p->next;
        }
    }
}


void addContentToHash(char **content, int N)
{
    int i;

    initHashTable(N);

    for(i=0; i<N; i++)
    {
        insertElement(content[i], hashTable, size);
    }

}

int hashFunction3(char* content)
{
    long long hash = 0;
    int k;
    for(k = 0; k < strlen(content); k++)
    {
        hash += content[k];
        hash += (hash << 10);
        hash ^= (hash >> 6);
    }

    return hash % size;
}

int hashFunction2(char *str) //  a doua
 {
        unsigned long hash = 0;
        int c;

        while (c = *str++)
            hash = c + (hash << 6) + (hash << 16) - hash;

        return hash % size;
}

int hashFunction1(char * content)
{
    //! keep in mind, size in this case simply means the number of buckets

    int k, sum = 0;

    for(k=0; k<strlen(content); k++)
        sum = sum + content[k];

    return sum % size;
}

int hashFunction0(char *content)
{
     int k, sum = 0, c1 = 11, c2 = 23;

    for(k=0; k<strlen(content); k++)
        sum = sum + content[k];

    return (sum - c1) % (c2 + c1);
}



void insertElement(char * element, listT *hash, int hashSize)
{
    //! insert an element
    int poz = hashFunction3(element);
    //printf("%d", poz);
    addToList(&hash[poz], element);

}


void computeDistributionsPerBucket(FILE *out)
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
    int i, nrStars = 20;
    int k, maxSize = 0;
    int x, average = 0, sum = 0;
    float percent;

    fprintf(out,"\n");

    for(i=0; i<size; i++)
        if(maxSize < hashTable[i].size)
            maxSize = hashTable[i].size;


    for(i=0; i<size; i++)
    {
        fprintf(out,"B%d: ", i);

        x = (nrStars * hashTable[i].size) / maxSize;
        percent = (100 * hashTable[i].size) / maxSize;

        for(k=0; k<x; k++)
            fprintf(out, "*");
        fprintf(out," %.1f", percent);
        fputs("%", out);

        sum += hashTable[i].size;

        fprintf(out,"\n");
    }

    double deviation;
    average = sum / size;
    int variance = 0;
    for(i=0; i<size; i++)
        variance += (hashTable[i].size - average) * (hashTable[i].size - average);
    variance = variance / size;
    deviation = pow(variance, 1.0/2);

    fprintf(out, "The deviation is %.2lf", deviation);
}
