#include "list.h"

static const float INITIAL_HT_SIZE_FACTOR = 0.33;

listT * hashTable;
int size;


int hashFunction(char * content);

void initHashTable(int N);

void insertElement(char * element);

void computeDistributionsPerBucket();

double standardDeviation();

