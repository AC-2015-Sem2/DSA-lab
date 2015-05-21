#include "io.h"
#include "files.h"
#include "hashTable.h"
int main()
{

    int N = _50000;
    int max=0;
    char ** content = readFromFile(N);

    int i;
    initHashTable(N);

    for (i=0;i<N;i++)
    {
    length=i;
    int nrOfCollisions=insertElement(*(content+i));
    if (nrOfCollisions>max) max=nrOfCollisions;

    }
    printf("maxNrOfCollisions=%d",max);
    return 0;
}
