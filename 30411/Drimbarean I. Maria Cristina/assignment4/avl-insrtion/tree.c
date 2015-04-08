#include "tree.h"
//print
  void printElement(NodeT * node)
{
    printf ( "%d " ,(int) node->data );
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
NodeT *createStaticTree()
  {
    NodeT *root=createNode(13);
    root->left=createNode(7);
    root->right=createNode(21);
    root->left->left=createNode(1);
    root->left->right=createNode(9);
    root->right->right=createNode(23);
    return root;
  }
NodeT* createNode(int x)
{
      NodeT *p;
      p=(NodeT*)malloc(sizeof(NodeT));
      p->data=x;
      p->left=p->right=NULL;
      return p;
}


//get maximum of two integers
int max(int a,int b)
{
    if (a>b) return a;
    else return b;//return (a>b)? a:b;
}
//function to get height of the tree
int height(NodeT *N)
{
    if (N==NULL)
        return 0;
    else return N->height;
}
//allocates new node with the given data
NodeT *newNode(int data)
{
    NodeT *node=(NodeT*)malloc(sizeof(NodeT));
    node->data=data;
    node->left=NULL;
    node->right=NULL;
    node->height=1;//added as a leaf
    return node;
}
//rotate right the subtree rooted with y
NodeT *rightRotate(NodeT *y)
{
    NodeT *x=y->left;
    NodeT *T2=x->right;
    //rotation
    x->right=y;
    y->left=T2;
    //updateheight
    y->height=max(height(y->left),height(y->right))+1;
    x->height=max(height(x->left),height(x->right))+1;
    //return new root
    return x;
}
//rotate left the subtree rooted with x
NodeT *leftRotate(NodeT *x)
{
    NodeT *y=x->right;
    NodeT *T2=y->left;
    //roatation
    y->left=x;
    x->right=T2;
    //update heights
    y->height=max(height(y->left),height(y->right))+1;
    x->height=max(height(x->left),height(x->right))+1;
    //return new root
    return y;
}
//get balance factor of node N
int getBalance(NodeT *N)
{
    if (N==NULL) return 0;
    return height(N->left)-height(N->right);
}
