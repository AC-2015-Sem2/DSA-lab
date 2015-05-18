
typedef struct node
{
    char * content;
    struct list * next;             //or list
} nodeT;

typedef struct list
{
    nodeT * head;
    nodeT * tail;
    int size;
} listT;

void addToList(listT *l, char * content);
