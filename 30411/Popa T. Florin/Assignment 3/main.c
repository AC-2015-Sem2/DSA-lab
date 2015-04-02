#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

typedef struct nodeT
{
    int data;
    struct nodeT* left;
    struct nodeT* right;
} nodeT;

typedef struct nodeL
{
    int data;
    struct nodeL* next;
} nodeL;
nodeL* firstFromList;
nodeL* tail;

nodeT* createBinTree()
{
    nodeT* p;
    char content[20];
    scanf("%s",content);
    if(strcmp(content,"*")==0)
        return NULL;

    p=(nodeT*)malloc(sizeof(nodeT));
    p->data=atoi(content);

    p->left=createBinTree();
    p->right=createBinTree();

    return p;
}

void add_last(int x)
{
    if(firstFromList==NULL)
    {
        firstFromList=(nodeL*)malloc(sizeof(nodeL));
        firstFromList->data=x;
        firstFromList->next=NULL;
        tail=firstFromList;
    }
    else
    {
        nodeL *temp;
        temp=(nodeL*)malloc(sizeof(nodeL));
        temp->data=x;
        temp->next=NULL;
        tail->next=temp;
        tail=temp;
    }
}

nodeL* getListFromTree(nodeT* root)
{
    if(root!=NULL)
    {
        int aux=root->data;
        add_last(aux);
        getListFromTree(root->left);
        getListFromTree(root->right);
    }
    return firstFromList;
}

void traverseList(nodeL*firstFromList)
{
    nodeL *temp=firstFromList;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}


void prettyPrint(nodeT *n, int x)
{
    for(int j=0; j<=x; j++)
    {
        printf("\t");
    }
    printf("%d\n", n->data);
    if(n->right != NULL)
    {
        prettyPrint(n->right, x+1);
    }
    if(n->left != NULL)
    {
        prettyPrint(n->left, x+1);
    }
}

int main()
{
    nodeT *root=createBinTree();
    nodeL *firstFromList=getListFromTree(root);
    traverseList(firstFromList);
    printf("\n");
    prettyPrint(root,0);
    return 0;
}
