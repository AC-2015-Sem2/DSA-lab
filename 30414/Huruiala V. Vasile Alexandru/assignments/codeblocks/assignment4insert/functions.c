#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "definition.h"
#define MAX_NR_LENGTH 10

BTree* createBTreeNode(void* data)
{
    BTree* New = (BTree*)malloc(sizeof(BTree));
    New->data = malloc(sizeof(int));
    *(int*)New->data = *(int*)data;
    New->left = NULL;
    New->right = NULL;

    New->Lweight = 0;
    New->Rweight = 0;

    return New;
}

//Insets an element to its place
//such that it remains a binary search tree
BTree* BSTInsert(BTree* root, void* data)
{
    if(root == NULL)
        return createBTreeNode(data);
    else if(*(int*)root->data < *(int*)data)
        root->right = BSTInsert(root->right, data);
        else
        root->left = BSTInsert(root->left, data);

    return root;
}

int maxDepth(BTree* root)
{
    if(root == NULL)
    {
        return 0;
    }
    else
    {
        int left = maxDepth(root->left) + 1;
        int right = maxDepth(root->right) + 1;
        if(left > right)
            return left;
        else
            return right;
    }
}

//This will get the maximum depths of its subtrees
void getWeight(BTree* root)
{
    if(root != NULL)
    {
        root->Lweight = maxDepth(root->left);
        root->Rweight = maxDepth(root->right);
        getWeight(root->left);
        getWeight(root->right);
    }
}

BTree* BSTRotate(BTree* root)
{
    if(root == NULL)
    {
        return NULL;
    }
    else
    {
        int diff = root->Lweight - root->Rweight;
        if(diff > 1)
        //>1 means the imbalance is on the left
        {
            int zig_type = root->left->Lweight - root->left->Rweight;

            if(zig_type > 0)
            //zig-zig
            {
                //single rotation
                //store the current root
                BTree* aux = root;
                //the left child becomes the root
                root = root->left;
                //the right child of the new root becomes the left child of the old root
                aux->left = root->right;
                //the old root becomes the right child of the new root
                root->right = aux;

                return root;
            }
            else if(zig_type < 0)
            //zig-zag
            {
                //double rotation
                //1: turn to zig-zig
                //store the left child of the root(to swap it with its right child)
                BTree* aux = root->left;
                //the right child of the left child becomes the new left child of the root(1st step of the swap)
                root->left = root->left->right;
                //child transfer
                aux->right = root->left->left;
                //the child becomes the parent(to finalize the swap)
                root->left->left = aux;
                //it is a zig-zig now
                //store the current root
                aux = root;
                //the left child becomes the root
                root = root->left;
                //the right child of the new root becomes the left child of the old root
                aux->left = root->right;
                //the old root becomes the right child of the new root
                root->right = aux;

                return root;
            }

        }
        else if(diff < -1)
        //<-1 the imbalance is on the right
        {
            int zig_type = root->right->Lweight - root->right->Rweight;

            if(zig_type < 0)
            //zig-zig
            {
                //single rotation
                //store the current root
                BTree* aux = root;
                //the right child becomes the root
                root = root->right;
                //the left child of the new root becomes the right child of the old root
                aux->right = root->left;
                //the old root becomes the left child of the new root
                root->left = aux;

                return root;
            }
            else if(zig_type > 0)
            //zig-zag
            {
                //double rotation
                //1: turn to zig-zig
                //store the right child of the root(to swap it with its right child)
                BTree* aux = root->right;
                //the left child of the right child becomes the new left child of the root(1st step of the swap)
                root->right = root->right->left;
                //child transfer
                aux->left = root->right->right;
                //the child becomes the parent(to finalize the swap)
                root->right->right = aux;
                //it is a zig-zig now
                //store the current root
                aux = root;
                //the right child becomes the root
                root = root->right;
                //the left child of the new root becomes the right child of the old root
                aux->right = root->left;
                //the old root becomes the left child of the new root
                root->left = aux;

                return root;
            }
        }
        else
        {
            return root;
        }
    }
    return root;
}

//Recursive part of the function below
int isBSTUtil(BTree* root, int Min, int Max)
{
    if(root == NULL)
        return 1;
    else if((*(int*)root->data > Max)||(*(int*)root->data < Min))
        return 0;
    else
        return isBSTUtil(root->left, Min, *(int*)root->data) & isBSTUtil(root->right, *(int*)root->data, Max);
}

//True if it is a balanced binary search tree
int isBST(BTree* root)
{
    return isBSTUtil(root ,INT_MIN, INT_MAX);
}

BTree* BSTBallance(BTree* root)
{
    if(root == NULL)
    {
        return NULL;
    }
    else
    {
        BTree* aux = root;
        aux = BSTRotate(root);
        if(aux == root)
        //This means no changes occurred(rotate always changes the root if the tree is imbalanced)
        //So if a rotation took place make no more operations
        //because the root will have been altered
        {
            aux->left = BSTBallance(aux->left);
            aux->right = BSTBallance(aux->right);
        }
        return aux;
    }
}

void AVLInsert(BTree** root, void* data)
{
    //step 1: add it
    *root = BSTInsert(*root, data);
    //step 2: get feedback
    getWeight(*root);
    //step 3: if it is imba nerf it
    *root = BSTBallance(*root);
}

BTree* createAVLFromFile(FILE* I)
{
    BTree* root = NULL;
    char* data = (char*)malloc(sizeof(char)*MAX_NR_LENGTH);
    while(fscanf(I, "%s", data) != -1)
    {
        int datap = atoi(data);
        AVLInsert(&root, (void*)&datap);

    }
    return root;
}
