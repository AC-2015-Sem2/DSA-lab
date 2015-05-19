#include "hashTable.h"
#include "io.h"
#include<string.h>

void initHashTable(int N)
{
    int i;
    totalNrOfCollisions=0;
    size=INITIAL_HT_SIZE_FACTOR * N;
    hashTable=(char**)malloc(sizeof(char*)*size);
    for(i=0;i<size;i++)
    {
        hashTable[i]=(char*)malloc(sizeof(char)*MAX_STRING_LENGTH);
        hashTable[i]='\0';
    }

    //! initialize hash table with length "INITIAL_HT_SIZE_FACTOR" of N (1/4 of N)
}

float getFillFactor()
{
    //! return the fill factor of the hash table
    float fillFactor = -1;
    int i;
    int nrOfComponents=0;
    for(i=0;i<N;i++)
    {
        if(hashTable[i] != '\0')
            nrOfComponents=nrOfComponents+1;
    }
    fillFactor =(float) nrOfComponents / N;
    return fillFactor;
}

void resizeHashTable()
{
    int i;
    for(i=0;i<size;i++)
    {
        free(hashTable[i]);
    }

    totalNrOfCollisions=0;

    size=size*2;
    for(i=0;i<size;i++)
    {
        hashTable[i]=(char*)malloc(sizeof(char)*MAX_STRING_LENGTH);
        hashTable[i]='\0';
    }



    //! reconstruct the hash table by (usually) doubling its size
    //! only call this when the current fill factor of your hash table > MAX_FILL_FACTOR

    //! careful, when resizing, the 'size' variable should be changed as well such that the 'hashFunction's distribution will work
    //! be double careful! all the elements which are already in the hash table have to  be RE-hashed! (explanation @ lab)
}

int insertElement(char *element, int i)
{
    int nrOfCollisions=0;

    if(getFillFactor()>=MAX_FILL_FACTOR)
    {
        resizeHashTable();

    }
    else
    {
        while(hashTable[i]!='\0')
        {
            nrOfCollisions++;
            i++;
        }
    }
    hashTable[i]=element;

    //! insert an element
    //! returns the number of collisions which occurred before the element was inserted

    return nrOfCollisions;
}


int hashFunction(char * content, int i)
{
    int j;
    int c=strlen(content);
    int sum=0;
    for(j=0;j<c;j++)
    {
        sum+=(int)content[j];
    }

    int x=(int)sum%size;


    nrOfCollisions[i]=insertElement(content,x);


    return x;
}
