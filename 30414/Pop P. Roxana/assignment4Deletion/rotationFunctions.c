#include "tree.h"

/**************** FUNCTION PERFORMING A ROTATION TO THE LEFT AROUND A NODE *************/
void singleLeftRotation(nodeT **k1)///rotation around k1(a root of a tree/subtree)
{
    nodeT * k2= (*k1)->right;///set a pointer to the right child
    (*k1)->right=k2->left;///move the left subtree of k1 to k2
    k2->left=(*k1);///k1 becomes the left subtree of k2
    ///update heights
    (*k1)->height=max(height((*k1)->left),height((*k1)->right))+1;
    k2->height=max((*k1)->height,height(k2->right))+1;
    ///set new root
    (*k1)=k2;
}

/**************** FUNCTION PERFORMING A ROTATION TO THE RIGHT AROUND A NODE *************/
void singleRightRotation(nodeT **k2)///similar to the left rotation
{
    nodeT * k1= (*k2)->left;
    (*k2)->left=k1->right;
    k1->right=(*k2);
    (*k2)->height=max(height((*k2)->left),height((*k2)->right))+1;
    k1->height=max(height(k1->left),(*k2)->height)+1;
    (*k2)=k1;
}

/**************** FUNCTION PERFORMING DOUBLE ROTATION AROUND A NODE: right-left *********/
void rightLeftRotation(nodeT ** k3)
{
    singleRightRotation(&((*k3)->right));///single rotation to the right around the child of k3
    singleLeftRotation(k3);///single rotation to the left around k3
}

/**************** FUNCTION PERFORMING DOUBLE ROTATION AROUND A NODE: left-right *********/
void leftRightRotation(nodeT ** k3)///similar to the right-left rotation
{
    singleLeftRotation(&((*k3)->left));
    singleRightRotation(k3);
}
