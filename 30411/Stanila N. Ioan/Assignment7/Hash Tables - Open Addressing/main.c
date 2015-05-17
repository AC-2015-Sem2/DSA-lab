#include "files.h"
#include "io.h"
#include "hashTable.h"

int main()
{
    int N = _25000;
    char ** content = readFromFile(N);
    //printContentToConsole(content,N);
    initHashTable(N);
    int i = 0, col = 0;
    int nrOfRehash = 0;
    int maxCol = 0;
    int elWith0Col = 0;
    int insertOK = 1;
    while (i < N) {
        if (insertOK) {
            printf("Inserting elements...\n");
            insertOK = 0;
        }
        if (getFillFactor() > MAX_FILL_FACTOR) {
            printf("%d: ", ++nrOfRehash);
            resizeHashTable();
            insertOK = 1;
        }
        col = insertElement(content[i]);
        if (col > maxCol)
            maxCol = col;
        if (col == 0)
            elWith0Col++;
        //printf("%d: i; %d col\n", i, col);
        i++;
    }
    printf("Done!\n");
    printf("%d elements had 0 collisions\n", elWith0Col);
    printf("Max num of collisions: %d\n", maxCol);
    return 0;
}
