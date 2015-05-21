static const float INITIAL_HT_SIZE_FACTOR = .25;
static const float MAX_FILL_FACTOR = .83;

char ** hashTable;
int size,nrOfResizes;


int hashFunction(char * content,int contor);

void initHashTable(int N);
float getFillFactor();
void resizeHashTable();
int insertElement(char * element);

 int hashFunction1(char* content,  int len);
