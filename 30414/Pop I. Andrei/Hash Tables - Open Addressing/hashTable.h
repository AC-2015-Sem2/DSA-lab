# include "io.h"
#ifndef HASHTABLE_H_INCLUDED
#define HASHTABLE_H_INCLUDED


const float INITIAL_HT_SIZE_FACTOR = .25;
const float MAX_FILL_FACTOR = .80;

char ** hashTable;
int size;

int hashFunction(char *, int , int);

void addToHashTbale(int);
void initHashTable(int );
float getFillFactor();
void resizeHashTable();
int insertElement(char * element, int, char **);


#endif
