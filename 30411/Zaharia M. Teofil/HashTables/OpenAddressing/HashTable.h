#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "TableElement.h"
#include "HashFunctions.h"

typedef struct s_hashTable {
    int size;
    float maxFillFactor;

    TableElement** entry;

    int* filled;
    int filledCount;

    int (*hashFunction)(char*);
} HashTable;

HashTable* newHashTable(int size,
                        float maxFillFactor,
                        int (*hashFunction)(char*));
HashTable* deleteHashTable(HashTable* ht);
void printHashTable(FILE* out, HashTable* ht);

float getFillFactor(HashTable* ht);
void resizeHashTable(HashTable* ht);

int insertElement(HashTable* ht, char* data);
// returns collision count

void setHashFunction(HashTable* ht, int (*hashFunction)(char*));

HashTable* staticNew(int (*hashFunction)(char*));
#endif // HASHTABLE_H
