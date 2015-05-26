
void generateWorst(int **x, int n);

void generateBest(int **x, int n);

void generateAverage(int **x, int n);

void printToScreen(int *x, int n);

void resetArray(int **x, int n);

void removeFiles();

char * formFileName(const char * funct, char * type);

//RADIX:
typedef struct node
{
    int data;
    struct node* next;
} nodeT;

typedef struct queueS
{
    nodeT * head, *tail;
} queueT;

nodeT * createNode(int data);
queueT* initQueueArray(int n);
int dequeue(queueT *q);
void enqueue(queueT *q, int data);
int isEmpty(queueT q);
int getmaxNrOfDigits(int *x, int n);
