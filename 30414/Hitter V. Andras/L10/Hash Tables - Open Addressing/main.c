#include <stdio.h>
#include <stdlib.h>
#include "io.h"
#include "files.h"
#include "hashTable.h"

int main()
{
    int N = _100;

    char ** content = readFromFile(N);
    printContentToConsole(content,N);
    int i;
    initHashTable(N);

    for (i=0;i<N;i++)
    {
    length=i;
    int Collisions=insertElement(*(content+i));
    if (Collisions>max) max=Collisions;

    }
    printf("maxNrCollisions=%d",max);
    return 0;
}
