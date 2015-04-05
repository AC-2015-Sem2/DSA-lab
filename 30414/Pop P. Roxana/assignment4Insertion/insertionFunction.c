#include "tree.h"

nodeT* insertNew(nodeT*root, int value)
{
    ///make the actual insertion
    if (root==NULL) return createNode(value);
    if (value<root->data)
        root->left=insertNew(root->left,value);
    else
        if (value>root->data)
        root->right=insertNew(root->right,value);
    ///update height
    root->height=max(height(root->left),height(root->right))+1;
    ///calculating balance factor
    int bF=balanceFactor(root);
    ///make the rotation, if necessary
    if (bF==-2)
    {
        if (root->right->data<value) singleLeftRotation(&root);
        if (root->right->data>value) rightLeftRotation(&root);
    }
    else
    {
        if (bF==2)
        {
            if (root->left->data>value) singleRightRotation(&root);
            if (root->left->data<value) leftRightRotation(&root);
        }
    }
    return root;
}
