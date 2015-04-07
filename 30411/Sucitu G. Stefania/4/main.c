#include <stdio.h>
#include <stdlib.h>
#include<limits.h>
#include<string.h>

typedef struct node
{
    int data;
    int height;
    struct node *left, *right;
} nodet;

nodet* createNode(int data)
{
    nodet* p=(nodet*)malloc(sizeof(nodet));
    p->data=data;
    p->left=NULL;
    p->right=NULL;
    p->height=1;
    return p;
}

nodet *createBinTREE()
{
    nodet *p;
    char *content=(char*)malloc(sizeof(char));
    scanf("%s",content);
    if (strcmp(content,"*")==0)
        return NULL;
    else
    {
        p=createNode(atoi(content));
        p->left=createBinTREE();
        p->right=createBinTREE();
    }
    return p;
}

int height(nodet *root)
{
    if (root==NULL)
        return 0;
    return root->height;
}

int balaced(nodet *root)
{
    if (root==NULL)
        return 0;
    else
        return height(root->left)-height(root->right);
}

int max(int a,int b)
{
    if (a<b)
        return b;
    else
        return a;
}

nodet *SRR(nodet*p)
{
    nodet* s=p->left;
    p->left=s->right;
    s->right=p;
    s->height = max(height(p->left), height(p->right)) + 1;
    p->height= max(height(s->left),height(s->right))+1;
    return s;
}

nodet *SRL(nodet *p)
{
    nodet* s=p->right;
    p->right=s->left;
    s->left=p;
    s->height = max(height(p->left), height(p->right)) + 1;
    p->height = max(height(s->left), height(s->right)) + 1;
    return p;
}

nodet *DRR(nodet *p)
{
    p->left=SRL(p->left);
    p=SRR(p);
    return p;
}

nodet *DRL(nodet *p)
{
    p->right=SRR(p->right);
    p=SRL(p);
    return p;
}

nodet* insert( nodet *p,int value)
{
    int balance;
    if (p==NULL)
        return createNode(value);
        if (p->data>value)
        p->left=insert(p->left,value);
    else
        p->right=insert(p->right,value);
            p->height=max(height(p->left),height(p->right))+1;
            balance=balaced(p);
                    if (balance>1 && p->left->data>value)
                        return SRR(p);
                    if (balance<-1 && p->right->data<value)
                        return SRL(p);
                    if (balance>1 && p->left->data<value)
                        return DRR(p);
                    if (balance<-1 && p->right->data>value)
                        return DRL(p);
            else
            return p;
}

void *printElement(nodet *root)
{
    printf( "%d " ,root->data );
}

int isBSTutil( nodet* root,int min,int max)
{
    if (root==NULL)
        return 1;
    else if ((root->data>max) &&(root->data<min))
        return 0;
    else
    {
        return isBSTutil(root->left,min, root->data) && isBSTutil(root->right,root->data,max);
    }
}

int isBST(nodet* root)
{
    return isBSTutil(root, INT_MIN,INT_MAX);
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
}

int main()
{
    nodet *root=createNode(10);
    root=insert(root,4);
    root=insert(root,20);
    root=insert(root,40);
    root=insert(root,25);
    root=insert(root,1);
    prettyPrint(root,0);
    printf("\n %d",isBST(root));
    return 0;
}
