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

nodeT* insertNew(nodeT*root, int value)
{
    ///make the actual insertion
    if (root==NULL) return createNode(value);
    if (value<root->data)
        root->left=insertNew(root->left,value);
    else
        if (value>root->data)
        root->right=insertNew(root->right,value);
    ///update height
    root->height=max(height(root->left),height(root->right))+1;
    ///calculating balance factor
    int bF=balanceFactor(root);
    ///make the rotation, if necessary
    if (bF==-2)
    {
        if (root->right->data<value) singleLeftRotation(&root);
        if (root->right->data>value) rightLeftRotation(&root);
    }
    else
    {
        if (bF==2)
        {
            if (root->left->data>value) singleRightRotation(&root);
            if (root->left->data<value) leftRightRotation(&root);
        }
    }
    return root;
}
/************ FUNCTION THAT CREATES A PERFECTLY BALANCED BST *******************/
nodeT * createBalancedBST(FILE *f)
{
    nodeT* root=NULL;
    int data;
    while (fscanf(f,"%d",&data)!=-1)
    {
        root=insertNew(root,data);
    }
    return root;
}
/************ FUNCTION THAT FINDS THE MININMUM VALUE IN A TREE ****************/
int minimumTree(nodeT * root)
{
    if (root->left==NULL) return root->data;///it got to the leftmost node in the tree
    return minimumTree(root->left);///otherwise, it keeps going left
}
