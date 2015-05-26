#include "io.h"
#include "files.h"
#include "hashTable.h"
#include <math.h>

double standardDeviation()
{
    double a=0,stdev=0;
    int i;

    for (i=0;i<size;i++)
        a=a+hashTable[i].size;
    a=a/size;

    for (i=0;i<size;i++)
        stdev=stdev+(hashTable[i].size-a)*(hashTable[i].size-a);
    stdev=stdev/size;
    return sqrt(stdev);
}

int main()
{
    int N = _1000;

    char ** content = readFromFile(N);
    initHashTable(N);
    int i = 0;
    while (i < N) {
        insertElement(content[i]);
        i++;
    }
    computeDistributionsPerBucket();
    printf("Standard deviation: %.3f\n", standardDeviation());
    return 0;
}
