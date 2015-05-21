#include "hashTable.h"
#include <string.h>
#include <stdio.h>


void initHashTable(int N)
{
	//! initialize hash table with length "INITIAL_HT_SIZE_FACTOR" of N (1/3 of N)
	//! also the size variable has to be initialized

	int i;
	size = (int)((float)N * INITIAL_HT_SIZE_FACTOR);
	hashTable = (listT *)malloc(sizeof(listT) * size);
	for (i = 1 ; i < size ; ++i)
	{
		hashTable[i].head = NULL;
		hashTable[i].tail = NULL;
		hashTable[i].size = 0;
	}
}

void insertElement(char * element)
{
	//! insert an element

	int key;

	key = hashFunction(element, 0);
	addToList(hashTable[key], element);
	hashTable[key].size++;
}

int hashFunction(char * content, int i)
{
	//! keep in mind, size in this case simply means the number of buckets

	unsigned long long h = 0xcbf29ce484222325ULL;
	int len;

	len = strlen(content);

	for ( i = 0; i < len; i++ )
		h = ( h ^ content[i] ) * 0x100000001b3ULL;

	return (h + i) % size;
}

void computeDistributionsPerBucket()
{
	//! computes the distribution of elements for each bucket
	//! the output should look something like:
	/**
	  MAX = 'x' * 20

B0: ********** (~50%)
B1: ************ (~60%)
B2: ****** (~30%)
B3: ******* (~35%)
.....


hint : the bigger you choose X, the better approximation
hint2: choose it somewhere between 20-40 such that it fits in one row in the console nicely
*/
	int i, j;
	int maxBucket;
	float distr;
	const int x = 35;

	maxBucket = 0;
	for (i = 0 ; i < size ; ++i)
		if (hashTable[i].size > maxBucket)
			maxBucket = hashTable[i].size;
	printf("%d\n", maxBucket);
	for (i = 0 ; i < size ; ++i)
	{
		distr = (float)hashTable[i].size / (float)maxBucket;
		printf("B%d: ", i);
		for (j = 0 ; j < (int)(distr * x) ; ++j)
			printf("*");
		printf(" (~%d%c)\n", (int)(distr * 100), '%');
	}

}
