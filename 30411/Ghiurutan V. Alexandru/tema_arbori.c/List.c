#include "List.h"

NodeT *createBinTree()
{
    NodeT *p;
    char *content=(char *)malloc(sizeof(char)*MAX_CONTENT);
    scanf("%s",content);
    if(strcmp(content,"*")==0)
    {
        return NULL;
    }
    else
    {
        void * cont=getIntegerContent(content);
        p=(NodeT *)malloc(sizeof(NodeT));
        if(p==NULL)
        {
            fatalError();
        }
        p->data=cont;
        p->left=createBinTree();
        p->right=createBinTree();
    }
    return p;
}

void addLast(void *key,NodeL *headRef,NodeL *tailRef)
{
    if(headRef==NULL)
    {
        headRef=(NodeL *)malloc(sizeof(NodeL));
        headRef->code=key;
        headRef->next=NULL;
        headRef->previous=NULL;
        tailRef=headRef;
    }
    else
    {
        NodeL *q=(NodeL *)malloc(sizeof(NodeL));
        q->code=key;
        q->next=NULL;
        q->previous=tailRef;
        tailRef->next=q;
        tailRef=q;
    }
}

void preorder(NodeT *root,NodeL *headRef,NodeL *tailRef)
{
    if(root!=NULL)
    {
        addLast(root->data,headRef,tailRef);
        preorder(root->left,headRef,tailRef);
        preorder(root->right,headRef,tailRef);
    }
    else
    {
        addLast((void*)'*',headRef,tailRef);
    }
}

NodeL *getListFromTree(NodeT *root)
{
    NodeL *head=NULL;
    NodeL *tail=NULL;
    preorder(root,head,tail);
    return head;

}

void *getIntegerContent(char *content)
{
    return (void *)atoi(content);
}

void fatalError()
{
    perror("Not enough memory!\n");
    exit(1);
}

void traverseList(NodeL *headRef)
{
    if(headRef!=NULL)
    {
        printf("The content of the list is:\n");
        NodeL *q;
        for(q=headRef; q!=NULL; q=q->next)
        {
            printElement(q->code);
        }
        printf("\n");
    }

}
void printSelectedElement(void *content)
{
    if(strcmp((char *)content,"*")==0)
    {
        printf("* ");
    }
    else
    {
        printf("%d ",(int )content);
    }
}

NodeT *getTreeFromList(NodeL *headRef)
{
    NodeT *p;
    NodeL *q=headRef;
    char *content=(char *)malloc(sizeof(char)*MAX_CONTENT);
    strcpy(content,(char *)q->code);
    q=q->next;
    if(strcmp(content,"*")==0)
    {
        return NULL;

    }
    else
    {
        p=(NodeT *)malloc(sizeof(NodeT));
        if(p==NULL)
        {
            fatalError();
        }
        p->data=getIntegerContent(content);
        p->left=getTreeFromList(headRef);
        p->right=getTreeFromList(headRef);
    }
    return p;
}

void prettyPrint(NodeT *root,int recLevel)
{
    if(root==NULL)
    {
        recLevel--;
        return;
    }
    recLevel++;
    prettyPrint(root->right,recLevel);
    int j;
    for(j=0; j<recLevel-1; j++)
    {
        printf("     ");
    }
    printElement(root);
    printf("\n");
    prettyPrint(root->left,recLevel);
}

void printElement(NodeT *root)
{
    printf("%d ",(int)root->data);
}
