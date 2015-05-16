static const float INITIAL_HT_SIZE_FACTOR = .50;
static const float MAX_FILL_FACTOR = .90;


int hashFunction(char * content, int i, int size);
int hashFunction2(char * content, int i, int size);
int hashFunction3(char* content, int i, int size);

void initHashTable(char*** hashTable, int* size, int N);
void destroyHashTable(char*** hashTable, int size);
int elementsInHash(char** hashTable, int size);
float getFillFactor(char** hashTable, int size);
void resizeHashTable(char*** hashTable, int* size);
int insertElement(char** hashTable, char* element, int size);
void insertAllElements(char*** hashTable, int* size, int count, char** content);



