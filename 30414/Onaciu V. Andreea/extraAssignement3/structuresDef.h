
typedef struct nod
{
    struct nod* left;
    struct nod* right;
    char data[10];
} nodeT;
typedef struct node
{
    char data[10];
    struct node *next;
    struct node *prev;
} nodeL;
nodeL *head,*tail;
