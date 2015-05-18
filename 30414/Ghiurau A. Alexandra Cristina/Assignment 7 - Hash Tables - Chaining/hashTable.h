#include "list.h"

static const float INITIAL_HT_SIZE_FACTOR = .85;

listT * hashTable;
int size;


int getSum(char * content);
int getProduct(char *content);
int getSum2(char * content);
int getSum3(char * content);

int hashFunction0(char * content, int nrOfBuckets);
int hashFunction1(char * content, int nrOfBuckets);

void initHashTable(int N, int nrOfBuckets);

void insertElement(char * element, int nrOfBuckets);

void computeDistributionsPerBucket(int N, int nrOfBuckets);


