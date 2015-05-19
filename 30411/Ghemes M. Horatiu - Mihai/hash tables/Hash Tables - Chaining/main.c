#include <math.h>
#include "io.h"
#include "files.h"
#include "hashTable.h"
int main()
{
    int N = _500;
    int i;
    char ** content = readFromFile(N);
    initHashTable(N);
    for (i=0;i<N;i++)
        insertElement(content[i]);
    computeDistributionsPerBucket();
    printf("Standard deviation: %.3f (x=30)\n", standardDeviation());
    return 0;
}
