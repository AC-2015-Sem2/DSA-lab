#include "io.h"
#include "files.h"
#include "hashTable.h"
#include <string.h>
int main()
{   int MAX_COLLISIONS = 0;
    int N = _1000,collisions=0, i;
    char ** content = readFromFile(N);

    initHashTable(N);

    for(i=0; i<N; i++)
    {
        printf("Element %d   ; collisions: %d    ",i,insertElement(content[i]));
        collisions = collisions + insertElement(content[i]);
        printf(", fillfactor: %.2f\n", getFillFactor());
        if(MAX_COLLISIONS < insertElement(content[i]))
            MAX_COLLISIONS = insertElement(content[i]);
    }
    printf("Total number of collisions: %d \nNr Of resizes: %d \nNr of Max Collisions : %d", collisions, nrOfResizes,MAX_COLLISIONS);
return 0;
}

