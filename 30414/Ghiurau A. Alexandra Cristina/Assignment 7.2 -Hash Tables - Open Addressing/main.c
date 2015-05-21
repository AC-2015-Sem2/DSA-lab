#include "io.h"
#include "files.h"
#include "hashTable.h"
int main()
{
    int N = _1000;

    int size = N * INITIAL_HT_SIZE_FACTOR;
   // char ** content = readFromFile(N);
  //  printContentToConsole(content,N);

    printf("Max no of collisions: %d ", elementInsert(N, size));
    printf("Nr of resizes: %d", nrOfResizes);


    return 0;
}
