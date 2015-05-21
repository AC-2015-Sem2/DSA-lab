#include "list.h"
#include "io.h"

static const float INITIAL_HT_SIZE_FACTOR = .85;

listT * hashTable;
int size;

void printHashToConsole();

void addContentToHash(char **, int);

int hashFunction(char * content);

void initHashTable(int N);

void insertElement(char * element, listT *, int);

void computeDistributionsPerBucket(FILE *);
