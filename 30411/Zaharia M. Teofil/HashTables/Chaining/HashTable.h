#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "LinkedList.h"

typedef struct s_hashTable {

    int size;
    ListT** listArray;

    int (*hashFunction)(char*);

} HashTable;

HashTable* newHashTable(int size, int (*hashFunction)(char*));
HashTable* delHashTable(HashTable* ht);

void setHashFunction(HashTable* ht, int (*newHashFunction)(char*));
void insertElement(HashTable* ht, char* element);
void computeDistributionsPerBucket(HashTable* ht, int scale);

int hashFunction0(char* element);
int hashFunction1(char* element);
int hashFunction2(char* element);
int hashFunction3(char* element);

#endif // HASHTABLE_H
