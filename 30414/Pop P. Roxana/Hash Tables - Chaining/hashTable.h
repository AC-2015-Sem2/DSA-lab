#include "list.h"

static const float INITIAL_HT_SIZE_FACTOR = .85;

listT * hashTable;
int size;

///prototypes for hash functions
int h0(char * content);
int h1(char* content);
int h2(char*element);
int h3(char*element);

///pointer to function
int (*hashFunction)(char*);

void initHashTable(int N);

void insertElement(char * element);

void computeDistributionsPerBucket();
float getStandardDeviation();


