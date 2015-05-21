#include <math.h>
#include "io.h"
#include "files.h"
#include "hashTable.h"

int main()
{
    int N = _100;

    char ** content = readFromFile(N);
    //printContentToConsole(content,N);
    initHashTable(N);
    int maxCol = 0, r, nrCol;
    for (r=0; r<N; r++){
        nrCol = insertElement(content[r]);
        if (nrCol > maxCol){
            maxCol = nrCol;
        }
    }
    printf("%d is the maximum number of collisions that occurred.\n", maxCol);
    printf("The hash table has been resized %d times.\n", (int)log2(size/(N*INITIAL_HT_SIZE_FACTOR)));
    return 0;
}
