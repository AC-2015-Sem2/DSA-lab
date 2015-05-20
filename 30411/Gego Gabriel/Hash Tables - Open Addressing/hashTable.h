static const float INITIAL_HT_SIZE_FACTOR = .50;
static const float MAX_FILL_FACTOR = .90;

char ** hashTable;
int size;
int hashFunction1(char * content, int i);
int hashFunction2(char * content, int i);
int hashFunction3(char * content, int i);
int nrOfResizes;

void initHashTable(int N);
float getFillFactor();
void resizeHashTable();
int insertElement(char * element);
