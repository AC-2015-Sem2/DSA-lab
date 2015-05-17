#include "io.h"
#include "files.h"
#include "hashTable.h"
//# include "header.h"

int main()
{
    int N = 1000;

    //int N = 5;

    addToHashTable(N);

    int i;

    //printContentToConsole(hashTable, size);

    //printHashTableToConsole();

    printf("Max number of collisions: %d\n", maxCollisions(N));
    printf("Nr of resizes: %d", nrOfResizes);

    return 0;
}
