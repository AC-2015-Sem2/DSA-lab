#include "io.h"
#include "files.h"
#include "hashTable.h"

int main()
{
    int N = 100;
    char ** content = readFromFile(N);
    printContentToConsole(content,N);

    initHashTable(N);

    int MAX=0;

    int i=0,resizeTable=0;
    while(i<N)
    {
        int x=hashFunction(*content,i);
        i++;
        if (insertElement(content[i],x)==-1)
        {
            i=0;
            resizeTable++;
        }
    }


    totalNrOfCollisions=0;
    for(i=0;i<N;i++)
    {
        totalNrOfCollisions+=nrOfCollisions[i];
        printf("\nelement %d : %d collisions",i,nrOfCollisions[i]);
        if (MAX<nrOfCollisions[i])
            MAX=nrOfCollisions[i];
    }
    printf("\nthe maximum nr of collisions is %d", MAX);
    printf("\nthe total number of collisions is %d", totalNrOfCollisions);
    printf("\nthe number of resizes is %d",resizeTable);
    return 0;
}
