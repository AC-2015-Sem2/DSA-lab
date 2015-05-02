#include <stdio.h>
#include <stdlib.h>

typedef struct NodeT
{
    int data,height;
    struct NodeT *left,*right;
} NodeT;
FILE *f,*g;
NodeT *root;
NodeT* rotateLeft(NodeT *root);
NodeT* rotateRight(NodeT *root);
NodeT* balance(NodeT *root,int data);
NodeT* insertNode(NodeT *root,int data);
NodeT *leftRotate(struct NodeT *nod);

struct NodeT* rotateLeft(NodeT *root)
{

    NodeT *node;
    node=root->right;
    root->right=node->left;
    node->left=root;
    root->height=root->height-1;
    node->height=node->height+1;
    root=node;
    return node;
}
struct NodeT* rotateRight(NodeT *root)
{

    NodeT *node;
    node=root->left;
    root->left=node->right;
    node->right=root;
    root->height=root->height-1;
    node->height=node->height+1;
    root=node;
    return node;
}

struct NodeT* balance (NodeT *root,int data)
{
    if ((root->left==NULL) && (root->right==NULL)) return root;
    else if ((root->left==NULL) && (root->right!=NULL))
    {
        if (root->right->data>data) root->right=rotateRight(root->right);
        return(rotateLeft(root));
    }
    else if ((root->left>1) && (root->right==NULL))
    {
        if (root->left->data<data) root->left=rotateLeft(root->left);
        return(rotateRight(root));
    }
    else if (root->left->height==root->right->height || root->left->height==root->right->height+1 ) return root;
    else if (root->left->height<root->right->height+1)
    {
        if (root->right->data>data) root->right=rotateRight(root->right);
        return(rotateLeft(root));
    }
    else if (root->left->height>root->right->height+1)
    {
        if (root->left->data<data) root->left=rotateLeft(root->left);
        return(rotateRight(root));
    }
}
NodeT* createNode(int data)
{
    NodeT *p;
    p=malloc(sizeof(NodeT));
    p->data=data;
    p->left=NULL;
    p->height=1;
    p->right=NULL;
    return p;
}
struct NodeT* insertNode(struct NodeT *root,int data)
{
    if (root==NULL)
        return(createNode(data));
    else if (data<root->data)
    {

        root->height++;
        root->left=insertNode(root->left,data);
    }
    else
    {

        root->height++;
        root->right=insertNode(root->right,data);
    }
    root=balance(root,data);
    return root;
}
void prettyPrint(NodeT *root,int level)
{
    int i;
    if (root==NULL)
        return;
    else
    {
        prettyPrint(root->right,level+1);
        for (i=0; i<level; i++) fprintf(g,"      ");
        fprintf(g,"%d\n",root->data);


        prettyPrint(root->left,level+1);

    }
}

int main()
{
    f=fopen("input.dat","r");
    g=fopen("output.dat","w");
    int data;
    while (fscanf(f,"%d",&data)==1)
    {
        root=insertNode(root,data);
        if (data>2) root=balance(root,data);

    }
    prettyPrint(root,0);
    fclose(f);
    fclose(g);
    return 0;
}
