#include "io.h"
#include "files.h"
#include "hashTable.h"

int main()
{
    int N = _100;
    hashFunction=h1;

    char ** content = readFromFile(N);
    printContentToConsole(content,N);
    char ** hashTable=initHashTable(N);
    int i;
    int max=0;


    for (i=0;i<N;i++)
    {
        int nrOfCollisions=insertElement(&hashTable,content[i]);
        if (max<nrOfCollisions) max=nrOfCollisions;
    }
    printf("Number of maximum collisions is %d\n",max);
    printf("Number of resizes is %d\n",nrOfResizes);
    return 0;
}
