#include "list.h"



listT * hashTable;
int size;


int hashFunction(char * content, int i);

void initHashTable(int N);

void insertElement(char * element);

void computeDistributionsPerBucket();


