#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    int data, height;
    struct node *left, *right;
}NodeT;

NodeT* createNode(int data)
{
    NodeT *x = (NodeT*)malloc(sizeof(NodeT));
    x->data  = data;
    x->left  = NULL;
    x->right = NULL;
    x->height = 1;
    return(x);
}

NodeT *createBinTree()
{
    NodeT*p;
    char *data=(char*) malloc(sizeof(char)*20);
    scanf("%s",data);
    if(strcmp(data,"*")==0)
    return NULL;
    else
    {
        p=(NodeT*)malloc(sizeof (NodeT));
        p->data=(atoi(data));
        p->left=createBinTree();
        p->right=createBinTree();
        return p;
    }
}

int findHeight(NodeT *root)
{
    if (root == NULL) return 0;
    else return root->height;
}

int max (int a, int b)
{
    return (a>b)?a:b;
}

NodeT *rightRot(NodeT *root)
{
    NodeT *n1 = root->left;
    NodeT *n2 = n1->right;
    n1->right = root;
    root->left = n2;
    root->height = max(findHeight(root->left), findHeight(root->right))+1;
    n1->height = max(findHeight(n1->left), findHeight(n1->right))+1;
    return n1;
}

NodeT *leftRot(NodeT *node)
{
    NodeT *root = node->right;
    NodeT *n1 = root->left;
    root->left = node;
    node->right = n1;
    node->height = max(findHeight(node->left), findHeight(node->right))+1;
    root->height = max(findHeight(root->left), findHeight(root->right))+1;
    return root;
}

int getBalance(NodeT *root)
{
    if (root == NULL) return 0;
    return (findHeight(root->left) - findHeight(root->right));
}

NodeT* insertNode(NodeT* node, int data)
{
    if (node == NULL) return(createNode(data));
    else if (data < node->data)
        node->left  = insertNode(node->left, data);
    else
        node->right = insertNode(node->right, data);
        node->height = max(findHeight(node->left), findHeight(node->right))+1;
    int bal=getBalance(node);
    if (bal>1 && data < node->left->data)  return rightRot(node);
    if (bal<-1 && data>node->right->data)  return leftRot(node);
    if (bal>1 && data>node->left->data)
        {
        node->left =leftRot(node->left);
        return rightRot(node);
        }
    if (bal<-1 && data<node->right->data)
        {
        node->right =rightRot(node->right);
        return leftRot(node);
        }
    return node;
}

void prettyPrint(NodeT *root,int niv)
{
    if(root==NULL)
    {
        niv--;
        return;
    }
    niv;
    prettyPrint(root->right,niv);
    int j=0;
    for(j=0; j<niv-1; j)
    {
        printf("          ");
    }
    printf("%d \n", root->data);
    prettyPrint(root->left,niv);
}

int main()
{
    NodeT *root = NULL;
    root = insertNode(root,1);
    root = insertNode(root,2);
    root = insertNode(root,3);
    root = insertNode(root,4);
    root = insertNode(root,5);
    root = insertNode(root,6);
    root = insertNode(root,7);
    root = insertNode(root,8);
    root = insertNode(root,9);
    root = insertNode(root,10);
    prettyPrint(root, 0);
    return 0;
}
