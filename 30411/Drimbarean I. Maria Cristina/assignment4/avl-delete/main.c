#include "tree.h"
//in a non-empty bynary tree return minimum value
NodeT *minValueNode(NodeT *root)
{
    NodeT *current=root;
    //loop down to find leftmost leaf
    while (current->left!=NULL)
        current=current->left;
    return current;
}
NodeT* deleteNode(NodeT *root, int data)
{
    //standard BST delete
    if (root==NULL)
        return root;
    if (data<root->data)
        root->left=deleteNode(root->left,data);
    else if (data>root->data)
          root->right=deleteNode(root->right,data);
    else
    {
        //node with only one child or no child
        if ((root->left==NULL) || (root->right==NULL))
        {
            NodeT *temp=root->left ? root->left : root->right;
            //no child case
            if (temp==NULL)
            {
                temp=root;
                root=NULL;
            }
            else //one child case
                *root=*temp;//copy the content of non-empty child
            free(temp);
        }
        else
        {
            //node with 2 children :get inorder succesor (smallest in the right subtree)
            NodeT *temp=minValueNode(root->right);
            //copy norder succesor's data to this node
            root->data=temp->data;
            //delete the inorder succesor
            root->right=deleteNode(root->right,temp->data);
        }
    }
    //if the tree had only one node to return
    if (root==NULL)
        return root;
    //update height of the current node
    root->height=max(height(root->left),height(root->right))+1;
    //check if the node has become unbalanced
    int balance=getBalance(root);
    //if node unbalanced assert the 4 cases
    //left left case
    if (balance>1 && getBalance(root->left)>= 0)
        return rightRotate(root);
    //right right case
    if (balance<-1 && getBalance(root->right)<= 0)
        return leftRotate(root);
    //right left case
    if (balance<-1 && getBalance(root->right)>0)
    {
        root->right=rightRotate(root->right);
        return leftRotate(root);
    }
    //left right case
    if (balance>1 && getBalance(root->left)<0)
    {
        root->left=leftRotate(root->left);
        return rightRotate(root);
    }
    //if balanced
    return root;
}
int main()
{
    NodeT *root=createStaticTree();
    prettyPrint(root,0);
    root=deleteNode(root,8);
    prettyPrint(root,0);
    return 0;
}
