#include "list.h"

static const float INITIAL_HT_SIZE_FACTOR = .33;

listT * hashTable;
int size;

int H0(char * content, int i);
int H1(char * content, int i);
int H2(char * content, int i);
int H3(char * content, int i);
void initHashTable(int N);
void insertElement(char * element);
void computeDistributionsPerBucket();


