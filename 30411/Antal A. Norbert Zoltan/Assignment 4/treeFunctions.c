#include <stdlib.h>
#include "AVL_Def.h"
#include "treeFunctions.h"

NodeT* createNode(int data)
{
    NodeT* node = (NodeT*)malloc(sizeof(NodeT));
    node->data = data;
    node->height = 1;
    node->left = node->right = NULL;
    return node;
}

int getHeight(NodeT* node)
{
    if (node==NULL)
    {
        return 0;
    }
    return node->height;
}

int heightDiff(NodeT* node)
{
    if (node==NULL)
    {
        return 0;
    }
    return getHeight(node->left) - getHeight(node->right);
}

int isPresent(NodeT* root, int data)
{
    if (root==NULL)
    {
        return 0;
    }
    else if(data>root->data)
    {
        return isPresent(root->right, data);
    }
    else if (data<root->data)
    {
        return isPresent(root->left, data);
    }
    else
    {
        return 1;
    }
}

NodeT* rotateLeft(NodeT* node)
{
    NodeT* rotAux = node->right;
    node->right = rotAux->left;
    rotAux->left = balanceF(node);
    return balanceF(rotAux);
}

NodeT* rotateRight(NodeT* node)
{
    NodeT* rotAux = node->left;
    node->left = rotAux->right;
    rotAux->right = balanceF(node);
    return balanceF(rotAux);
}

NodeT* balanceF(NodeT* node)
{
    if (heightDiff(node) > 1)
    {
        if (heightDiff(node->left) < 0)
        {
            node->left = rotateLeft(node->left);
        }
        return rotateRight(node);
    }
    else if (heightDiff(node) < -1)
    {
        if (heightDiff(node->right) > 0)
        {
            node->right = rotateRight(node->right);
        }
        return rotateLeft(node);
    }
    if (node!=NULL)
    {
        node->height = (getHeight(node->left) < getHeight(node->right) ? getHeight(node->right) : getHeight(node->left)) + 1;
    }
    return node;
}

NodeT* insertUTIL(NodeT* node, int data)
{
    if (node==NULL) return createNode(data);
    if (node->data>data)
    {
        node->left = insertUTIL(node->left, data);
    }
    else
    {
        node->right = insertUTIL(node->right, data);
    }
    return balanceF(node);
}

NodeT* insertF(NodeT* node, int data)
{
    return isPresent(node, data) ? node : insertUTIL(node, data);
}

NodeT* deleteUTIL(NodeT* node1, NodeT* node2)
{
    if (node1==NULL)
    {
        return node2;
    }
    else
    {
        node1->right = deleteUTIL(node1->right, node2);
        return balanceF(node1);
    }
}

NodeT* deleteF(NodeT* node, int data)
{
    if (node==NULL)
    {
        return NULL;
    }
    else if (node->data==data)
    {
        NodeT* toRet = deleteUTIL(node->left, node->right);
        free(node);
        return toRet;
    }
    else if (node->data<data)
    {
        node->right = deleteF(node->right, data);
    }
    else
    {
        node->left = deleteF(node->left, data);
    }
    return balanceF(node);
}

void prettyPrint(NodeT* root, int x, FILE* file)
{
    if (root==NULL) return;
    prettyPrint(root->right, x+1, file);
    int i;
    for (i=0; i<x; i++)
    {
        fprintf(file, "   ");
    }
    fprintf(file, "%d\n", root->data);
    prettyPrint(root->left, x+1, file);
};
