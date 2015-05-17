#include "io.h"
#include "files.h"
#include "hashTable.h"

int main()
{
    FILE* O = fopen("output.dat", "w");
    //init
    int N = _100000;
    listT* hashTable;
    int size;
    initHashTable(&hashTable, &size, N);
    char** content = readFromFile(N);
    //printContentToConsole(content,N);
    //solution
    insertAllElements(hashTable, size, N, content);
    computeDistributionsPerBucket(hashTable, size, N, O);
    fprintf(O, "N = %d; ISF = %f\nhash table size = %d\n", N, INITIAL_HT_SIZE_FACTOR, size);
    fclose(O);
    return 0;
}
