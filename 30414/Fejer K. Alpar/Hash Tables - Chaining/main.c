#include "io.h"
#include "files.h"

int main()
{
    int N = _100000;

    char ** content = readFromFile(N);
    printContentToConsole(content,N);
    initHashTable(N);
    addElements(content,N);
    computeDistributionsPerBucket();
    return 0;
}
