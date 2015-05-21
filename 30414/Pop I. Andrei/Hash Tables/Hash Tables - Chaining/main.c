#include "io.h"
#include "files.h"
#include "hashTable.h"

int main()
{
    int N = _10000;
    FILE *out = fopen("result.data", "w");

    char ** content = readFromFile(N);

    addContentToHash(content, N);

    //printHashTableToConsole();

    //printContentToConsole(content,N);

    computeDistributionsPerBucket(out);

    return 0;
}
