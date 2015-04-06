#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node
{
    struct node *left, *right;
    int data;
    int height;
} nodeT;

nodeT* createNode(int data)
{
    nodeT* nod=(nodeT*)malloc(sizeof(nodeT));
    nod->data=data;
    nod->left=NULL;
    nod->right=NULL;
    nod->height=1;
    return nod;
}
int max(nodeT* a,nodeT* b )
{
    if ((a==NULL) && (b==NULL)) return 0;
    else if (a==NULL) return b->height;
    else if (b==NULL) return a->height;
    else
    {
        if ((a->height)>(b->height)) return(a->height);
        else return (b->height);
    }
}

nodeT* createBinTree(FILE *f)
{
    nodeT *p;
    char *dat=( char* ) malloc(sizeof(char)*100);
    fscanf(f,"%s",dat);
    if (strcmp(dat,"*")==0)
    {
        return NULL;
    }
    else
    {
        p=createNode(atoi(dat));
        p->left=createBinTree(f);
        p->right=createBinTree(f);
    }
    p->height=max(p->left,p->right)+1;
    return p;
}

void prettyPrint(nodeT *root,int recLevel)
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
    printf("%d",root->data);
    printf("\n");
    prettyPrint(root->left,recLevel);
}
/********ROTATION FUNCTIONS******/

nodeT* singleRotRight(nodeT *k2)
{
    nodeT *k1;
    k1=k2->left;
    k2->left=k1->right;
    k1->right=k2;
    k2->height=max(k2->left,k2->right)+1;
    k1->height=max(k1->left,k1->right)+1;
    return k1;
}
nodeT* singleRotLeft(nodeT *k2)
{
    nodeT *k1;
    k1=k2->right;
    k2->right=k1->left;
    k1->left=k2;
    k2->height=max(k2->left,k2->right)+1;
    k1->height=max(k1->right,k2)+1;
    return k1;

}

nodeT* doubleRotRightLeft(nodeT* k3)
{
    k3->right=singleRotRight(k3->right);
    return singleRotLeft(k3);
}

nodeT* doubleRotLeftRight(nodeT* k3)
{
    k3->left=singleRotLeft(k3->left);
    return singleRotRight(k3);
}


int height(nodeT *p)
{
    if (p == NULL)
        return 0;
    return p->height;
}

int balanceFactor(nodeT* p)
{
    if (p==NULL)
        return 0;
    return ((height(p->left))-(height(p->right)));
}
nodeT* inorderReplacementNode(nodeT* p)
{
    while (p->left!=NULL)
        p=p->left;

    return p;
}

nodeT* deleteNode(nodeT* node, int value)
{
    if (node == NULL)
        return node;
    if ( value < node->data )
        node->left = deleteNode(node->left, value);
    else if( value > node->data )
        node->right = deleteNode(node->right, value);
    else
    {
        if (node->left==NULL && node->right==NULL)
        {
            free(node);
            node=NULL;
        }
        else if (node->left==NULL)
        {
            nodeT* aux=node->right;
            *node=*aux;
            free(aux);
        }
        else if (node->right==NULL)
        {
            nodeT* aux=node->left;
            *node=*aux;
            free(aux);
        }
        else
        {
            nodeT* aux =inorderReplacementNode(node->right);
            node->data = aux->data;
            node->right = deleteNode(node->right, aux->data);
        }
    }

    if (node == NULL)
        return node;
    node->height = max(node->left, node->right) + 1;
    int balance = balanceFactor(node);
    int balanceLeft=balanceFactor(node->left);
    int balanceRight=balanceFactor(node->right);
    if (balance > 1)
    {
        if (balanceLeft >= 0)
            return singleRotRight(node);
        else
            return doubleRotLeftRight(node);
    }
    if (balance < -1)
    {
        if ( balanceRight <= 0)
            return singleRotLeft(node);
        else
            return doubleRotRightLeft(node);
    }

    return node;
}
