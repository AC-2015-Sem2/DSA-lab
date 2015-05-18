
static const float INITIAL_HT_SIZE_FACTOR = .25;
static const float MAX_FILL_FACTOR = .80;
static const int MAX_STRING_LENGTH = 64;

char ** hashTable;
char ** content;
int size;
int n, N;


int hashFunction(char * content, int i);

void initHashTable(int N);
float getFillFactor();
void resizeHashTable();
int insertElement(char * element, int i);



