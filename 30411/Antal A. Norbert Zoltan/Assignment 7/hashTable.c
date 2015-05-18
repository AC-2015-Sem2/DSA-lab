#include <ctype.h>
#include "hashTable.h"
#include "io.h"

void initHashTable(int N)
{
    //! initialize hash table with length "INITIAL_HT_SIZE_FACTOR" of N (1/4 of N)
    size = N * INITIAL_HT_SIZE_FACTOR;
    hashTable = (char**)malloc(size*sizeof(char*));
    int i;
    for(i=0; i<size; i++){
        hashTable[i] = NULL;
    }
}

float getFillFactor()
{
    //! return the fill factor of the hash table
    float fillFactor = -1;
    int n = 0, i;
    for (i=0; i<size; i++){
        if (hashTable[i]!=NULL){
            n++;
        }
    }
    fillFactor = (float)n/size;
    return fillFactor;
}

void resizeHashTable()
{
    //! reconstruct the hash table by (usually) doubling its size
    //! only call this when the current fill factor of your hash table > MAX_FILL_FACTOR

    //! careful, when resizing, the 'size' variable should be changed as well such that the 'hashFunction's distribution will work
    //! be double careful! all the elements which are already in the hash table have to  be RE-hashed! (explanation @ lab)
    int nSize = size * 2;
    char** nHashTable = (char**)malloc(nSize*sizeof(char*));
    char** tempHash = hashTable;
    hashTable = nHashTable;
    int i;
    for (i=0; i<nSize; i++){
        hashTable[i] = NULL;
    }
    for (i=0; i<size; i++){
        if (tempHash[i]!=NULL)
        insertElement(tempHash[i]);
    }
    free(tempHash);
    size = nSize;
}

int insertElement(char * element)
{
    //! insert an element
    //! returns the number of collisions which occurred before the element was inserted
    if (getFillFactor()>MAX_FILL_FACTOR){
        resizeHashTable();
    }
    int hash = hashFunction3(element, 0);
    int nrCol = 0;
    while (nrCol<size && hashTable[hash]!=NULL){
        nrCol++;
        hash = hashFunction3(element, nrCol);
    }
    hashTable[hash] = (char*)malloc(MAX_STRING_LENGTH+1);
    strcpy(hashTable[hash], element);
    return nrCol;
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

int hashFunction2(char* content, int i)
{
    unsigned int value = 0;
    while (*content){
        value = (value << 4) | toupper(*content++);
    }
    return (value + i) % size;
}

int hashFunction3(char* content, int i)
{
    unsigned long hash = 5381;
    int c;

    while (c = *content++)
        hash = ((hash << 5) + hash) + c;

    return (hash + i) % size;
}
