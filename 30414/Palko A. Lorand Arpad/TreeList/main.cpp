#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NTREE
{
    int data;
    struct NTREE *left, *right;
} NodeT;

typedef struct List
{
    char *character;
    struct List *next;
} NodeL;

NodeT *createNode(int x)
{
    NodeT *p;
    p=(NodeT*)malloc(sizeof(NodeT));
    p->data=x;
    p->left=NULL;
    p->right=NULL;
    return p;
}

NodeT *createBinaryTree()
{
    char* c=(char*)malloc(sizeof(char)*20);
    scanf("%s",c);
    NodeT *p=createNode(atoi(c));
    if (strcmp(c,"*")==0)
        return NULL;
    else
    {
        p->left=createBinaryTree();
        p->right=createBinaryTree();
    }
    return p;
}

NodeL *ListFromTree(NodeT *root)
{
    NodeL *p=(NodeL*)malloc(sizeof(NodeL));
    if(root == NULL)
        p->character="*";
    else
    {
        p->character=(char*)root->data;
        free(root);
        ListFromTree(root->left);
        ListFromTree(root->right);
    }
    return p;
}

int *printList(NodeL *first)
{
    if(first!=NULL)
    {
        printf("%s ",first->character);
        printList(first->next);
    }
    return 0;
}

NodeT *createTree(char *c)
{
    NodeT* p=(NodeT*)malloc(sizeof(NodeT));
    if(strcmp(c,"*")!=0)
    {
        p->data=atoi(c);
        p->left=NULL;
        p->right=NULL;
    }
    return p;
}

NodeT *GetTree(NodeL *first)
{
    NodeT *p=createTree(first->character);
    if(strcmp(first->character,"*")==0)
        return NULL;
    else
    {
        p->left=GetTree(first->next);
        p->right=GetTree(first->next);
    }
    return p;
}

void prettyPrint(NodeT *root,int lvl)
{
    int i;
    if(root!=NULL)
    {
        for(i=0; i<=lvl; i++)
            printf(" ");
        printf("%d ",root->data);
        prettyPrint(root->left,lvl+1);
        prettyPrint(root->right,lvl+1);
    }
}

int main()
{
    NodeT *root=createBinaryTree();
    NodeL *first=ListFromTree(root);
    printList(first);
    root=GetTree(first);
    prettyPrint(root,0);
    return 0;
}
