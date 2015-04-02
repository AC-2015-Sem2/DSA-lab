#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NodeT{
    char *data;
    struct NodeT *left;
    struct NodeT *right;
}NodeT;

NodeT *root;

typedef struct NodeL{
    char *data;
    struct NodeL *prev;
    struct NodeL *next;
}NodeL;

NodeL *head, *tail;

NodeT *createBinTree()
{
    char *data=(char*) malloc(sizeof(char)*20);
    scanf("%s",data);
    if(strcmp(data,"*")==0)
    return NULL;
    else
    {
        NodeT *p=(NodeT*)malloc(sizeof (NodeT));
        p->data=data;
        p->left=createBinTree();
        p->right=createBinTree();
        return p;
    }
}


void addLast(char *data)
{
    NodeL *p=(NodeL*) malloc(sizeof (NodeL));
    p->data=data;
    if(head==NULL)
    {
        p->prev=NULL;
        p->next=NULL;
        head=p;
        tail=head;
    }
    else
    {
        tail->next=p;
        p->prev=tail;
        p->next=NULL;
        tail=p;
    }
}

NodeL *getLfromT(NodeT *root)
{
    if(root==NULL)
    addLast("*");
    else
    {
            addLast(root->data);
            getLfromT(root->left);
            getLfromT(root->right);
    }
    return head;
}

void printList()
{
    NodeL *x=head;
    while(x != NULL)
    {
        printf("%s ",x->data);
        x=x->next;
    }
    printf("\n");
}


NodeT *getTfromL(NodeL **head)
{
   if(strcmp((*head)->data,"*")==0)
   {
       *head=(*head)->next;
       return NULL;
   }
   else
    {
        NodeT *p=(NodeT*)malloc(sizeof (NodeT));
        p->data=(*head)->data;
        *head=(*head)->next;
        free((*head)->prev);
        p->left=getTfromL(head);
        p->right=getTfromL(head);
        return p;
    }
}

void delTree(NodeT *root)
{
    if(root==NULL)
    return;
    delTree(root->left);
    delTree(root->right);
    free(root);
}

void prettyPrint(NodeT *root,int level)
{
    if(root==NULL)
    {
        level--;
        return;
    }
    level;
    prettyPrint(root->right,level);
    int j=0;
    for(j=0; j<level-1; j)
    {
        printf("    ");
    }
    printf ( "%s " ,root->data );
    printf("\n");
    prettyPrint(root->left,level);

}

int main()
{
   root=createBinTree();
   head=getLfromT(root);
   printf("tree=>list: \n");
   printList();
   delTree(root);
   root=NULL;
   root=getTfromL(&head);
   printf("list=>tree: \n");
   prettyPrint(root,0);
   return 0;
}
