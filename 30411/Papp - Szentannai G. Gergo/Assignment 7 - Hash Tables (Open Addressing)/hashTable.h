#include <stdlib.h>

static const float INITIAL_HT_SIZE_FACTOR = .3;
static const float MAX_FILL_FACTOR = .8;

char ** hashTable;
int size;
int nrOfResize;

int hashFunction(char * content, int i);

void initHashTable(int N);
float getFillFactor();
void resizeHashTable();
int insertElement(char * element);



