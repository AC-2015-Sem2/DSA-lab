#include "io.h"
#include "files.h"
#include "hashTable.h"

int main()
{
    int N = _100000;
    n=N;
    char ** content = readFromFile(N);
    printContentToConsole(content,N);

    initHashTable(N);

    return 0;
}
