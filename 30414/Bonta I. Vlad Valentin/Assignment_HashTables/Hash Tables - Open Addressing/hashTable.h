static const float INITIAL_HT_SIZE_FACTOR = 0.50;
static const float MAX_FILL_FACTOR = 0.9;

char ** hashTable;
int size;


int hashFunction(char * content, int i);

void initHashTable(int N);
float getFillFactor();
void resizeHashTable();
int insertElement(char * element);
