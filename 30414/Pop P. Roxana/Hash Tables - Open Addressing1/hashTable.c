#include "hashTable.h"
#include "io.h"
#include <math.h>

char** initHashTable(int N)
{
    //! initialize hash table with length "INITIAL_HT_SIZE_FACTOR" of N (1/4 of N)
    char **hashTable;
    size=INITIAL_HT_SIZE_FACTOR*N;
    hashTable = (char**) malloc(sizeof(char*) *size );
    if (hashTable==NULL) perror("HashTable could not be allocated (in init function)\n");
    int i;
    for(i=0; i<size; i++)
    {
        hashTable[i] = NULL;
    }
    return hashTable;
}

float getFillFactor(char** ht, int size)
{
    int i;
    int nrOfEntries = 0;
    for(i=0;i<size;i++)
        if(ht[i] != NULL)
            nrOfEntries++;

    return (float)nrOfEntries/size;
}

char ** resizeHashTable(char ** hashTable)
{
    int i;
    nrOfResizes++;
    char** newH = (char**)malloc(sizeof(char*) * size * 2);
    for(i = 0; i < 2*size; i++)
        if(hashTable[i] != NULL)
        {
            newH[i]=NULL;
        }


    for(i = 0; i < size; i++)
        if(hashTable[i] != NULL)
        {
            insertElement(&newH, hashTable[i]);
        }
    for(i = 0; i < size; i++)
        if(hashTable[i] != NULL)
        {
            free(hashTable[i]);
        }
    free(hashTable);

    size *=2;

    return newH;
}
int insertElement(char *** hashTable,char * element)
{
    //! insert an element
    //! returns the number of collisions which occurred before the element was inserted
    if (getFillFactor((*hashTable), size)>MAX_FILL_FACTOR)
    {
        (*hashTable)=resizeHashTable(*hashTable);
    }
    int i=0;
    do
    {
        int k=hashFunction(element,i);
        if ((*hashTable)[k]==NULL)
        {
            (*hashTable)[k]=(char*)malloc(sizeof(char)*(MAX_STRING_LENGTH+1));
            strcpy((*hashTable)[k],element);
            return i;
        }
        else
        {
            i++;
        }
    }
    while(i<size);
    perror("could not insert a element\n");
    return -1;
}


int h0(char * content, int i)
{
    return i % size;
}

int h1(char * content, int i)
{
    int length = strlen(content);
    int k, sum=0;
    for (k=0; k < length; k++)
    {
        sum += content[k];
    }
    return (sum+i) % size;
}

int h2(char * content, int i)
{
    int length = strlen(content);
    int k, sum=0;
    for (k=0; k < length; k++)
    {
        sum += content[k];
    }
    int c1=pow(2,k);
    int c2=c1+1;
    return (sum+c1*i+c2*i*i) %size;
}

int h3(char * content, int i)
{
    int length = strlen(content);
    int k, sum=0,sum1=0;
    for (k=0; k < length; k++)
    {
        sum += content[k];
    }
        for (k=0; k < length; k++)
    {
        if (k%3==0)
        sum1 += content[k];
    }

    return (sum+i*sum1) %size;
}

