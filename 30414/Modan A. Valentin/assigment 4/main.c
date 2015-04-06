#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include<math.h>
FILE *input, *output;

typedef struct nod
{
    int height;
    struct nod *left, *right;
    char data;
}NODET;

NODET* createNODE(int d)
{
    NODET *p;
    p=(NODET*)malloc(sizeof(NODET));
    p->data=d;
    p->left=NULL;
    p->right=NULL;
    return p;
}

NODET* createBinTree()
{
    NODET *p;
    char*data=(char*)malloc(sizeof(char)*100);
    fscanf(input,"%s",data);
    if(strcmp(data,"*")==0)
        return NULL;
    else
    {
        p=createNODE(atoi(data));
        p->left=createBinTree();
        p->right=createBinTree();
    }
    return p;
}

void prettyPrint(NODET *root,int recLevel)
{
    if(root==NULL)
    {
        recLevel--;
        return;
    }
    recLevel++;
    prettyPrint(root->right,recLevel);
    int i=0;
    for(i=0; i<recLevel-1; i++)
        fprintf(output,"  ");

    fprintf(output,"%d", root->data);
    fprintf(output,"\n");
    prettyPrint(root->left,recLevel);
}

int Search(NODET* root, int value)
{
    if(root==NULL)
        return 0;
    else
        if(root->data==value)
        return 1;
    else
        if(root->data<value)
        return Search(root->right,value);
    else
        return Search(root->left,value);
}

NODET* insert(NODET* root,int value)
{
    if(root==NULL)
        return createNODE(value);
    else
    {
        if(root->data<value)
            root->right=insert(root->right,value);
        else
            root->left=insert(root->left,value);
        return root;
    }
}

int isBSTUtil(NODET* root, int a,int b)
{
    if (root==NULL)
        return 1;
    else
        if(root->data>=a && root->data<=b)
            return(isBSTUtil(root->left,a,root->data) && isBSTUtil(root->right,root->data,b));
    else
        {
            return 0;
        }

}

int isBST(NODET* root)
{
    return isBSTUtil(root,INT_MIN,INT_MAX);
}
NODET* shiftright(NODET* root)
{
    NODET *aux;
    aux=root->left;
    root->left=aux->right;
    aux->right=root;
    return aux;

}
NODET* shiftleft(NODET* root)
{
    NODET *aux;
    aux=root->right;
    root->right=aux->left;
    aux->left=root;
    return aux;
    }
int compare_height(NODET *root)
{
    if(root==NULL)
        return 0;
    else
        return compare_height(root->left)>compare_height(root->right)?compare_height(root->left)+1:compare_height(root->right)+1;
}
NODET* switch_root(NODET *root)
{
    while(abs(compare_height(root->left)-compare_height(root->right))>1)
    {
        if(compare_height(root->left)>compare_height(root->right))
            root=shiftright(root);
        else
            root=shiftleft(root);

    }
    return root;
}
int main()
{
    NODET *root;
    input=fopen("input.dat","r");
    output=fopen("output.dat","w");
    root=createBinTree();
    fprintf(output,"%d \n",Search(root,1));
    insert(root,10);
    insert(root,11);
    insert(root,12);
    insert(root,13);
    insert(root,14);
    insert(root,15);
    root=switch_root(root);
    prettyPrint(root,0);
    fprintf(output,"\n");
    fprintf(output,"%d",compare_height(root));
    fprintf(output,"%d",isBST(root));
}
