typedef struct Queue
{
    int data;
    struct Queue* next;
} nodQueue;
typedef struct
{
nodQueue *head,*tail;
} sentinel;

void generateWorst(int **x, int n);

void generateBest(int **x, int n);

void generateAverage(int **x, int n);

void printToScreen(int *x, int n);

void resetArray(int **x, int n);

void removeFiles();

char * formFileName(const char * funct, char * type);

int itsEmpty(sentinel* x);

int maxNrOfDigits(int *x,int n);

int dequeue(sentinel* q);

void enqueue(sentinel* q,int x);

sentinel* initializeQueueArray(int n);

