#include "io.h"
#include "files.h"
#include "hashTable.h"

int main()
{
    int N = _100;
    int nrOfBuckets = N * INITIAL_HT_SIZE_FACTOR;
    char ** content = readFromFile(N);
    printContentToConsole(content,N);

    initHashTable(N, nrOfBuckets);
    int i;
    for(i=0; i<N; i++)
    {
        insertElement(content[i], nrOfBuckets);
    }
    computeDistributionsPerBucket(N, nrOfBuckets);

    return 0;
}
