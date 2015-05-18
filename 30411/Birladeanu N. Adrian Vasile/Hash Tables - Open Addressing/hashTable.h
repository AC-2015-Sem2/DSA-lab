
static const float INITIAL_HT_SIZE_FACTOR = .25;
static const float MAX_FILL_FACTOR = .85;

char ** hashTable;
int size;


int hashFunction(char * content, int i);

void initHashTable(int N);
float getFillFactor();
void resizeHashTable();
int insertElement(char * element);
void fillHashTable(char** content, int N);



