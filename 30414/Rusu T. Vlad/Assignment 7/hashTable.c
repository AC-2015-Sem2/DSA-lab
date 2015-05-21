#include "hashTable.h"
#include <stdio.h>


void initHashTable(int N)
{
    //! initialize hash table with length "INITIAL_HT_SIZE_FACTOR" of N (1/4 of N)
	
	int	i;

	size = (int)((float)N * INITIAL_HT_SIZE_FACTOR);
	hashTable = (char **)malloc(sizeof(char *) * size);
	for (i = 0 ; i < size ; ++i)
		hashTable[i] = NULL;
}

float getFillFactor()
{
    //! return the fill factor of the hash table
    float fillFactor = -1;
	int	i = 0, elements = 0;

	for (i = 0 ; i < size ; ++i)
		if (hashTable[i] != NULL)
			++elements;
	fillFactor = (float)elements / (float)size;

    return fillFactor;
}

void resizeHashTable()
{
    //! reconstruct the hash table by (usually) doubling its size
    //! only call this when the current fill factor of your hash table > MAX_FILL_FACTOR

    //! careful, when resizing, the 'size' variable should be changed as well such that the 'hashFunction's distribution will work
    //! be double careful! all the elements which are already in the hash table have to  be RE-hashed! (explanation @ lab)
	
	char **backupTable;
	int	i;
	
	backupTable = hashTable;
	hashTable = (char **)malloc(sizeof(char *) * (size * 2));
	for (i = 0 ; i < size * 2 ; ++i)
		hashTable[i] = NULL;
	size *= 2;
	for (i = 0 ; i < size / 2 ; ++i)
		if (backupTable[i] != NULL)
			insertElement(backupTable[i]);
	free(backupTable);
}

int insertElement(char * element)
{
    //! insert an element
    //! returns the number of collisions which occurred before the element was inserted
	
	int collisions = 0;
	int	key;

	if (getFillFactor() > MAX_FILL_FACTOR)
		resizeHashTable();
	key = hashFunction(element, collisions);
	while (hashTable[key] != NULL)
	{
		++collisions;
		key = hashFunction(element, collisions);
	}
	hashTable[key] = element;
    return collisions;
}

int hashFunction(char * content, int i)
{
	int	my_hash, length, j;

	length = strlen(content);
	my_hash = 0;
	for (j = 0 ; j < length ; ++j)
	{
		my_hash += content[j];
	}
	my_hash -= length;
	my_hash %= (length / 2 + 11);
	my_hash *= length;
    return (my_hash + i) % size;
}
