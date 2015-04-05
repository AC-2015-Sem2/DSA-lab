#include "tree.h"

nodeT* deleteNode(nodeT*root, int value)
{
    if (root==NULL) return root;
    if (value<root->data)
        root->left=deleteNode(root->left,value);
    else
    {
        if (value>root->data)
        root->right=deleteNode(root->right,value);
    else if (value==root->data)///the node to be deleted was identified
    {
        ///the node is a leaf
        if ((root->left==NULL)&&(root->right==NULL))
        {
            free(root);///deallocate the memory area
            root=NULL;///set the root pointer to NULL
        }
        else
        {
        ///the node has one child only
        if ((root->left==NULL)||(root->right==NULL))
        {
            nodeT* aux=root->left?root->left:root->right;///aux is a pointer to the non-null child
            *root=*aux;///the contents of the child are written over
            free(aux);///the memory area aux points to is deallocated as root holds the same info
        }
        ///the node has two children
        else
        {
        ///replace it with the inorder successor
        int data=minimumTree(root->right);
        root->data=data;
        ///delete the inorder successor
        root->right=deleteNode(root->right,data);
        }
        }
    }
    }
    ///if the tree had only one node, return
    if (root==NULL) return root;
    ///update height
    root->height=max(height(root->left),height(root->right))+1;
    ///calculating balance factor
    int bF=balanceFactor(root);
    ///make the rotation, if necessary
    if (bF==-2)///more on the right
    {
        int childBF=balanceFactor(root->right);
        if (childBF==-1) singleLeftRotation(&root);///right right
        if (childBF==1) rightLeftRotation(&root);///right left
    }
    else
    {
        if (bF==2)///more on the left
        {
            int childBF=balanceFactor(root->left);
            if (childBF==1) singleRightRotation(&root);///left left
            if (childBF==-1) leftRightRotation(&root);///left right
        }
    }
    return root;
}
