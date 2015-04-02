#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "T_t_DLL_Def.h"

NodeT* createBinTree(FILE* file)
{
    char* data = (char*)malloc(30);
    fscanf(file, "%s", data);
    if (!strcmp(data, "*"))
    {
        return NULL;
    }
    else
    {
        NodeT* node = (NodeT*)malloc(sizeof(NodeT));
        node->data = data;
        node->left = createBinTree(file);
        node->right = createBinTree(file);
        return node;
    }
}

void prettyPrint(NodeT* root, int x)
{
    if (root==NULL) return;
    prettyPrint(root->right, x+1);
    int i;
    for (i=0; i<x; i++)
    {
        printf("   ");
    }
    printf("%s\n", root->data);
    prettyPrint(root->left, x+1);
};
