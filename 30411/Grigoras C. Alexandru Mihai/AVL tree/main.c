#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    struct node* left;
    struct node* right;
    int data,height;
} NodeT;
NodeT* createNode(int data)
{
    NodeT* root=(NodeT*)malloc(sizeof(NodeT));
    root->data=data;
    root->left=NULL;
    root->right=NULL;
    root->height=1;
    return root;
}
int height(NodeT *root)
{
    if (root==NULL)
        return 0;
    return root->height;
}
int max(int a,int b)
{
    if (a<b)
        return b;
    else
        return a;
}
int balaced(NodeT *root)
{
    if (root==NULL)
        return 0;
    else
        return height(root->left)-height(root->right);
}
NodeT* rotateRight(NodeT *y)
{
    NodeT *x = y->left;
    NodeT *T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;

}
NodeT* rotateLeft(NodeT *x)
{
    NodeT *y = x->right;
    NodeT *T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
}

NodeT* insert(NodeT* root, int code)
{
    int balance;
    if (root==NULL)
        return createNode(code);
    if (code<root->data)
        root->left=insert(root->left,code);
    else
        root->right=insert(root->right,code);
    root->height=max(height(root->left),height(root->right)) +1;
    balance = balaced(root);
    if (balance>1 && code < root->left->data)
        return rotateRight(root);
    if (balance<-1 && code > root->right->data)
        return rotateLeft(root);
    if (balance>1 && code > root->left->data)
    {
        root->left=rotateLeft(root->left);
        return rotateRight(root);
    }
    if (balance<-1 && code < root->right->data)
    {
        root->right=rotateRight(root->right);
        return rotateLeft(root);
    }
    return root;
}
void printElement(NodeT*  root)
{
    printf("%d",root->data);
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
int main()
{

    NodeT *root=createNode(10);
    root=insert(root,20);
    root=insert(root,30);
    root=insert(root,40);
    root=insert(root,50);
    root=insert(root,25);
    root=insert(root,1);
    prettyPrint(root,0);
    return 0;
}
