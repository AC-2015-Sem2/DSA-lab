
const float INITIAL_HT_SIZE_FACTOR = .25;
const float MAX_FILL_FACTOR = .80;

char ** hashTable;
char ** content;
int size;
int n;
int N;

int hashFunction(char * content, int i);

void initHashTable(int N);
float getFillFactor();
void resizeHashTable();
int insertElement(char * element,int i);



