typedef struct st_node node;
struct st_node
{
    int data;
    node* next;
};

typedef struct st_list List;
struct st_list
{
    node* head;
    node* tail;
};

void initList(List* lst);
node* createNode(int data);
void destroyNode(node** dst);
int peekNodeData(List* lst);
void enq(List* lst, int data);
void deq(List* lst);


void generateWorst(int **x, int n);

void generateBest(int **x, int n);

void generateAverage(int **x, int n);

void printToScreen(int *x, int n);

void resetArray(int **x, int n);

void removeFiles();

char * formFileName(const char * funct, char * type);

