#include "io.h"
#include "files.h"
#include "hashTable.h"

int main()
{
    int N = _5000;
    int i, maxim, collision, Resize;

    char ** content = readFromFile(N);
    initHashTable(N);
    maxim = -5;
    Resize = 0;
    i = 0;
    collision = 0;
    printf("Start ! \n");
    while (i < N)
    {
        if (getFillFactor() > MAX_FILL_FACTOR)
        {
            Resize++;
            printf("\tResizing number: %d \n\tLoading ...\n", Resize);
            resizeHashTable();
        }
        collision=insertElement(content[i]);
        if (collision > maxim)
            maxim = collision;
        i++;
    }
    printf("Done !\n");
    printf("The number of collisions in the table is: %d !\n", maxim);
    //printContentToConsole(content,N);
    return 0;
}
