#include "io.h"
#include "files.h"
#include "hashTable.h"

int main()
{
    int N = _100;

    char ** content = readFromFile(N);
    initHashTable(N);
    //printContentToConsole(content,N);

    return 0;
}
