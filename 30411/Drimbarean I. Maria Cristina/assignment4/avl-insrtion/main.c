#include "tree.h"

NodeT *insert(NodeT *root,int data)
{
    //normal BST rotation
    if (root==NULL)
        return (newNode(data));
    if (data < root->data)
        root->left=insert(root->left,data);
    else root->right=insert(root->right,data);
    //update height of ancestor node
    root->height=max(height(root->left),height(root->right))+1;
    //get balanced
    int balance=getBalance(root);
    //if it become unbalanced we assert the folowing 4 cases
    //left left case
    if (balance>1 && data<root->left->data)
        return rightRotate(root);
    //right right case
    if (balance<-1 && data>root->right->data)
        return leftRotate(root);
    //left right case
    if (balance>1 && data> root->left->data)
    {
        root->left=leftRotate(root->left);
        return rightRotate(root);
    }
    //right left case
    if (balance< (-1) && data<root->right->data)
    {
        root->right=rightRotate(root->right);
        return leftRotate(root);
    }
    //return the unchanged root pointer
    return root;
}
int main()
{
    NodeT *root;
    root=createStaticTree();
    prettyPrint(root,0);
    root=insert(root,18);
    root=insert(root,18);
    root=insert(root,2);
    prettyPrint(root,0);
    return 0;
}
