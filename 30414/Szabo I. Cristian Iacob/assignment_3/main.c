#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodeTree
{
    char *data;
    struct nodeTree *left;
    struct nodeTree *right;
} nodeT;

typedef struct nodeList
{
    char *data;
    struct nodeList *prev;
    struct nodeList *next;
} nodeL;


nodeL *head, *tail;
nodeT *root;

nodeT* CreateNode(char *data)
{
    nodeT *p=(nodeT*)malloc(sizeof(nodeT));
    p->data=data;
    p->left=NULL;
    p->right=NULL;
    return p;
}

nodeT *CreateBinTree()
{
    nodeT *p;
    char *c;
    c = (char *)malloc(sizeof(char) * 20);
    scanf("%s", c);
    if(strcmp(c,"*")==0)
        return NULL;
    else
    {
        p=(nodeT*)malloc(sizeof(nodeT));
        p->data=c;
        p->left=CreateBinTree();
        p->right=CreateBinTree();
    }
    return p;

}

void addLast(char *data)
{
    if(head==NULL)
    {
        head = (nodeL*)malloc(sizeof(nodeL));
        head->data=data;
        head->next=NULL;
        tail=head;
    }
    else
    {
        nodeL *new=(nodeL*)malloc(sizeof(nodeL));
        new->data=data;
        new->prev=tail;
        new->next=NULL;
        tail->next=new;
        tail=new;
    }
}

void getListFromTree(nodeT* root)
{
    if(root!=NULL)
    {
        addLast(root->data);
        getListFromTree(root->left);
        getListFromTree(root->right);
    }
    else
        addLast("#");
}

void printlist()
{
    nodeL* x=head;
    while(x!=NULL)
    {
        if(strcmp(x->data, "#") == 0)
            printf("# ");
        else
            printf("%s ",x->data );
        x=x->next;

    }
    printf("\n");
}

nodeT* getTreeFromList()
{
    nodeT *p;
    char *current;
    current=head->data;
    head=head->next;
    if(strcmp(current, "#") == 0)
        return NULL;
    else
    {
        p=CreateNode(current);
        p->left=getTreeFromList();
        p->right=getTreeFromList();
    }
    return p;
}

void printElement (nodeT *root)
{
    printf("%s\n",root->data);
}

void prettyPrint(nodeT *root,int recLevel)
{
    if(root==NULL)
        return;
    recLevel++;
    prettyPrint(root->right,recLevel);
    int j;
    for(j=0; j<recLevel-1; j++)
    {
        printf("    ");
    }
    printElement(root);
    prettyPrint(root->left,recLevel);
}

int main()
{
    nodeT *root=CreateBinTree();
    getListFromTree(root);
    printlist();
    root = getTreeFromList();
    prettyPrint(root,0);
    return 0;
}

