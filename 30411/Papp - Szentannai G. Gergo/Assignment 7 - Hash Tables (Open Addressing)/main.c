#include "io.h"
#include "files.h"
#include "hashTable.h"

int main()
{
    int N = _5000;

    char ** content = readFromFile(N);
    //printContentToConsole(content,N);

    initHashTable(N);
    int i, aux;
    int maxColl = 0;
    nrOfResize = 0;
    float avgColl= 1;

    for (i=0; i<N; i++)
    {
        if ((i % 20) ==0)
            printf("\nElement Collisions FillFactor\n\n");
        aux = insertElement(*(content+i));
        printf("%7d %10d", i, aux);
        if (maxColl < aux)
            maxColl = aux;
        printf(" %8.2f%% \n", 100*getFillFactor());
        avgColl=(float)((((float)(avgColl)*i)+(float)aux)/(float)(i+1));


    }
    printf("\nNumber of resizes: %d\n", nrOfResize);
    printf("\nMaximal number of collisions: %d\n", maxColl);
    printf("\nAverage number of collisions: %f\n", avgColl);
    return 0;
}
