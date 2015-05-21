#include "io.h"
#include "files.h"
#include "hashTable.h"

int main()
{
    //init
    int N = _100000;
    char** hashTable;
    int size;
    char** content = readFromFile(N);
    //printContentToConsole(content, N);
    printf("ISF: %f; MFF: %f; N = %d\n", INITIAL_HT_SIZE_FACTOR, MAX_FILL_FACTOR, N);
    initHashTable(&hashTable, &size, N);
    printf("Initial Size: %d\n", size);
    //solution
    insertAllElements(&hashTable, &size, N, content);

    printf("terminal size: %d\n", size);
    destroyHashTable(&hashTable, size);

    return 0;
}
