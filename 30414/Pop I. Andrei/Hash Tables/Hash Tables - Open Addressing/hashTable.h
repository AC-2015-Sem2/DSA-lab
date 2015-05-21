# include "io.h"

static float INITIAL_HT_SIZE_FACTOR = .50;
static float MAX_FILL_FACTOR = .90;

char ** hashTable;
int size, nrOfResizes, *collisions;

int hashFunction0(char *, int , int);
int hashFunction1(char *, int, int);
int hashFunction2(char *, int, int);
int hashFunction3(char *, int, int);

void addToHashTbale(int);
void initHashTable(int);
float getFillFactor();
void resizeHashTable();
void addToHashTable(int);
int insertElement(char * element, int, char **);
int maxCollisions(int);

