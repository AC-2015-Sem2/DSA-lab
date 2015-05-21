#include "list.h"
#include "stdlib.h"
static const float INITIAL_HT_SIZE_FACTOR = .33;

listT * hashTable;
int size;

void addElements(char ** content, int N);

int hashFunction(char * content);

void initHashTable(int N);

void insertElement(char * element);

void computeDistributionsPerBucket();


