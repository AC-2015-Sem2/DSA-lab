#include "hashTable.h"
#include <stdlib.h>
#include <string.h>

void initHashTable(int N)
{
    //! initialize hash table with length "INITIAL_HT_SIZE_FACTOR" of N (1/4 of N)

    size = (int)((float)N * INITIAL_HT_SIZE_FACTOR);
    hashTable = (char**)malloc(sizeof(char*) * size);
    nrOfResizes = 0;
}

float getFillFactor()
{
    //! return the fill factor of the hash table
    float fillFactor = -1;

    int nrOfFull=0, i;

    for(i=0; i<size; i++)
        if(hashTable[i] != NULL)
            nrOfFull++;

    fillFactor = (float)nrOfFull/(float)size;
    return fillFactor;
}

void resizeHashTable()
{
    //! reconstruct the hash table by (usually) doubling its size
    //! only call this when the current fill factor of your hash table > MAX_FILL_FACTOR

    //! careful, when resizing, the 'size' variable should be changed as well such that the 'hashFunction's distribution will work
    //! be double careful! all the elements which are already in the hash table have to  be RE-hashed! (explanation @ lab)

    char **copyTable;
    int i;

    copyTable = hashTable;
    size *= 2;

    hashTable = (char**)malloc(sizeof(char*) * size);
    for(i=0; i<size; i++)
        hashTable[i]=NULL;

    for(i=0; i<size/2; i++)
        if(copyTable[i] != NULL)
        {
            insertElement(copyTable[i]);
        }

    free(copyTable);

    nrOfResizes++;
}

int insertElement(char * element)
{
    //! insert an element
    //! returns the number of collisions which occurred before the element was inserted

    int i=0, resPos, inserted=0;

    if(getFillFactor() > MAX_FILL_FACTOR)
        resizeHashTable();

    while(!inserted)
    {
        resPos = hashFunction3(element, i);
        if(hashTable[resPos] == NULL)
        {
            hashTable[resPos] = element;
            inserted = 1;
        }
        else
            i++;
    }
    return i;
}


int hashFunction(char * content, int i)
{
    int length = strlen(content);
    int k, sum;
    for (sum=0, k=0; k < length; k++)
    {
        sum += content[k];
    }
    return (sum+i) % size;
}

int hashFunction3(char * content, int i)
{
    int h = 0, k;
    for(k = strlen(content)-1; k >= 0; k--)
        h = (content[i] + 128 * h) % size;
    return (h+i)%size;
}

int hashFunction2(char * content, int i)
{
    int hash=0;
    hash += content[0];
    hash += (hash << 3);
    hash ^= (hash >> 11);
    hash += (hash << 15);
    hash += content[1];
    hash += 2;
    return (hash+i)%size;
}
