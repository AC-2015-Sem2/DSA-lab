#include "hashTable.h"
#include "files.h"
#include "io.h"
int main()
{
    int N = _5000;
	int i;
	int nrOfCollisions, maxNrOfCollisions = 0;

	i = 0;
    char **content = readFromFile(N);
	//printContentToConsole(content, N);
	initHashTable(N);
	while (i < N)
	{
		nrOfCollisions = insertElement(content[i]);
		if (nrOfCollisions > maxNrOfCollisions)
				maxNrOfCollisions = nrOfCollisions;
		i++;
	}
	dprintf(2, "NrOfResizes==%d maxnrofcollisions==%d", size, maxNrOfCollisions);

    return 0;
}
