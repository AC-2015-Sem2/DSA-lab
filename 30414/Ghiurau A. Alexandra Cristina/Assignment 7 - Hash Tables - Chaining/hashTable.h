#include "list.h"

static const float INITIAL_HT_SIZE_FACTOR = .85;

listT * hashTable;
int size;

//! hash function relates stuff
int getSum0(char * content);
int getSum1(char * content);

int hashFunction0(char * content, int nrOfBuckets);
int hashFunction1(char * content, int nrOfBuckets);
int hashFunction2(char * str, int nrOfBuckets);
int hashFunction3(char * str, int nrOfBuckets);


void initHashTable(int N, int nrOfBuckets);

void insertElement(char * element, int nrOfBuckets);

void computeDistributionsPerBucket(int N, int nrOfBuckets);


