#include "io.h"
#include "files.h"
#include "hashTable.h"

int main()
{
    int N = _100;
	int i, maxNrOfCollisions, collisions;
	int resizes, factor;

	maxNrOfCollisions = 0;
    char ** content = readFromFile(N);
	initHashTable(N);
	for (i = 0 ; i < N ; ++i)
	{
		collisions = insertElement(content[i]);
		if (collisions > maxNrOfCollisions)
			maxNrOfCollisions = collisions;
	}
	printf("Maximum number of collisions is: %d\n", maxNrOfCollisions);
	factor = size / (int)((float)N * INITIAL_HT_SIZE_FACTOR);
	for (resizes = 0 ; factor > 1 ; factor >>= 1)
		++resizes;
	printf("The table was resized %d times.\n", resizes);
//    printContentToConsole(content,N);

    return 0;
}
