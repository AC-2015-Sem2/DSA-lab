#include "list.h"

static const float INITIAL_HT_SIZE_FACTOR = .35;

listT * hashTable;
int size;


int hashFunction0(char * content,int i);
int hashFunction(char * content);
int hashFunction1(char* content,int i);

void initHashTable(int N);

void insertElement(char * element);

void computeDistributionsPerBucket();


