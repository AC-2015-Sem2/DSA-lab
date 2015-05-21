#include "io.h"
#include "files.h"
#include "hashTable.h"

int main()
{
    int N = _100000;

    char ** content = readFromFile(N);
    //printContentToConsole(content,N);

    initHashTable(N);

    int i;
    while(i<N)
    {
        insertElement(content[i]);
        printf("%d: ins\n", i);
        i++;
    }
    computeDistributionsPerBucket();
    return 0;
}
