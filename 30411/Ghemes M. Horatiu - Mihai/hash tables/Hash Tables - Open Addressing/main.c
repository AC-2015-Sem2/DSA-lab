#include "io.h"
#include "files.h"
#include "hashTable.h"
#include <string.h>
int main()
{
    int N = _1000;
    char ** content = readFromFile(N);
    //printContentToConsole(content,N);
    initHashTable(N);
    int collisions=0;
    int resizes=0;
    int i;
    float Fillfactor;
    for(i=0; i<N; i++)
    {
        collisions = collisions+insertElement(content[i]);
        Fillfactor= getFillFactor();
        if(Fillfactor>MAX_FILL_FACTOR && size<N)
        {
            resizes++;
            resizeHashTable(N);
            i=0;
        }
    }
        printf("Total number of collisions: %d \nTimes the has table was resized: %d \n", collisions, resizes);
}
