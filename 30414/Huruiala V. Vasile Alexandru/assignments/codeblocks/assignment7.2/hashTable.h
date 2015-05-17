#include "list.h"
#include <stdio.h>
#include <stdlib.h>

static const float INITIAL_HT_SIZE_FACTOR = .85;

int hashFunction0(char* content, int size);
int hashFunction1(char* content, int size);
int hashFunction2(char* content, int size);
int hashFunction3(char* content, int size);

void initHashTable(listT** hashTable, int* size, int N);
void insertAllElements(listT* hashTable, int size, int N, char** content);
void insertElement(listT* hashTable, int size, char* element);
void computeDistributionsPerBucket(listT* hashTable, int size, int N, FILE* O);


