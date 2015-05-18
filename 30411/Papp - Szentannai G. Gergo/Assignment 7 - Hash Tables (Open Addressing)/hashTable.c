#include "hashTable.h"
#include <string.h>
#include <stdio.h>
#include <math.h>

void initHashTable(int N)
{
    //! initialize hash table with length "INITIAL_HT_SIZE_FACTOR" of N (1/4 of N)
    hashTable = (char**) malloc(INITIAL_HT_SIZE_FACTOR * N * sizeof(char*));

    size = INITIAL_HT_SIZE_FACTOR * N;

    int i;
    for (i=0; i<size; i++)
        *(hashTable+i) = NULL;
    printf("\nInitial size: %d\n\n", size);
    //printf("Element Collisions FillFactor\n\n");
}

float getFillFactor()
{
    //! return the fill factor of the hash table
    float fillFactor = -1;

    int i, filled=0;
    for (i=0; i<size; i++)
    {
        if (*(hashTable+i) != NULL)
            filled++;
    }
    if (filled != 0)
        fillFactor = (float)filled/(float)size;

    return fillFactor;
}

void resizeHashTable()
{
    //! reconstruct the hash table by (usually) doubling its size
    //! only call this when the current fill factor of your hash table > MAX_FILL_FACTOR

    //! careful, when resizing, the 'size' variable should be changed as well such that the 'hashFunction's distribution will work
    //! be double careful! all the elements which are already in the hash table have to  be RE-hashed! (explanation @ lab)
    printf("\nResizing...");
    char ** tempHashTable = hashTable;  // saving old hash table

    // I suppose this uses a free memory space, so the contents of the tempHashTable will mot be affected:
    hashTable = (char**) malloc( 2 * size * sizeof(char*));  // initializing new hash table
    size = 2 * size;

    int i;
    for (i=0; i<size; i++)
        *(hashTable+i) = NULL;

    for (i=0; i<size/2; i++)
    {
        if (tempHashTable[i] != NULL)
            insertElement(tempHashTable[i]);
    }

    printf(" size = %d\n\n", size);
    nrOfResize++;

}

int insertElement(char * element)
{
    //! insert an element
    //! returns the number of collisions which occurred before the element was inserted
    float ff=getFillFactor();

    if ( ff > MAX_FILL_FACTOR)
        resizeHashTable();

    int i=0;
    int aux_cycle = hashFunction(element, i), cycle=-1;
    while (hashTable[hashFunction(element, i)] != NULL)
    {
        i++;
        if (aux_cycle == hashFunction(element, i)) //! If an element cannot be inserted, however there are free places
            cycle++;
        if (cycle>0)  // resize
        {
            resizeHashTable();
            i=0;
        }
    }
    *(hashTable+hashFunction(element, i)) = element;
    return i;
}
//! H3
int hashFunction(char * content, int i)
{
    int length = strlen(content);
    int k, sum=content[0]*size;
    for (k=0; k < length; k++)
    {
        sum += pow(content[k], 2);
    }

    return ((sum+(i*2)) % size);
}


/*//! H2
int hashFunction(char * content, int i)
{
    int length = strlen(content);
    int k, sum;
    for (sum=0, k=0; k < length; k++)
    {
        sum += content[k];
    }
    sum = sum * 2;
    return (sum+(i*3)) % size;
}
*/
/*//! H1
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
*/





