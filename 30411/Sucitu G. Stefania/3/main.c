#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct nod
{
    int data;
    struct nod *left;
    struct nod *right;
} nodet;

typedef struct queue
{
    int dat;
    struct queue *next;
    struct queue *previous;
} node;
node *head,*tail;

nodet*createnode(int data)
{

    nodet *p;
    p=(nodet*)malloc(sizeof(nodet));
    p->data=data;
    p->right=p->left=NULL;
    return p;
}

nodet* createbintree( )
{
    nodet* p;
    char* content=(char*)malloc(sizeof(char)*20);
    scanf("%s",content);
    if (strcmp(content,"*")==0)
        return NULL;
    else
    {
        p=createnode(atoi(content));
        p->left=createbintree();
        p->right=createbintree();
    }
    return p;
}

nodet* createbintree2( )
{
    nodet* p;
    int content=(int*)malloc(sizeof(int)*20);
    content=head->dat;
    head=head->next;
    if (content==8)
        return NULL;
    else
    {
        p=createnode(content);
        p->left=createbintree2();
        p->right=createbintree2();
    }
    return p;
}

void AL(int x)
{
    if (head==NULL)
    {
        head=(struct node*)malloc(sizeof(node));
        head->dat=x;
        head->previous=NULL;
        head->next=NULL;
        tail=head;
    }
    else
    {
        node *t=(node*)malloc(sizeof(node));
        t->dat=x;
        t->next=NULL;
        t->previous=tail;
        tail->next=t;
        tail=t;
    }
}

void addlist(nodet* root)
{
    if (root!=NULL)
    {
        AL(root->data);
        addlist(root->left);
        addlist(root->right);
    }
    else
    {
        AL(8);
    }
}

void printElement(nodet * node)
{
    printf ( "%d " ,(int) node->data );
}

void prettyPrint(nodet *root,int recLevel)
{
    if(root==NULL)
    {
        recLevel--;
        return;
    }
    recLevel++;
    prettyPrint(root->right,recLevel);
    int j=0;
    for(j=0; j<recLevel-1; j++)
    {
        printf("     ");
    }
    printElement(root);
    printf("\n");
    prettyPrint(root->left,recLevel);
    printf("\n");
}
void printlist()
{
    node* t=head;
    while (t!=NULL)
    {
        printf("%d ",t->dat);
        t=t->next;
    }  printf("\n");
}


int main()
{
    nodet* root=createbintree();
    prettyPrint(root,0);
    addlist(root);
    printlist();
    createbintree2();
    prettyPrint(root,0);
    return 0;
}
