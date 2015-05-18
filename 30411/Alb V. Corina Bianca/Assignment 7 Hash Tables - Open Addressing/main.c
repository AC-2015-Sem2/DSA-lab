#include "io.h"
#include "files.h"
#include "hashTable.h"

int main()
{
    int N = _100000;
    char ** content = readFromFile(N);
    //printContentToConsole(content,N);

    initHashTable(N);
    MAX=0;
    int i,j,x;
    for(i=0;i<N;i++)
    {
       hashFunction(content[i],i);
       if(getFillFactor()>=MAX_FILL_FACTOR)
    {
        int *nrOfCollisions=(int*)malloc(sizeof(int)*size);
        for(j=0;j<size;j++)
            nrOfCollisions[j]=0;
        for(j=0;j<=i;j++)
        {

            x=hashFunction(content[j],j);
            nrOfCollisions[j]=insertElement(content[j],x);
        }
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
