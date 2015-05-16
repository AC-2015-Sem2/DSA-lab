#include "hashTable.h"
#include "io.h"
#include <math.h>

//Allocates and initializes the hashTable and the size
void initHashTable(char*** hashTable, int* size, int N)
{
    srand(time(NULL));

    *size = N * INITIAL_HT_SIZE_FACTOR;

    *hashTable = (char**)malloc(*size * sizeof(char*));
    int i;
    for(i = 0; i < *size; i++)
    {
        *(*hashTable + i) = NULL;
    }
}
//Counts how many elements are in hashTable
int elementsInHash(char** hashTable, int size)
{
    int filledBuckets = 0;
    int i;
    for(i = 0; i < size; i++)
    {
        if(hashTable[i] != NULL)
        {
            filledBuckets++;
        }
    }
    return filledBuckets;
}

float getFillFactor(char** hashTable, int size)
{
    return (float)elementsInHash(hashTable, size) / size;
}

//Deallocates the hash table
void destroyHashTable(char*** hashTable, int size)
{
    int i;
    for(i = 0; i < size; i++)
        if(*(*hashTable + i) != NULL)
            free(*(*hashTable + i));
    free(*hashTable);
    *hashTable = NULL;
}

//Allocates a new hash table and rehashes the elements form the old one
void resizeHashTable(char*** hashTable, int* size)
{
    int i;
    int newSize = *size * 2;
    char** newHashTable = (char**)malloc(sizeof(char*) * newSize);
    for(i = 0; i < newSize; i++)
    {
        *(newHashTable + i) = NULL;
    }
    char** oldHashTable = *hashTable;

    for(i = 0; i < *size; i++)
        if(*(oldHashTable + i) != NULL)
            insertElement(newHashTable, *(oldHashTable + i), newSize);

    destroyHashTable(&oldHashTable, *size);
    *size = newSize;
    *hashTable = newHashTable;
}

void insertAllElements(char*** hashTable, int* size, int count, char** content)
{
    float fillFactor = 0.0;

    int i;
    int maxCol = -1;
    int resizes = 0;
    unsigned long int totalCol = 0;
    for(i = 0; i < count; i++)
    {
        fillFactor = getFillFactor(*hashTable, *size);
        if(fillFactor > MAX_FILL_FACTOR)
        {
            //DEBUG
            printf("debug: Resizing at step %d\n", i);
            resizeHashTable(hashTable, size);
            resizes++;
        }
        int collisions = insertElement(*hashTable, content[i], *size);
        totalCol += collisions;
        if(maxCol < collisions || maxCol == -1)
            maxCol = collisions;

        //DEBUG
        if(i % 1000 == 0)
            printf("debug: step: %d; fillFactor: %f; collisions: %d; resizes: %d\n", i, fillFactor, collisions, resizes);
    }
    printf("\nMax Collisions: %d\nNumber of Resizes: %d\nCollision/element: %f\n", maxCol, resizes, (float)totalCol/count);
}

int insertElement(char** hashTable, char* element, int size)
{
    int isInserted = 0;
    int i = 0;
    do
    {
        int Hash = hashFunction3(element, i, size);
        if(hashTable[Hash] == NULL)
        {
            hashTable[Hash] = (char*)malloc(sizeof(char) * (MAX_STRING_LENGTH+1));
            strcpy(hashTable[Hash], element);
            isInserted = 1;
        }
        else
        {
            i++;
        }
    }
    /**extra condition is not necessary since the hash function and resizeHashTable should never allow this to happen if N and MFF are reasonable**/
    while(isInserted == 0 /** && i < size **/);
    return i;
}

//Sums the whole ASCII value
int sumOfChars(char* content)
{
    int sum = 0;
    int i = 0;
    while(content[i] != '\0')
        sum += content[i++];
    return sum;
}

int hashFunction(char* content, int i, int size)
{
    return (sumOfChars(content) + i) % size;
}

int hashFunction2(char* content, int i, int size)
{
    return ((int)(1.618033 * sumOfChars(content) + 3.141592 * i + 2.718281 * i*i)) % size;
}

int hashFunction3(char* content, int i, int size)
{
    return ((int)(sumOfChars(content) * 1.5 + i * cos(i) + 3.2 * (i*i - 1.7 * atan(i*i)))) % size;
}
