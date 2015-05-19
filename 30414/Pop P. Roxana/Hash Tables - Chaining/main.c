#include "io.h"
#include "files.h"
#include "list.h"
#include "hashTable.h"

int main()
{
    int N = _100;
    hashFunction=h3;
    char ** content = readFromFile(N);
    printContentToConsole(content,N);
    initHashTable(N);

    int i;
    for (i=0;i<N;i++)
    {
        insertElement(content[i]);
    }
    computeDistributionsPerBucket();
    float delta=getStandardDeviation();
    printf("The standard deviation is %f\n",delta);
    return 0;
}
