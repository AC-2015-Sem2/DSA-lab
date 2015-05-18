#include "list.h"

static const float INITIAL_HT_SIZE_FACTOR = .33;

listT * hashTable;
int size;


int hashFunction(char * content, int i);

void initHashTable(int N);

void insertElement(char * element);

void computeDistributionsPerBucket();


