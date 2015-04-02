
typedef struct nod
{
    struct nod* left;
    struct nod* right;
    char data;
} nodeT;
typedef struct node
{
    char data;
    struct node *next;
    struct node *prev;
} nodeL;
nodeL *head,*tail;
