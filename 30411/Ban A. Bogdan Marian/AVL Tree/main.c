#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *right,*left;
} Tree;

Tree* createNode(int x);
void preorder(Tree *root);
int height(Tree *root);
Tree* createStaticTree();
Tree * rotateRight(Tree *x);
Tree * rotateLeft(Tree *x);
Tree * RR(Tree *T);
Tree * LL(Tree *T);
Tree * RL(Tree *T);
Tree * LR(Tree *T);
int DifferenceLevel(Tree *T);
Tree *insert(Tree *T,int x);

Tree* createNode(int x)
{
    Tree* n=(Tree*)malloc(sizeof(Tree));
    n->data=x;
    n->left=NULL;
    n->right=NULL;
    return n;
}

void preorder(Tree *root)
{
    if (root!=NULL)
    {
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

int height(Tree *root)
{
    if (root==NULL)
        return 0;
    else
    {
        int left,right;
        left=height(root->left);
        right=height(root->right);
        if (left>right)
            return left+1;
        else
            return right+1;
    }
}
Tree* createStaticTree()
{
    Tree *root=createNode(7);
    root->left=createNode(9);
    root->right=createNode(12);
    root->left->left=createNode(11);
    root->left->right=createNode(8);
    return root;
}

Tree * rotateRight(Tree *x)
{
    Tree *y;
    y=x->left;
    x->left=y->right;
    y->right=x;
    return(y);
}

Tree * rotateLeft(Tree *x)
{
    Tree *y;
    y=x->right;
    x->right=y->left;
    y->left=x;
    return(y);
}

Tree * RR(Tree *T)
{
    T=rotateLeft(T);
    return(T);
}
Tree * LL(Tree *T)
{
    T=rotateRight(T);
    return(T);
}
Tree * LR(Tree *T)
{
    T->left=rotateLeft(T->left);
    T=rotateRight(T);
    return(T);
}
Tree * RL(Tree *T)
{
    T->right=rotateRight(T->right);
    T=rotateLeft(T);
    return(T);
}

int DifferenceLevel(Tree *T)
{
    int lh,rh;
    if (T==NULL)
    {
        return 0;
    }

    if (T->left==NULL)
        lh=0;
    else
        lh=1+T->left->data;
    if (T->right==NULL)
        rh=0;
    else
        rh=1+T->right->data;
    return(lh-rh);
}

Tree *insert(Tree *T,int x)
{
    if (T==0)
    {
        createNode(x);
    }
    else if (x>T->right->data)
    {
        T->right=insert(T->right,x);
        if (DifferenceLevel(T)==-2)
        {
            if (x > T->right->data)
                T=RR(T);
            else
                T=RL(T);
        }
    }
        if(x<T->data)
    {
        T->left=insert(T->left,x);

        if (DifferenceLevel(T)==2)
        {
            if(x < T->left->data)
                T=LL(T);
            else
                T=LR(T);
        }
    }
    return(T);
}

    int main()
    {
        int x;
        Tree * root = createStaticTree();
        preorder(root);
        printf("Enter x:");
        scanf("%d",&x);
        root=insert(root,x);
        return 0;
    }
