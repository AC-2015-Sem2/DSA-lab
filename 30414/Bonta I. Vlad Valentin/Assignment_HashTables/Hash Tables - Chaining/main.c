#include "io.h"
#include "files.h"
#include "hashTable.h"

int main()
{
	int N = _100;

	char ** content = readFromFile(N);
	//printContentToConsole(content,N)
	initHashTable(N);
	int i = 0;
	while (i < N)
	{
		insertElement(content[i]);
		i++;
	}
	computeDistributionsPerBucket();;

	return 0;
}
