#include "io.h"
#include "files.h"
#include "hashTable.h"

int main()
{
    int N = _50000;

    char ** content = readFromFile(N);
    //printContentToConsole(content,N);

    initHashTable(N);
    int i, aux;
    int maxColl = 0;
    nrOfResize = 0;

    for (i=0; i<N; i++)
    {
        aux = insertElement(*(content+i));
        printf("Element %3d; collisions: %3d", i, aux);
        if (maxColl < aux)
            maxColl = aux;
        printf(", fillfactor: %.2f\n", getFillFactor());
    }
    printf("\nNumber of resizes: %d\n", nrOfResize);
    printf("\nMaximal number of collisions: %d\n", maxColl);
    return 0;
}
