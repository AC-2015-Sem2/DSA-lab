#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "HashTable.h"
#include "io.h"

int main() {
    int nISF = 7;
    float ISF[] = {0.1, 0.2, 0.3, 0.35, 0.50, 0.75, 0.85};
    int iISF;

    const int noOfHashTables = 4;
    HashTable** ht = (HashTable**) malloc (noOfHashTables * sizeof(HashTable*));

    // from file
    const int N = 5000;
    char** contents;

    int i, j;
    contents = readFromFile(N);

    // for statistics;
    float avg, dev[4];

    int noOfBuckets;
    float kISF;

    FILE* devTable = fopen("devtable.txt", "w");
    fprintf(devTable, "Deviations table for N =%d\n\n", N);
    fprintf(devTable, " ISF|     hf0|     hf1|     hf2|     hf3|\n"); // table header
    fprintf(devTable, "-----------------------------------------\n");
    for (iISF = 0; iISF < nISF; iISF++) {
        kISF = ISF[iISF];
        noOfBuckets = N * kISF;

        ht[0] = newHashTable(noOfBuckets, &hashFunction0);
        ht[1] = newHashTable(noOfBuckets, &hashFunction1);
        ht[2] = newHashTable(noOfBuckets, &hashFunction2);
        ht[3] = newHashTable(noOfBuckets, &hashFunction3);

        for (i = 0; i < N; i++) {
            for (j = 0; j < noOfHashTables; j++) {
                insertElement(ht[j], contents[i]);
            }
        }

        // statistics
        avg = 1.0 / kISF; // NoOfElements = N, NoOfBuckets = kISF * N
        // avg elements / buckets, same for every hash table
        // because we always insert every element

        // compute deviations
        for (i = 0; i < noOfHashTables; i++) {
            dev[i] = 0.0;
        }

        //printf("%d", ht[0]->listArray[0]->size);
        for (j = 0; j < noOfHashTables; j++) {
            for (i = 0; i < noOfBuckets; i++) {
                dev[j] += (ht[j]->listArray[i]->size - avg) *
                          (ht[j]->listArray[i]->size - avg);
            }
        }


        // avg the deviations

        fprintf(devTable, "%4g|", kISF);
        for (j = 0; j < noOfHashTables; j++) {
            dev[j] /= noOfBuckets;
            dev[j] = sqrt(dev[j]);

            fprintf(devTable, "%8g|", dev[j]);
        }
        fprintf(devTable, "\n");

        // clean up
        for (j = 0; j < noOfHashTables; j++) {
            delHashTable(ht[j]);
        }
    }

    fprintf(devTable, "-----------------------------------------\n");
    fclose(devTable);
    free(ht);
    return 0;
}
