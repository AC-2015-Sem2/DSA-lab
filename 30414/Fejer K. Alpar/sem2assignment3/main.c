#include <stdio.h>
#include <stdlib.h>
FILE *f,*g;
typedef struct NodeT
{
    struct NodeT *left, *right;
    char *data;
} NodeT;

typedef struct NodeL
{
    struct NodeL *next, *prev;
    char *data;
} NodeL;
void traverseList(NodeL *head)
{
    while(head!=NULL)
    {
        fprintf(g,"%s ",head->data);
        head=head->next;
    }
    fprintf(g,"\n");
}

NodeT* createNode(char *c)
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
    fscanf(f,"%s",data);
    if(strcmp(data,"*")==0)
        return NULL;
    else
    {
        p=createNode(data);
        p->left=createBinTree();
        p->right=createBinTree();
    }
    return p;
}
NodeT *getTreeFromList(NodeL **pp)
{
    NodeT *p;
    NodeL *firstFromList=*pp;
    *pp=(*pp)->next;
    if(strcmp(firstFromList->data,"*")==0)
        return NULL;
    else
    {
        p=createNode(firstFromList->data);
        p->left=getTreeFromList(pp);
        p->right=getTreeFromList(pp);
        return p;
    }
}

void AddLast(NodeL **head, char *data)
{
    if (*head == NULL)
    {
        *head = (NodeL*)malloc(sizeof(NodeL));
        (*head)->data = data;
        (*head)->next = NULL;
    }
    else
    {
        NodeL *q,*p;
        p=*head;
        while (p->next!=NULL)
            p = p->next;
        q=(NodeL*)malloc(sizeof(NodeL));
        q->data = data;
        q->next = NULL;
        q->prev = p;
        p->next=q;
    }
}
void createList(NodeT *root, NodeL **head)
{
    if(root==NULL)
        AddLast(head,"*");
    else
    {
        AddLast(head, root->data);
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
void prettyPrint(NodeT *root,int level)
{
    int i=0;
    if(root==NULL)
        return;
    prettyPrint(root->right,level+1);
    for(i=0; i<level; i++)
        fprintf(g,"   ");
    fprintf(g,"%s\n", root->data);
    prettyPrint(root->left,level+1);
}
int main()
{
    f=fopen("input.dat", "r");
    g=fopen("output.dat","a");
    NodeT *root = createBinTree();
    NodeL *firstFromList = getListFromTree(root);
    traverseList(firstFromList);
    root=getTreeFromList(&firstFromList);
    prettyPrint(root, 0);
    return 0;
}
