#include <stdio.h>
#include <stdlib.h>

#include "HashTable.h"
#include "HashFunctions.h"
#include "io.h"

int main() {

    const int N = 1000;

    int nISF = 3, iISF;
    float ISF[] = {.20, .25, .50}, kISF;

    int nMFF = 6, iMFF;
    float MFF[] = {.60, .75, .80, .83, .85, .90}, kMFF;

    const int noOfHashTables = 3;
    HashTable** ht = (HashTable**) malloc(noOfHashTables * sizeof(HashTable*));

    char** contents;
    contents = readFromFile(N);

    FILE *table = fopen("table.txt", "w");
    fprintf(table, "ANALYSIS FOR N = %d\n\n", N);
    fprintf(table, "    |    |    MAX_COL_COUNT|     RESIZE_COUNT|\n");
    fprintf(table, " ISF| MFF|   H1|   H2|   H3|   H1|   H2|   H3|\n");
    fprintf(table, "----------------------------------------------\n");

    int noOfBuckets;
    int i, j;
    int colCount;
    int maxColCount;//[noOfHashTables];

    for (iISF = 0; iISF < nISF; iISF++) {
        kISF = ISF[iISF];
        noOfBuckets = kISF * N;

        for (iMFF = 0; iMFF < nMFF; iMFF++) {
            kMFF = MFF[iMFF];

            fprintf(table, "%4g|%4g|", kISF, kMFF);

            ht[0] = newHashTable(noOfBuckets, kMFF, &hashFunction1);
            ht[1] = newHashTable(noOfBuckets, kMFF, &hashFunction2);
            ht[2] = newHashTable(noOfBuckets, kMFF, &hashFunction3);


            // insert contents into hash tables
            for (j = 0; j < noOfHashTables; j++) {

                maxColCount = 0;
                for (i = 0; i < N; i++) {
                    colCount = insertElement(ht[j], contents[i]);
                    if (maxColCount < colCount) {
                        maxColCount = colCount;
                    }
                }
                fprintf(table, "%5d|", maxColCount);
            }

            for (j = 0; j < noOfHashTables; j++) {
                fprintf(table, "%5d|", ht[j]->size / noOfBuckets);
            }

            fprintf(table, "\n");
            ht[0] = deleteHashTable(ht[0]);
            ht[1] = deleteHashTable(ht[1]);
            ht[2] = deleteHashTable(ht[2]);
        }
    }

    free(ht);
    fprintf(table, "----------------------------------------------\n");
    fclose(table);
    return 0;
}
