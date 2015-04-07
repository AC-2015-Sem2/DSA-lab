#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

NodeT* createNode(int value)
{
    NodeT* p=( NodeT *) malloc( sizeof( NodeT* ) );
    p->value=value;
    p->left=p->right=NULL;
    return p;
}

NodeT *  createBinTree(FILE* in)  // Read from input.txt - Ordered as in the text file - '*'-s needed
{
    NodeT *p;
    char *content = (char*)malloc(sizeof(char)*5);

    fscanf(in, "%s " ,content );
    if ( strcmp(content,"*")==0 )
        return NULL;
    else
    {
        int cont;
        sscanf(content,"%d ",&cont);
        p = ( NodeT *) malloc( sizeof( NodeT *) ) ;
        p->value = cont;
        p->left = createBinTree(in) ;
        p->right = createBinTree(in) ;
    }
    return p;
}
NodeT *  createAVL_BST(FILE* in)  // Read from input.txt - NO '*'-s required - ORDER does NOT matter
{

    NodeT **p = ( NodeT **) malloc( sizeof( NodeT** ) );

    *p = ( NodeT *) malloc( sizeof( NodeT* ) );

    (*p)->left=(*p)->right=NULL; // initializing node

    (*p)->value=INT_MIN;
    int content;

    while (fscanf(in, "%d " ,&content )==1)
    {

        insert_balanced(p,content);
    }
    return *p;
}

NodeT* insert (NodeT* root, int value)
{

    if (root == NULL)
    {

        return createNode(value);
    }

    else if ((root->value)==INT_MIN)
    {

        root->value=value;
    }
         //
    else if (value < root->value )
    {

        root->left=insert(root->left,value);
    }
    else if (value > root->value )
    {

        root->right=insert(root->right,value);
    }

    return root;
}

NodeT* insert_balanced (NodeT** root, int value)
{

    insert ((*root), value);  // simple inserting


    printf("\nThe new tree (possibly unbalanced, but BST):\n\n");

    prettyPrint((*root),0);  // Print the new tree

    if (((*root)->right==NULL)&&((*root)->left==NULL))
        return (*root);
    NodeT *n=search((*root), value);
    // n is the inserted node
    NodeT *p=parent((*root),n->value);
    // p is the parent of n (n's height might be incremented - its parents might also become unbalanced)

    // I go one level higher, because the newly introduced node is surely balanced

    // unless tree is small -> reached top:

    if (n!=NULL) n=parent((*root),n->value);
    if (p!=NULL) p=parent((*root),p->value);

    while (p!=NULL)
    {
        if (balanceFactor(p)==2)
        {
            if ((n==(p->left))&&(balanceFactor(n)==-1)) // LR case
                rotate_left(&n, root);  // Reducing to LL case
            rotate_right(&p, root);  // Balancing tree
        }
        else if (balanceFactor(p)==-2)
        {
            if ((n==(p->right))&&(balanceFactor(n)==1))  // RL case
                rotate_right(&n, root);  // reducing to RR case
            rotate_left(&p, root);  // Balancing tree
        }

        // Going up with one level:
        n=p;
        p=parent((*root),n->value);
 //       printf("\nTree after rotation:\n\n");
//        prettyPrint((*root),0);
    }
    return (*root);
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

    printf("%d",root->value);

    //! print  a new line
    printf("\n");

    prettyPrint(root->left,recLevel); //! keep going left in the tree
}

void rotate_left(NodeT **p, NodeT **root)
{
    NodeT *PP=parent((*root), (*p)->value);  // Parent of p // We do not know if p is on the left or right child
    if (PP==NULL)
    {
        PP=(*p)->right;
        (*p)->right=PP->left;
        PP->left=(*p);
        (*root)=PP;
        return;
    }
    if ((PP->left)==(*p))  // LR case
    {
        PP->left=(*p)->right;
        NodeT* aux=( NodeT *) malloc( sizeof( NodeT* ) );
        aux=PP->left->left;
        PP->left->left=(*p);
        (*p)->right=aux;
    }
    else  // RR case
    {
        PP->right=(*p)->right;
        NodeT* aux=( NodeT *) malloc( sizeof( NodeT* ) );
        aux=PP->right->left;
        PP->right->left=(*p);
        (*p)->right=aux;
    }
}

void rotate_right(NodeT **p, NodeT **root)
{
    NodeT *PP=parent((*root), (*p)->value);  // Parent of p // We do not know if p is on the left or right child
    if (PP==NULL) // in this case we need to change the root!
    {
        PP=(*p)->left;
        (*p)->left=PP->right;
        PP->right=(*p);
        (*root)=PP;
        return;
    }
    if ((PP->left)==(*p))  // LL case
    {
        PP->left=(*p)->left;
        NodeT* aux=( NodeT *) malloc( sizeof( NodeT* ) );
        aux=PP->left->right;
        PP->left->right=(*p);
        (*p)->left=aux;
    }
    else  //RL case
    {
        PP->right=(*p)->left;
        NodeT* aux=( NodeT *) malloc( sizeof( NodeT* ) );
        aux=PP->right->right;
        PP->right->right=(*p);
        (*p)->left=aux;
    }
}

int balanceFactor (NodeT* p)
{
    if (p==NULL)
        return 0;
    else
        return height(p->left) - height(p->right);
}

NodeT* parent(NodeT* root, int value)  // I discussed many cases, but otherwise it gave me errors/warnings
{
    if (root==NULL)
        return NULL;
    else if ((root->left==NULL)&&(root->right!=NULL))
    {
        if (root->right->value==value)
            return(root);
        else
            return parent(root->right,value);
    }
    else if ((root->left!=NULL)&&(root->right==NULL))
    {
        if (root->left->value==value)
            return (root);
        else
            return parent(root->left,value);
    }
    else if ((root->left==NULL)&&(root->right==NULL))
    {
        return NULL;
    }
    else if ((root->left->value == value)||(root->right->value == value))
        return(root);
    else if (root->value < value)
        return parent (root->right, value);
    else
        return parent(root->left, value);
}

int height (NodeT* p)
{
    if (p==NULL)
        return 0;
    else
        return (max(height(p->left),height(p->right))+1);
}

int max(int a, int b)
{
    if (a<b)
        return b;
    else return a;
}

NodeT* search(NodeT *root, int value)
{
    if (root==NULL) return NULL;
    else if (root->value == value)
        return(root);
    else if (root->value < value)
        return search (root->right, value);
    else
        return search(root->left, value);
}

int isBSTUtil(NodeT* root, int min, int max)
{
    if (root==NULL)
        return 1;
    else if ((root->value >max) || (root->value <min))
        return 0;
    else
        return isBSTUtil(root->left,min,root->value) && isBSTUtil(root->right, root->value, max);
}

int isBST(NodeT* root)
{
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

int sameTree(NodeT* a, NodeT* b)
{
    if ((a==NULL)&&(b==NULL))
        return 1;
    else if (a->value!=b->value)
        return 0;
    else if (a->value==b->value)
        return sameTree(a->left,b->left) && sameTree(a->right,b->right);
    return 0;
}
