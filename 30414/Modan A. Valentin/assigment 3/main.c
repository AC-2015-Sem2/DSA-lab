# include <stdio.h>
FILE *input,*output;
typedef struct nod
{
    struct nod *left, *right;
    char *data;
}NodeT;

typedef struct node
{
    struct node *next, *prev;
    char *data;
}NodeL;

NodeT* createNODE(char *c)
{
    NodeT *p;
    p=(NodeT*)malloc(sizeof(NodeT));
    p->data=c;
    p->left=NULL;
    p->right=NULL;
    return p;
}

NodeT* createBinTree()
{
    NodeT *p;
    char *data=(char*)malloc(sizeof(char)*10);
    fscanf(input,"%s",data);
    if(strcmp(data,"*")==0)
        return NULL;
    else
    {
        p=createNODE(data);
        p->left=createBinTree();
        p->right=createBinTree();
    }
    return p;
}


void print(NodeT *root)
{
    if(root!=NULL)
        {
            fprintf(input,"%s ",root->data);
            print(root->left);
            print(root->right);
        }
}

void AL(NodeL **head, char *data)
{
    if (*head == NULL)
    {
        *head = (NodeL*)malloc(sizeof(NodeL));
        (*head)->data = data;
        (*head)->next = NULL;
    }
    else
    {
        NodeL *newnode,*p;
        p=*head;
        while (p->next!=NULL)
            p = p->next;
        newnode=(NodeL*)malloc(sizeof(NodeL));
        newnode->data = data;
        newnode->next = NULL;
        newnode->prev = p;
        p->next=newnode;
    }
}

void createList(NodeT *root, NodeL **head)
{
    if(root==NULL)
        AL(head,"*");
    else
        {
        AL(head, root->data);
        createList(root->left,head);
        createList(root->right,head);
        }
}

NodeL *getListFromTree(NodeT *root)
{
    NodeL *head=NULL;
    createList(root,&head);
    return head;
}

void traverseList(NodeL *head)
{
    while(head!=NULL)
    {
        fprintf(output,"%s ",head->data);
        head=head->next;
    }
    fprintf(output,"\n");
}

NodeT *getFromList(NodeL **pointer)

{
    NodeT *p;
    NodeL *firstFromList=*pointer;
    *pointer=(*pointer)->next;
    if(strcmp(firstFromList->data,"*")==0)
        return NULL;
    else
    {
        p=createNODE(firstFromList->data);
        p->left=getFromList(pointer);
        p->right=getFromList(pointer);
        return p;
    }
}

void prettyPrint(NodeT *root,int level)
{
    int i=0;
    if(root==NULL)
        return;
    ++level;
    prettyPrint(root->right,level);
    for(i=0; i<level-1; i++)
        fprintf(output,"   ");
    fprintf(output,"%s\n", root->data);
    prettyPrint(root->left,level);
}



int main()
{

    input=fopen("input.dat", "r");
    output=fopen("output.dat","w");
    NodeT *root = createBinTree();
    NodeL *firstFromList = getListFromTree(root);
    traverseList(firstFromList);
    root=getFromList(&firstFromList);
    prettyPrint(root, 0);

    return 0;
}
