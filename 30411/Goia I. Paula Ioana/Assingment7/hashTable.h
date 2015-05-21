static const float INITIAL_HT_SIZE_FACTOR = .25;
static const float MAX_FILL_FACTOR = .80;
int res=1;
char ** hashTable;
int size;
int maxboom=0;//max number of collisions

int hashFunction(char * content, int i);

void initHashTable(int N);
float getFillFactor();
void resizeHashTable(int N);
int insertElement(char * element,int N);


