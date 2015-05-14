#ifndef HASHTABLE_H
# define HASHTABLE_H

#include <stdlib.h>
#include <string.h>

#define INITIAL_HT_SIZE_FACTOR 0.25
#define MAX_FILL_FACTOR 0.80

char ** hashTable;
int size;


int hashFunction(char * content, int i);

void initHashTable(int N);
float getFillFactor();
void resizeHashTable();
int insertElement(char * element);

#endif
