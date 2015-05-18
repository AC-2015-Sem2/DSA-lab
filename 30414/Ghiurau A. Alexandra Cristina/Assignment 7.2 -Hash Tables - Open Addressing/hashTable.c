#include "hashTable.h"
#include "io.h"
#include <string.h>

void initHashTable(int N, int size)
{
    //! initialize hash table with length "INITIAL_HT_SIZE_FACTOR" of N (1/4 of N)
    int i;
    hashTable = (char**)malloc(sizeof(char*)* size);
    for(i=0; i<size; i++)
    {
        *(hashTable+ i) = NULL;
    }
}

float getFillFactor(int size)
{
    //! return the fill factor of the hash table;
    //! the fill factor is the ratio between the number of elements and the size of the table
    int counter = 0;
    int i;
    for(i=0 ; i< size; i++)
    {
        if(hashTable[i] != NULL)
            counter ++;
    }

    return (float)counter / (float)size;
}

void deleteHash(char **hash, int hashSize)
{
    if(hash != NULL)
    {
        int i;
        for(i=0; i < hashSize; i++)
        {
            if(*(hash + i)  != NULL)
            {
                free (*(hash + i));
            }
        }
        free(hash);
    }
}
void resizeHashTable(int N, int *size)
{
    //! reconstruct the hash table by (usually) doubling its size
    int i;
    int doubleSize = 2 * (*size);
    char **reconstructedHash = (char**)malloc(sizeof(char*)* doubleSize);

    for(i=0; i<doubleSize; i++)
    {
        *(reconstructedHash+ i) = NULL;
    }

    for(i= 0; i< *size; i++)
    {
        if(*(hashTable + i) != NULL)
        {
            insertElement(hashTable[i], reconstructedHash, doubleSize);
        }
    }

    deleteHash(hashTable, *size);

    *size = doubleSize;
    hashTable = reconstructedHash;

}


int insertElement(char * element, char ** hash, int size)
{
    //! insert an element
    //! returns the number of collisions which occurred before the element was inserted
    /** pseudo-code for inserting an element using Open Addressing:

    hashInsert(hashTable, k)
    i=0
    repeat
        j = h(k,i)
        if(T == NIL)
             T[j] = k //k - content[i]
        return j
        else i = i+1
        until i == m (in our case -> if fill factor > MAX_FILL_FACTOR)
    error "Overflow" (in our case -> resizing the hashTable)

    */
    int i = 0;
   // nrOfResizes = 0;
    int isInserted = 0;

    do
    {
        int j = hashFunction3(element,i, size);
        if(hash[j] == NULL)
        {
            *(hash+ j) = (char*) malloc(sizeof(char) * (MAX_STRING_LENGTH +1) ); // <=> hash[i]
            strcpy(hash[j], element);
            isInserted = 1;
        }
        else
        {
            i = i+1;
        }
    }
    while(isInserted == 0);

    return i;
}


int elementInsert(int N, int size)
{
    char **content = readFromFile(N);
    initHashTable(N, size);
    nrOfResizes = 0;
    int maxCollisions = 0;
    int k;
    for(k = 0 ; k < N ; k++)
    {
        float fillFactor = getFillFactor(size);
        if(fillFactor > MAX_FILL_FACTOR)
        {
            resizeHashTable(N, &size);
            nrOfResizes++;
        }
            int collisions = insertElement(content[k], hashTable, size);
            if(collisions > maxCollisions)
                maxCollisions = collisions;
    }
    return maxCollisions;
}


int hashFunction1(char * content, int i, int size)
{
    int length = strlen(content);
    int k = 0, sum = 0;
    for (sum=0, k=0; k < length; k++)
    {
        sum += content[k];
    }
    return (sum + i) % size;
}

//quadric
int hashFunction2(char * content, int i, int size)
{
    int length = strlen(content);
    int k = 0, sum = 0;
    for (sum=0, k=0; k < length; k++)
    {
        sum += content[k];
    }
    return ((sum % size)+ i + i*i) % size;
}
//quadric with [prime]constants
int hashFunction3(char * content, int i, int size)
{
    int length = strlen(content);
    int k = 0, sum = 0;
    for (sum=0, k=0; k < length; k++)
    {
        sum += content[k];
    }
     return ((sum % size)+ 11*i + 29*i*i) % size;
}



