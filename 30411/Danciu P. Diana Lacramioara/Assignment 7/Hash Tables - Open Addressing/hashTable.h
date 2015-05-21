static const float INITIAL_HT_SIZE_FACTOR = .20;
static const float MAX_FILL_FACTOR = .75;

char ** hashTable;
int size;

int hashFunction1(char * content, int i);
int hashFunction2(char *content, int i);
int hashFunction3(char *content, int i);

void initHashTable(int N);
float getFillFactor();
void resizeHashTable();
int insertElement(char * element);
