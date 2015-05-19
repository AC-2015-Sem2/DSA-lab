#include "hashTable.h"
#include <stdio.h>
#include <stdlib.h>
#include<math.h>


void initHashTable(int N)
{
    hashTable = (char**) malloc(INITIAL_HT_SIZE_FACTOR * N * sizeof(char*));

    size = INITIAL_HT_SIZE_FACTOR * N;

    int i;
    for (i=0; i<size; i++)
        *(hashTable+i) = NULL;
    printf("\nInitial size: %d\n\n", size);
}

//int getNumberOfElements(char **hashTable,int size)
//{
//    return length;
//    int i;
//    int nrOfElements=0;
//    for (i=0; i<size; i++)
//        if (hashTable[i]!=NULL) nrOfElements++;
//
//    return nrOfElements;
//}
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

void insertAllElements(char hashTable, int count, char** content)
{
    float fillFactor = 0.0;

    int i;
    int maxCol = -1;
    int resizes = 0;
    unsigned long int totalCol = 0;
    for(i = 0; i < count; i++)
    {
        fillFactor = getFillFactor(hashTable, size);
        if(fillFactor > MAX_FILL_FACTOR)
        {

            printf("step %d\n", i);
            resizeHashTable(hashTable, size);
            resizes++;
        }
        int collisions = insertElement(content[i]);
        totalCol += collisions;
        if(maxCol < collisions || maxCol == -1)
            maxCol = collisions;

        if(i % 100 == 0)
            printf("debug: step: %d; fillFactor: %f; collisions: %d; resizes: %d\n", i, fillFactor, collisions, resizes);
    }
   printf("\nMax Collisions: %d\nNumber of Resizes: %d\nCollision/element: %f\n", maxCol, resizes, (float)totalCol/count);

void resizeHashTable()
{
    //! reconstruct the hash table by (usually) doubling its size
    //! only call this when the current fill factor of your hash table > MAX_FILL_FACTOR

    //! careful, when resizing, the 'size' variable should be changed as well such that the 'hashFunction's distribution will work
    //! be double careful! all the elements which are already in the hash table have to  be RE-hashed! (explanation @ lab)

    char ** HashTable2 = hashTable;
    hashTable = (char**) malloc( 2 * size * sizeof(char*));
    size = 2 * size;

    int i;
    for (i=0; i<size; i++)
//        *(hashTable+i) = NULL;

    for (i=0; i<size/2; i++)
    {
        if (HashTable2[i] != NULL)
            insertElement(HashTable2[i]);
    }

    printf("\nResizing, size = %d\n\n", size);

}

//!int insertElement(char * element)

//int hashFunction(char * content, int i)
//{
//    int sum=0;
//    int k;
//    int length=strlen(content);
//    for (k=0; k<length; k++)
//        sum+=content[k];
//
//    return (sum+i) % size;
//}

