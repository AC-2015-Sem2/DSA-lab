#include <stdio.h>
#include <stdlib.h>
#define INF -99999999

typedef struct node
{
    struct node*left;
    struct node*right;
    char* data;
} nodeT;

typedef struct st_node
{
    char *data;
    struct st_node*next;
    struct st_node*prev;
} nodeL;
nodeL *head, *tail;

void prettyPrint(nodeT *root,int recLevel) //! root, index, length, reccurence level
{
    if(root==NULL)
    {
        recLevel--; //! reached leaf, must decrement recurence level
        return;
    }
    recLevel++; //! otherwise increment it
    prettyPrint(root->right,recLevel); //! keep going right in the tree
    int j=0;

    //! print spaces for the appropriate recurence level
    for(j=0; j<recLevel-1; j++)
    {
        printf("     ");
    }
//test
    //! then print value
    printf("%d ",root);

    //! print  a new line
    printf("\n");

    prettyPrint(root->left,recLevel); //! keep going left in the tree
}
void AddLast(char *data)
{
    if (head==NULL)
    {
        head=(nodeL*)malloc(sizeof(nodeL));
        head->data=data;
        head->next=NULL;
        head->prev=NULL;
        tail=head;
    }
    else
    {
        nodeL* newNode=(nodeL*)malloc(sizeof(nodeL));
        newNode->data=data;
        newNode->next=NULL;
        newNode->prev=head;
        newNode->next = NULL;
        tail->next=newNode;
        tail=newNode;
    }
}
//
void traverseList(FILE *f, nodeL *aux)
{
    aux=head;
    while (aux!=NULL)
    {
        fprintf(f, "%s ", aux->data);
        aux=aux->next;
    }
    fprintf(f,"\n");
}

nodeT* createNode(char *d)
{
    nodeT* Newnode;
    Newnode=(nodeT*)malloc (sizeof(nodeT));
    Newnode->data=d;
    Newnode->right=NULL;
    Newnode->left=NULL;

    return Newnode;
}

nodeT* createBinTree(FILE*f)
{
    nodeT* p;
    char *data=(char*)malloc(sizeof(char)*10);
    fscanf(f, "%s", data);
    if(strcmp(data, "*")==0)
        return NULL;
    else
    {
        p=createNode(data);
        p->left=createBinTree(f);
        p->right=createBinTree(f);
    }
    return p;
}

nodeL *getListFromTree(nodeT *root)
{
    if(root!=NULL)
    {
        AddLast(root->data);
        getListFromTree(root->left);
        getListFromTree(root->right);
    }
    else
    {
        AddLast(INF);
    }
    return head;
}
nodeT* getTreeFromList()
{
    char* data=head->data;
    nodeT*p;
    head=head->next;
    if(data==INF)
        return NULL;
    else
    {
        p=createNode(data);
        p->left=getTreeFromList();
        p->right=getTreeFromList();
    }
    return p;
}

int main()
{

    FILE *f;
    f=fopen("input.dat","r");
    nodeT * root=createBinTree(f);
    nodeL * firstFromList=getListFromTree(root);
    traverseList(f,firstFromList);
    root=getTreeFromList(&firstFromList);
    prettyPrint(root, 0);
    fclose(f);
    return 0;
}
