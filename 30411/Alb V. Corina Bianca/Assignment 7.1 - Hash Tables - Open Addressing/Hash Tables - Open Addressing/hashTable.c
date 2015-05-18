#include "hashTable.h"
#include "io.h"
#include<string.h>

void initHashTable(int N)
{
    int i;

    size=INITIAL_HT_SIZE_FACTOR * N;
    hashTable=(char**)malloc(sizeof(char*)*size);
    for(i=0;i<size;i++)
    {
        hashTable[i]=(char*)malloc(sizeof(char)*MAX_STRING_LENGTH);
        hashTable[i]=NULL;
    }

    for(i=0;i<n;i++)
    {
        printf("\n the number of collisions for element %s is %d ",content[i],insertElement(content[i],i));
    }
    //! initialize hash table with length "INITIAL_HT_SIZE_FACTOR" of N (1/4 of N)
}

float getFillFactor(int nth_element)
{
    //! return the fill factor of the hash table
    float fillFactor = 1;
    fillFactor= fillFactor - (nth_element/size);
    return fillFactor;
}

void resizeHashTable()
{

    initHashTable(2*N);

    //! reconstruct the hash table by (usually) doubling its size
    //! only call this when the current fill factor of your hash table > MAX_FILL_FACTOR

    //! careful, when resizing, the 'size' variable should be changed as well such that the 'hashFunction's distribution will work
    //! be double careful! all the elements which are already in the hash table have to  be RE-hashed! (explanation @ lab)
}

int insertElement(char * element, int nth_element)// the n-th element that is being introdyced in the hash table
{
    int i=hashFunction(element,0);
    while(hashTable[i]!=NULL)
        i++;
    if(getFillFactor(nth_element)>=MAX_FILL_FACTOR)
    {
        resizeHashTable();
    }
    else
    {
        hashTable[i]=element;
    }
    int nrOfCollisions=i-hashFunction(element,0);

    //! insert an element
    //! returns the number of collisions which occurred before the element was inserted

    return nrOfCollisions;
}


int hashFunction(char * content, int i)
{
    int j;
    for(j=0;j<MAX_STRING_LENGTH;j++)
    {
        i += atoi(content[j]) + 65;
    }
    return i % size;
}
