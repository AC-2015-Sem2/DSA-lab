#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node
{
    int  content;
    struct node *left, *right;
} NodeT;

typedef struct nodel
{
    int x;
    struct nodel *next;
}NodeL;
NodeL *Qhead,*Qtail;
NodeT *createNode(int content)
{
    NodeT* newNode = (NodeT*)malloc(sizeof(NodeT));
    newNode->content = content;
    newNode->left = NULL;
    newNode->right= NULL;
    return newNode;
}
void printElement(NodeT *root)
{
    printf("%d ",root->content);
}
NodeT *createBinTREE(FILE *pf)
{
    NodeT *p;
    char *content=(char*)malloc(sizeof(char));
    fscanf(pf,"%s",content);
    if (strcmp(content,"*")==0)
        return NULL;
    else
    {
        p=createNode(atoi(content));
        p->left=createBinTREE(pf);
        p->right=createBinTREE(pf);
    }
    return p;
}
void enqueue(int x)
{
    if (Qhead==NULL)
    {
        Qhead=(NodeL*)malloc(sizeof(NodeL));
        Qhead->x=x;
        Qhead->next=NULL;
        Qtail=Qhead;
    }
    else
    {

        NodeL *p=(NodeL*)malloc(sizeof(NodeL));
        p->x=x;
        p->next=NULL;
        Qtail->next=p;
        Qtail=p;
    }
}

void preorder(NodeT * root)
{
    if ( root != NULL )
    {
        enqueue(root->content);
        preorder( root->left) ;
        preorder( root->right) ;
    }
    else
    {
        enqueue(0);
    }
}

void prettyPrint(NodeT *root,int recLevel) //! root, index, length, reccurence level
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
    //! then print value
    printElement(root);

    //! print  a new line
    printf("\n");

    prettyPrint(root->left,recLevel); //! keep going left in the tree
}
void dequeue()
{
    if (Qhead!=NULL)
    {
        NodeL *p=Qhead->next;
        free(Qhead);
        Qhead=p;
    }

}
NodeT *listotree()
{

    NodeT *p;
    int content;
    content=Qhead->x;
    Qhead=Qhead->next;
    if (content==0)
        return NULL;
    else
    {
        p=createNode(content);
        p->left=listotree();
        p->right=listotree();
    }
    return p;
}
void printl()
{
    NodeL *a=Qhead;
    while (a!=NULL)
    {
        printf("%d ",a->x);
        a=a->next;
    }
}
int main()
{
    FILE *pf=fopen("data.txt","r");
    NodeT *root=createBinTREE(pf);
    prettyPrint(root,0);
    preorder(root);
    root=listotree();
    prettyPrint(root,0);
    return 0;
}
