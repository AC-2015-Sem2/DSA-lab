#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    char height;
    struct  node* left;
    struct node* right;

} TreeT;

TreeT *createNodeTree(int value)
{
    TreeT *p;

    p = (TreeT *)malloc(sizeof(TreeT));
    p->value = value;
    p->left = p->right = NULL;
    return(p);
}

void preorder(TreeT *root)
{
    if (root!=NULL)
    {
       printf("%d ",root->value);
        preorder(root->left);
        preorder(root->right);
    }
}

TreeT* createStaticTree()
{
    TreeT *root=createNodeTree(10);
    root->left=createNodeTree(12);
    root->right=createNodeTree(15);
    root->left->left=createNodeTree(14);
    root->left->right=createNodeTree(11);
    return root;
}

int height(TreeT *root)
{
    if(root==NULL)
        return 0;
    else
    {
        int hl=height(root->left);
        int hr=height(root->right);
        if(hl>hr)
            return hl+1;
        else
            return hr+1;
    }
}

TreeT *rotateRight(TreeT *x)
{
    TreeT *y;

    y=x->left;
    x->left=y->right;
    y->right=x;
    x->height=height(x);
    y->height=height(y);

    return(y);
}
TreeT *rotateLeft(TreeT *x)
{
    TreeT *y;

    y=x->right;
    x->right=y->left;
    y->left=x;
    x->height=height(x);
    y->height=height(y);

    return(y);
}

TreeT * RR(TreeT *T)
{
    T=rotateLeft(T);
    return(T);
}

TreeT * LL(TreeT *T)
{
    T=rotateRight(T);
    return(T);
}

TreeT * LR(TreeT *T)
{
    T->left=rotateLeft(T->left);
    T=rotateRight(T);
    return(T);
}

TreeT * RL(TreeT *T)
{
    T->right=rotateRight(T->right);
    T=rotateLeft(T);
    return(T);
}

int getBalance(struct node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

TreeT* Insert(TreeT *root, int k)
{
    if(root==NULL) return createNodeTree(k);

    if(k < root->value)
        root->left=Insert(root->left,k);
    else
        root->right=Insert(root->right,k);
    return getBalance(root);
}

int main()
{
        int x;
        TreeT * root = createStaticTree();
        preorder(root);
        printf("Enter x:");
        scanf("%d",&x);
        root=Insert(root,x);
        preorder(root);
        return 0;
}
