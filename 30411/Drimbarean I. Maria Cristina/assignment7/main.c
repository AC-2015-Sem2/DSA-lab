#include "io.h"
#include "files.h"
#include "hashTable.h"

int main()
{
    int N = _100;
    int i;

    char ** content = readFromFile(N);
    initHashTable(N);
    for(i=0; i<N; i++)
    {
        insertElement(*(content + i));
    }
    computeDistributionsPerBucket();
    //compute de standard deviation
    float d=0;
     for(i=0; i<size; i++)
    {
        d=d+hashTable[i].size*i;
    }
    d=d/N;
    printf("\nstandard deviaton is:%g",d);
    //printContentToConsole(content,N);
    return 0;
}
