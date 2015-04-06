#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
typedef struct node
{
    struct node* left;
    struct node* right;
    int data,length;
} NodeT;
NodeT* createNode(int data)
{
    NodeT* root=(NodeT*)malloc(sizeof(NodeT));
    root->data=data;
    root->left=NULL;
    root->right=NULL;
    root->length=1;
    return root;
}
int length(NodeT *root)
{
    if (root==NULL)
        return 0;
    return root->length;
}
int max(int a,int b)
{
    if (a<b)
        return b;
    else
        return a;
}
int balanced(NodeT *root)
{
    if (root==NULL)
        return 0;
    else
        return length(root->left)-length(root->right);
}
NodeT* RR(NodeT *l)
{
    NodeT *node = l->left;
    NodeT *rr = node->right;
    node->right = l;
    l->left = rr;
    l->length = max(length(l->left), length(l->right)) + 1;
    node->length = max(length(node->left), length(node->right)) + 1;
    return node;

}
NodeT* RL(NodeT *node)
{
    NodeT *r = node->right;
    NodeT *rl = r->left;
    r->left = node;
    node->right = rl;
    node->length = max(length(node->left), length(node->right)) + 1;
    r->length = max(length(r->left), length(r->right)) + 1;
    return r;
}
NodeT* insert(NodeT* root, int code)
{
    int OK;
    if (root==NULL)
        return createNode(code);
    if (code<root->data)
        root->left=insert(root->left,code);
    else
        root->right=insert(root->right,code);

    root->length=max(length(root->left),length(root->right)) +1;
    OK = balanced(root);

    if (OK>1)
        if(code < root->left->data)
           return RR(root);
    if (OK<-1)
        if(code > root->right->data)
           return RL(root);
    if (OK>1)
        if(code > root->left->data)
    {
        root->left=RL(root->left);
           return RR(root);
    }
    if (OK<-1)
        if(code < root->right->data)
    {
        root->right=RR(root->right);
        return RL(root);
    }
    return root;
}
int isBSTUTIL(NodeT *nodea,int min,int max)
{
    if(nodea==NULL)
        return 1;
    if(nodea->data<min || nodea->data>max)
        return 0;
    else
        return isBSTUTIL(nodea->right,nodea->data,max) && isBSTUTIL(nodea->left,min,nodea->data);
}
int isBST(NodeT *root)
{
    return isBSTUTIL(root,INT_MIN,INT_MAX);

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
    NodeT *root=createNode(5);
    root=insert(root,6);
    root=insert(root,8);
    root=insert(root,9);
    root=insert(root,10);
    root=insert(root,7);
    root=insert(root,1);
    prettyPrint(root,0);
    printf("\n%d",isBST(root));
    return 0;
}
