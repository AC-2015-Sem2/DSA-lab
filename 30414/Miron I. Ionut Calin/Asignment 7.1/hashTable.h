
static const float INITIAL_HT_SIZE_FACTOR = .50;
static const float MAX_FILL_FACTOR = 0.90;

char ** hashTable;
int size, nrOfResizes;


int hashFunction(char * content, int i);
int hashFunction2(char * content, int i);
int hashFunction3(char * content, int i);

void initHashTable(int N);
float getFillFactor();
void resizeHashTable();
int insertElement(char * element);



