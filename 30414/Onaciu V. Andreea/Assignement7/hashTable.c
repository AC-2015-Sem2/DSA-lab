#include "hashTable.h"
#include "io.h"
#include "files.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
void initHashTable(int N)
{
    //! initialize hash table with length "INITIAL_HT_SIZE_FACTOR" of N (1/4 of N)
    size=N*INITIAL_HT_SIZE_FACTOR;
    hashTable=(char**)malloc(sizeof(char*)*size);
    int i;
    for (i=0; i<size; i++)
    {
        *(hashTable+i)=NULL;
    }
}
int getNumberOfElements(char **hashTable,int size)
{
    return length;
    int i;
    int nrOfElements=0;
    for (i=0; i<size; i++)
        if (hashTable[i]!=NULL) nrOfElements++;

    return nrOfElements;
}
float getFillFactor()
{

    //! return the fill factor of the hash table
    return (float)getNumberOfElements(hashTable,size)/size;

}

void resizeHashTable()
{
    //! reconstruct the hash table by (usually) doubling its size
    //! only call this when the current fill factor of your hash table > MAX_FILL_FACTOR
    char** auxHashTable;
    int k=0;
    auxHashTable=(char**)malloc(sizeof(char*)*length);
    int i;
    ///Copy the elements in an auxiliary array
    for (i=0; i<size; i++)
    {
        if (*(hashTable+i)!=NULL)
        {
            auxHashTable[k]=hashTable[i];
            k++;
        }
    }
    ///Initialize the new hash table
    size=size*2;
    hashTable=(char**)malloc(sizeof(char*)*size);
    for (i=0; i<size; i++)
    {
        *(hashTable+i)=NULL;
    }
    for (i=0; i<length; i++)
        insertElement(*(auxHashTable+i));

}

int insertElement(char * element)
{
    //! insert an element
    //! returns the number of collisions which occurred before the element was inserted
    int nrOfCollisions=0;
    float fillFactor=getFillFactor();
    if (fillFactor>MAX_FILL_FACTOR)
    {
        resizeHashTable();

    }
    while (hashTable[hashFunction3(element,nrOfCollisions)]!=NULL)
        nrOfCollisions++;
    hashTable[hashFunction3(element,nrOfCollisions)]=element;
    return nrOfCollisions;
}


int hashFunction(char * content, int i)
{
    int sum=0;
    int k;
    int lengthS=strlen(content);
    for (k=0; k<lengthS; k++)
        sum+=content[k];

    return (sum+i) % size;
}

int hashFunction2(char * content, int i)
{
    int k=0;
    int x=33;
    long hash=0;
    int stringLength=strlen(content);
    while ( (k<stringLength))
    {
        hash=content[k]+hash*x;
        k++;
    }
    hash=abs((hash+i)%size);
    return hash;
}

int hashFunction3(char *content,int i)
{
    int k;
    int constant=1;
    int len=strlen(content);
    unsigned long sum=0;
    for (k=0; k<len; k++)
    {
        sum+=content[k]*constant;
        constant*=256;
    }
    return ((sum+i)%size);

}
