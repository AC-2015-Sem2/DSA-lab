#include "hashTable.h"
#include "io.h"

void initHashTable(int N)
{
	//! initialize hash table with length "INITIAL_HT_SIZE_FACTOR" of N (1/4 of N)
	size = INITIAL_HT_SIZE_FACTOR * N;
	hashTable = (char**)malloc(sizeof(char*) * size);
	int i;

	i = 0;
	while (i <= size - 1)
	{
		hashTable[i] = NULL;
		i++;
	}
}

float getFillFactor()
{
	//! return the fill factor of the hash table
	float fillFactor = -1;
	int i;
	float nrOfFilledSpaces;

	i = 0;
	nrOfFilledSpaces = 0;
	while (i < size)
	{
		if (hashTable[i] != NULL)
			nrOfFilledSpaces++;
		i++;
	}

	fillFactor = (float)nrOfFilledSpaces / (float)size;
	return fillFactor;
}

void resizeHashTable()
{
	//! reconstruct the hash table by (usually) doubling its size
	//! only call this when the current fill factor of your hash table > MAX_FILL_FACTOR

	//! careful, when resizing, the 'size' variable should be changed as well such that the 'hashFunction's distribution will work
	//! be double careful! all the elements which are already in the hash table have to  be RE-hashed! (explanation @ lab)
	char **auxTable;
	int i;

	auxTable = hashTable;
	size = size * 2;
	hashTable = (char**)malloc(sizeof(char*) * size);
	i = 0;
	while (i < size)
	{
		hashTable[i] = NULL;
		i++;
	}
	i = 0;
	while (i < size / 2)
	{
		if (auxTable[i])
			insertElement(auxTable[i]);
		i++;
	}
	free(auxTable);
}

int insertElement(char * element)
{
	//! insert an element
	//! returns the number of collisions which occurred before the element was inserted
	int ok;
	int i;
	int hashRes;
	int nrOfColissions;

	i = 0;
	ok = 0;
	nrOfColissions = 0;
	if (MAX_FILL_FACTOR < getFillFactor())
		resizeHashTable();
	while (ok == 0)
	{
		hashRes = hashFunction(element, i);
		if (hashTable[hashRes] == NULL)
		{
			hashTable[hashRes] = element;
			ok = 1;
		}
		else
			nrOfColissions++;
		i++;
	}
	return nrOfColissions;
}


int hashFunction(char *content, int i)
{
	long sum = 0;
	long mult = 1;
	int j;
	for (j = 0; j < i; j++)
	{
		sum += size ^ content[j];
		mult = mult ^ content[j];
	}
	return (abs(sum) * mult + i) % size;
}
