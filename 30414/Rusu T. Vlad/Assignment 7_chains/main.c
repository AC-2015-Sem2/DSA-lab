#include "io.h"
#include "files.h"

int main()
{
    int N = _100000;
	int i;

    char ** content = readFromFile(N);
	initHashTable(N);
	for (i = 0 ; i < N ; ++i)
		insertElement(content[i]);
	computeDistributionsPerBucket();
    //printContentToConsole(content,N);

    return 0;
}
