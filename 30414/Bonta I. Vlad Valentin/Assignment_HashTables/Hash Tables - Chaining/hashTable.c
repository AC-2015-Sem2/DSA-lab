#include "hashTable.h"
#include "io.h"

void initHashTable(int N)
{
	//! initialize hash table with length "INITIAL_HT_SIZE_FACTOR" of N (1/3 of N)
	//! also the size variable has to be initialized
	size = INITIAL_HT_SIZE_FACTOR * N;
	hashTable = (listT*)malloc(sizeof(listT) * size);
	int i;

	i = 0;
	while (i <= size - 1)
	{
		hashTable[i].head = hashTable[i].tail = NULL;
		hashTable[i].size = 0;
		i++;
	}
}

void insertElement(char * element)
{
	//! insert an element
	int i;
	int key;

	i = 0;
	key = hashFunction(element, i);
	addToList(&(hashTable[key]), element);
}

int hashFunction(char * content, int i)
{
	//! keep in mind, size in this case simply means the number of buckets
	/*unsigned char *p = content;
	  unsigned long long h = 0xcbf29ce484222325ULL;
	  int j;
	  for ( j = 0; j < size; j++ )
	  h = ( h ^ p[j] ) * 0x100000001b3ULL;

	  return h % size;*/

	long sum = 0;
	long mult = 1;
	int j;
	for (j = 0; j < size; j++)
	{
		sum += size ^ content[j];
		mult = mult ^ content[j];
	}
	return (abs(sum) * mult) % size;
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
	int maxSize = 0;
	int i;
	int j;
	float sumOfAllBucketsSizes;
	float fillPerBucket;

	sumOfAllBucketsSizes = 0;
	fillPerBucket = 0;
	for (i = 0; i < size; ++i)
	{
		if (hashTable[i].size > maxSize)
			maxSize = hashTable[i].size;
		sumOfAllBucketsSizes += hashTable[i].size;
	}

	float sum = 0;
	float sq_sum = 0;
	for(i = 0; i < size; ++i)
	{
		sum += hashTable[i].size;
		sq_sum += hashTable[i].size * hashTable[i].size;
	}
	float mean = sum / (float)size;
	float variance = sq_sum / (float)size - mean * mean;
	for (i = 0;i < size; ++i)
	{
		printf("B%d:", i);
		fillPerBucket = (float)hashTable[i].size/(float)maxSize * 40.00;
		for (j = 0; j < fillPerBucket; ++j)
			printf("*");
		printf(" (%.2lf %c)\n", fillPerBucket / 40 * 100, '%');
	}
	printf("size==%d\n", size);
	printf("Variance== %lf\n", sqrt(variance));
	printf("Standard deviation : %lf", sumOfAllBucketsSizes / (float)size);
}
