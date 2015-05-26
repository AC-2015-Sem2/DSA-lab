static const float INITIAL_HT_SIZE_FACTOR = .25;
static const float MAX_FILL_FACTOR = .80;
int res=1;
char ** hashTable;
int size;
int nrmax=0;

int hashFunction(char * content, int i);
int hashFunction1(char * content, int i);
int hashFunction2(char * content, int i);
int hashFunction3(char* content);

void initHashTable(int N);
float getFillFactor();
void resizeHashTable(int N);
int insertElement(char * element,int N);
