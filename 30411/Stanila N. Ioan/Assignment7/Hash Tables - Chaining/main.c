#include "io.h"
#include "files.h"
#include "hashTable.h"

#include <math.h>

double standardDeviation() {
    double avgVal = 0;
    for (int i = 0; i < size; i++)
        avgVal += hashTable[i].size;
    avgVal /= size;
    double avgStdDev = 0;
    for (int i = 0; i < size; i++)
        avgStdDev += (hashTable[i].size - avgVal)*(hashTable[i].size - avgVal);
    avgStdDev /= size;
    return sqrt(avgStdDev);
}

int main()
{
    int N = _25000;

    char ** content = readFromFile(N);
    //printContentToConsole(content,N);
    initHashTable(N);
    int i = 0;
    while (i < N) {
        insertElement(content[i]);
        //printf("%d: ins\n", i);
        i++;
    }
    computeDistributionsPerBucket();
    printf("Standard deviation: %.3f\n", standardDeviation());
    return 0;
}
