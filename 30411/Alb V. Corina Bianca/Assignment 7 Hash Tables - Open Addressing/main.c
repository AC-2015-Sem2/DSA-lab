#include "io.h"
#include "files.h"
#include "hashTable.h"

int main()
{
    int N = _100;
    char ** content = readFromFile(N);
    printContentToConsole(content,N);

    initHashTable(N);

    int i,j,x;
    for(i=0;i<N;i++)
    {
       hashFunction(content[i],i);
       if(getFillFactor()>=MAX_FILL_FACTOR)
    {
        int *nrOfCollisions=(int*)malloc(sizeof(int)*size);
        for(j=0;j<=i;j++)
        {

            x=hashFunction(content[j],j);
            nrOfCollisions[j]=insertElement(content[j],x);
        }
    }

    }
    int MIN=999999;
    for(i=0;i<N;i++)
    {
        totalNrOfCollisions=nrOfCollisions[i];
        printf("\nelement %d : %d collisions",i,nrOfCollisions[i]);
        if (MIN>nrOfCollisions[i])
            MIN=nrOfCollisions[i];
    }
    printf("\nthe minimum nr of collisions is %d", MIN);
    return 0;
}
