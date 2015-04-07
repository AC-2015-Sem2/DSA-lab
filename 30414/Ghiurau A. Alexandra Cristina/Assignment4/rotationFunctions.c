#include "functions.h"

void rightRotation(NodeT **root2)
{
    NodeT *root1 = (*root2)->left;
    (*root2)->left = root1->right;
    root1->right = *root2;
    (*root2)->height = max( height((*root2)->left), height((*root2)->right)) + 1;
    root1->height = max( height(root1->left), (*root2)->height) +1;
    (*root2) = root1;
}

void leftRotation(NodeT **root2)
{
    NodeT *root1 = (*root2)->right;
    (*root2)->right = root1->left;
    root1->left = (*root2);
    (*root2)->height = max( height((*root2)->left), height((*root2)->right)) + 1;
    root1->height = max( (*root2)->height, height(root1->right) )+1;
    (*root2) = root1;
}

void rightLeftRotation(NodeT **root3)
{
    rightRotation(&((*root3)->right));
    leftRotation(root3);
}

void leftRightRotation(NodeT **root3)
{
    leftRotation(&((*root3)->left));
    rightRotation(root3);
}
