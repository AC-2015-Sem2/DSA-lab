
static const float INITIAL_HT_SIZE_FACTOR = .25;
static const float MAX_FILL_FACTOR = .60;

char ** hashTable;
int size;

int res=0;
int max_col=0;//max number of collisions


int hashFunction(char * content, int i);

void initHashTable(int N);
float getFillFactor();
void resizeHashTable(int N);
int insertElement(char * element,int N);




