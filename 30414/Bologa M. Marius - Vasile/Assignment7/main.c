#include "io.h"
#include "files.h"
#include "hashTable.h"

int main()

{

   int N = _100;
    int maxCollisions=0;
    char ** content = readFromFile(N);

    int i;
initHashTable(N);

    for (i=0;i<N;i++)
    {
    int nrOfCollisions=insertElement(content[i]);
    if (nrOfCollisions>maxCollisions)
        maxCollisions=nrOfCollisions;
    }
    printf("Maximum number of collisions:%d\n",maxCollisions);
    printf("Number of resizes:%d\n",nrOfResizes);
    return 0;
}


