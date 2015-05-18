#include "io.h"
#include "files.h"
#include "hashTable.h"

int main()
{
    int N = _100;
    int i;

    char ** content = readFromFile(N);

    initHashTable(N);
    i = 0;
    printf("Start !");
    printf("\tInserting elements !\n\tLoading...\n");
    while (i<N)
    {
        insertElement(content[i]);
        i++;
    }
    computeDistributionsPerBucket();
    //printContentToConsole(content,N);
    return 0;
}
