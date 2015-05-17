#include "list.h"

static const float INITIAL_HT_SIZE_FACTOR = .35;

listT * hashTable;
int size;


int hashFunction0(char * content);
int hashFunction1(char * content);
int hashFunction2(char * content);
int hashFunction3(char * content);
int hashFunction4(char * content);
int hashFunction5(char * content);

void initHashTable(int N);

void insertElement(char * element);

void computeDistributionsPerBucket();


