#include "hashTable.h"
#include <string.h>
#include <stdio.h>
void initHashTable(int N)
{
    //! initialize hash table with length "INITIAL_HT_SIZE_FACTOR" of N (1/4 of N)
    int i;
    size=INITIAL_HT_SIZE_FACTOR * N;
    hashTable = (char**)malloc(size*sizeof(char*));
    for (i=0; i<size; i++)
        hashTable[i]=NULL;
}

float getFillFactor()
{
    //! return the fill factor of the hash table
    float fillFactor = -1;
    int filledSlots = 0;
    int i;
    for (i=0; i<size; i++)
        if (hashTable[i]!=NULL)
            filledSlots++;
    if(filledSlots!=0)
        fillFactor = filledSlots/size;
    return fillFactor;
}
void resizeHashTable(int N)
{
    int i;
    if(size*2<=N)
        size=size*2;
    else
        size=N;;
    free(hashTable);
    hashTable=(char**)malloc(size * sizeof(char*));
    for(i=0; i<size; i++)
        hashTable[i]=NULL;

    //! reconstruct the hash table by (usually) doubling its size
    //! only call this when the current fill factor of your hash table > MAX_FILL_FACTOR

    //! careful, when resizing, the 'size' variable should be changed as well such that the 'hashFunction's distribution will work
    //! be double careful! all the elements which are already in the hash table have to  be RE-hashed! (explanation @ lab)
}

int insertElement(char * element)
{
    //! insert an element
    //! returns the number of collisions which occurred before the element was inserted
    int collisions=0;
    int k=hashFunction1(element,0);
    if(hashTable[k]==NULL)
        hashTable[k]=element;
    else
    {
        int i=1;
        while(hashTable[k]!=NULL)
        {
            collisions++;
            k=hashFunction1(element, i);
            i++;
        }
        hashTable[k]=element;
    }
    return collisions;
    return 0;
}
int hashFunction1(char * content, int i)     //!-the starting one
{
    int length = strlen(content);
    int k, sum=0;
    for (k=0; k < length; k++)
    {
        sum+=content[k];
    }
    return (sum+i) % size;
}
int hashFunction2(char* content, int i)
{
    int value = 0;
    while (*content){
        value = (value << 4) | toupper(*content++);
    }
    return (value + i) % size;
}

