#include "tree.h"

/********** FUNCTION THAT DETERMINES THE MAXIMUM OF TWO NUMBERS*****************/
///useful in determining the height of a node
int max(int a, int b)
{
    if (a>b) return a;
    else return b;
}

/*********** FUNCTION RETURNING THE HEIGHT OF A NODE ***************************/
int height(nodeT*p)
{
    if (p==NULL) return 0;
    return p->height;
}

/*********** FUNCTION THAT CREATES A NODE IN A TREE ***************************/
nodeT * createNode(int data)
{
    nodeT * p;
    p=(nodeT*)malloc(sizeof(nodeT));
    p->data=data;
    p->left=NULL;
    p->right=NULL;
    p->height=1;
    return p;
}

/*********** FUNCTION THAT CREATES A BINARY TREE ******************************/
nodeT * createBinTree()
{
 nodeT* p;
    char*data=(char*)malloc(sizeof(char)*100);
    if ( (fscanf(f,"%s",data)==-1)||(strcmp(data,"*")==0))
    {
        return NULL;
    }
    else
    {
        p=createNode(atoi(data));
        p->left=createBinTree();
        p->right=createBinTree();
        p->height=max(height(p->left),height(p->right))+1;
    }
    return p;
}
/************ FUNCTION THAT CALCULATES THE BALANCE FACTOR OF A NODE ***********/
int balanceFactor(nodeT * p)
{
    if (p==NULL) return 0;
    return height(p->left)-height(p->right);
}
/************ PRETTT PRINT  ***************************************************/
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
        fprintf(g,"     ");
    }
    fprintf(g,"%d",root->data);
    fprintf(g,"\n");

    prettyPrint(root->left,recLevel);
}

