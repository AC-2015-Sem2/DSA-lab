#include "io.h"
#include "files.h"
#include "hashTable.h"

int main()
{
    int N = _1000;

    char ** content = readFromFile(N);
    //printContentToConsole(content,N);

    initHashTable(N);

    int i, nrOfCollisions=0, maxNrOfCollisions = 0;

    for(i=0; i<N; i++)
    {
        nrOfCollisions = insertElement(content[i]);
        if(nrOfCollisions > maxNrOfCollisions)
            maxNrOfCollisions = nrOfCollisions;
    }



    printf("%d collisions, %d resizes", maxNrOfCollisions, nrOfResizes);

    return 0;
}
