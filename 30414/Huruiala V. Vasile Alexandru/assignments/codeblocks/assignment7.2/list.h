typedef struct node nodeT;
struct node
{
    char* content;
    nodeT* next;
};

typedef struct list listT;
struct list
{
    nodeT* head;
    nodeT* tail;
    int size;
};

void addToList(listT* l, char* content);
