
static const float INITIAL_HT_SIZE_FACTOR = .50;
static const float MAX_FILL_FACTOR = .90;

char ** hashTable; //array de stringuri
int nrOfResizes;



int insertElement(char * element, char ** hash, int  size);
int getMaximum(int N);
int elementInsert(int N, int size);

void initHashTable(int N, int size);
float getFillFactor(int size);
void resizeHashTable(int N, int *size);
void deleteHash(char **hash, int hashSize);

int hashFunction1(char * content, int i, int hashSize);
int hashFunction2(char * content, int i, int size);
int hashFunction3(char * content, int i, int size);
