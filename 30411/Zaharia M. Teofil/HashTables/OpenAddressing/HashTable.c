#include "HashTable.h"

#include <stdlib.h>
#include <stdio.h>

HashTable* newHashTable(int size,
                        float maxFillFactor,
                        int (*hashFunction)(char*)) {
    HashTable* ht = (HashTable*) malloc (sizeof(HashTable));

    ht->size = size;
    ht->maxFillFactor = maxFillFactor;

    ht->entry = (TableElement**) malloc (ht->size * sizeof(TableElement*));
    ht->filled = (int*) calloc(ht->size, sizeof(int));
    // initialize with 0s

    ht->filledCount = 0; // count up with every insertion

    ht->hashFunction = hashFunction;

    return ht;
}

HashTable* deleteHashTable(HashTable* ht) {
    if (ht == NULL)
        return NULL;

    int i;
    for (i = 0; i < ht->size; i++) {
        if (ht->filled[i])
            ht->entry[i] = deleteTableElement(ht->entry[i]);
    }

    free(ht->entry);
    free(ht->filled);
    free(ht);

    return NULL;
}

void printHashTable(FILE* out, HashTable* ht) {
    if (ht == NULL) {
        fprintf(out, "EMPTY\n");
        return;
    }

    int i;
    fprintf(out, "index  filled  contents\n");
    for (i = 0; i < ht->size; i++) {
        fprintf(out, "%-5d  %-6s  ", i, ht->filled[i] ? "YES" : "NO");
        if (ht->filled[i])
            printElement(out, ht->entry[i]);
        else
            fprintf(out, "EMPTY");
        fprintf(out, "\n");
    }
    printf("\n");
}

float getFillFactor(HashTable* ht) {
    return (float)(ht->filledCount) / ht->size;
}

void resizeHashTable(HashTable* ht) {
    // create new empty entry and filled array
    TableElement** newEntry = (TableElement**) malloc (2 * ht->size * sizeof(TableElement*));
    int* newFilled = (int*) calloc(2 * ht->size, sizeof(int));

    // store old ones for rehashing
    TableElement** oldEntry = ht->entry;
    int* oldFilled = ht->filled;

    // swap old with new
    ht->entry = newEntry;
    ht->filled = newFilled;
    ht->size = 2 * ht->size;
    ht->filledCount = 0; // reset filled count

    // rehash every element
    int i;
    for (i = 0; i < ht->size / 2; i++) {
        if (oldFilled[i])
            insertElement(ht, oldEntry[i]->data);
    }
    // no danger of ht->resize being called recursively
    // ht->size was doubled

    // free the old entries
    for (i = 0; i < ht->size / 2; i++) {
        if (oldFilled[i])
            oldEntry[i] = deleteTableElement(oldEntry[i]);
    }
    free(oldEntry);
    free(oldFilled);
}

int insertElement(HashTable* ht, char* data) {
    //printf("%d ", ht->filledCount);

    if (getFillFactor(ht) > ht->maxFillFactor) {
        //printf("%g %g\n", getFillFactor(ht), ht->maxFillFactor);
        resizeHashTable(ht);
    }

    int (*hf)(char*) = ht->hashFunction;

    int i = 0;
    int j = ((*hf)(data) + i) % ht->size;

    // find position
    while (ht->filled[j]) {
        i++;
        j = ((*hf)(data) + i) % ht->size;
    }

    // insert element
    ht->entry[j] = newTableElement(data);
    ht->filled[j] = 1;
    ht->filledCount++;

    return i; // collision count;
}

void setHashFunction(HashTable* ht, int (*hashFunction)(char*)) {
    ht->hashFunction = hashFunction;
}


HashTable* staticNew(int (*hashFunction)(char*)) {
    HashTable* ht = newHashTable(10, .25, hashFunction);

    insertElement(ht, "Hello");
    insertElement(ht, "GoodBye");
    insertElement(ht, "Alpha");
    insertElement(ht, "Beta");
    insertElement(ht, "Gamma");

    return ht;
}

