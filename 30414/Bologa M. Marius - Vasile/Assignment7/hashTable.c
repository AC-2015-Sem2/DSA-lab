#include "hashTable.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void initHashTable(int N)
{
    //! initialize hash table with length "INITIAL_HT_SIZE_FACTOR" of N (1/4 of N)
    size = N * INITIAL_HT_SIZE_FACTOR;

    hashTable = (char**) malloc (sizeof(char*) * size);
    int i;

    for(i=0; i<size; i++)

        hashTable[i] = NULL;

    nrOfResizes=0;
}

float getFillFactor()
{
    //! return the fill factor of the hash table
    float fillFactor=-1;
    int fullBuckets=0;
    int i;

    for(i=0; i<size; i++)
        if (hashTable[i] != NULL)
            fullBuckets++;



    fillFactor = fullBuckets / size;
    return fillFactor;
}



void resizeHashTable()
{
    //! reconstruct the hash table by (usually) doubling its size
    //! only call this when the current fill factor of your hash table > MAX_FILL_FACTOR

    //! careful, when resizing, the 'size' variable should be changed as well such that the 'hashFunction's distribution will work
    //! be double careful! all the elements which are already in the hash table have to  be RE-hashed! (explanation @ lab)

    char ** newTable=hashTable;
    int i;
    hashTable= (char**) malloc ((size*2) * sizeof(char*));
    for(i=0; i<size*2; i++)
        hashTable[i] = NULL;
    size*=2;
    for(i=0; i<size/2; i++)
        if(newTable[i] != NULL)
        {
            insertElement(newTable[i]);
        }
    free(newTable);
    nrOfResizes++;

}

int insertElement(char * element)
{
    //! insert an element
    //! returns the number of collisions which occurred before the element was inserted
    int nrOfCollisions=0,hashElement,emptyB=0;
    if (MAX_FILL_FACTOR < getFillFactor())
        resizeHashTable();

    while(!emptyB)
    {
        hashElement= hashFunction1(element,nrOfCollisions);
        if (hashTable[hashElement] == NULL)
        {
            hashTable[hashElement] = element;
            emptyB=1;
        }
        else
            nrOfCollisions++;
    }
    return nrOfCollisions;
}
int hashFunction1(char *content, int len)
{

    unsigned h = 0;
    int i;

    for (i = 0; i < len; i++)
    {
        h += content[i];
    }

    return h%size;
}
/*int  hashFunction2(char *content, int len)
{
    int h = 0;
    int i;

    for (i = 0; i < len; i++)
    {
        h = 33 * h + content[i];
    }

    return h%size;
}

*/

 /*int hashFunction3(char* content, int len)
{
   unsigned int b    = 378551;
   unsigned int a    = 63689;
   unsigned int h = 0;
   unsigned int i    = 0;

   for(i = 0; i < len; content++, i++)
   {
      h = h * a + content[i];
      a    = a * b;
   }

   return h%size;
}*/


