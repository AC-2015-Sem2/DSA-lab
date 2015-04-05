#include <stdio.h>
#include <stdlib.h>

/*Write the code for the insertion of an element in a binary search tree such that it
always keeps the property height(Lsub) = height(Rsub) +-1*/

typedef struct node{
  struct node*left;
  struct node*right;
  int data;
  int height;
} nodeT;

int max(int a, int b);

int height(nodeT*N){
  if (N==NULL)
    return 0;
  return N->height;
}

int max(int a, int b){
    return (a>b)? a:b;
}

nodeT* createNode(int d){
    nodeT* Newnode;
    Newnode=(nodeT*)malloc(sizeof(nodeT));
    Newnode->right=NULL;
    Newnode->left=NULL;
    Newnode->data=d;
    Newnode->height=1; //new node is initially added at leaf
    return Newnode;

}
//root y
nodeT *rightRotate(nodeT*y){
    nodeT *x=y->left;
    nodeT *T2=x->right;

//perform rotation
   x->right=y;
   y->left=T2;

//update heights
   y->height=max(height(y->left), height(y->right))+1;
   x->height=max(height(x->left), height(x->right))+1;

//return new root
    return x;
}

//root x
nodeT *leftRotate(nodeT*x){
  nodeT *y=x->right;
  nodeT *T2=y->left;

//perform rotation
   y->left=x;
   x->right=T2;

//Update heights
x->height=max(height(x->left), height(x->right))+1;
y->height=max(height(y->left), height(y->right))+1;

//Return new root
return y;
}

//Get balance factor of node N
int getBalance(nodeT *N){
    if (N==NULL)
        return 0;
    return height(N->left)-height(N->right);
}

nodeT* insert(nodeT *node, int value){

    if (node==NULL)
        return (createNode(value));
    else if(node->data<value)
        node->right=insert(node->right, value);
    else
        node->left=insert(node->left, value);
    return node;

    node->height=max(height(node->left), height(node->right))+1;

    int balance= getBalance(node);

//If this node becomes unbalanced, then are 4 cases:

// Left Left Case
if (balance>1 && value<node->left->data)
    return rightRotate(node);

//Right Right Case
if (balance<-1 && value> node->right->data)
    return leftRotate(node);

//Left Right Case
if (balance<-1 && value>node->left->data){
    node->left=leftRotate(node->left);
    return rightRotate(node);
}
//Right Left Case
if (balance<-1 && value<node->right->data){
    node->right=rightRotate(node->right);
    return leftRotate(node);
}

/*return the (unchanged) node pointer*/
return node;
}


void preorder(nodeT* root){
 if (root==NULL){
    printf("%d", root->data);
    preorder(root->left);
    preorder(root->right);
   }
 }


int main()
{

    nodeT *root=NULL;
    root=insert(root, 10);
    root=insert(root, 20);
    root=insert(root, 30);
    root=insert(root, 40);
    root=insert(root, 50);
    root=insert(root, 25);
    printf("Preorder traversal of the constructed AVL is:\n");
    preorder(root);
    return 0;
}


