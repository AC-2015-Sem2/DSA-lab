#include "list.h"

static const float INITIAL_HT_SIZE_FACTOR = .33;

listT * hashTable;
int size;


int hashFunction(char * content, int nrOfBuckets);

void initHashTable(int N, int nrOfBuckets);

void insertElement(char * element, int nrOfBuckets);

void computeDistributionsPerBucket(int N, int nrOfBuckets);


