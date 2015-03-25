#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "treeFunctions.h"
#include "listFunctions.h"

NodeL* getListFromTree(NodeT*, NodeL**);
NodeT* getTreeFromList(NodeL**);

int main()
{
    NodeL* tail = NULL;
    FILE* ifile = fopen("inp.txt", "r");
    NodeT* root = createBinTree(ifile);
    fclose(ifile);
    NodeL* firstFromList = getListFromTree(root, &tail);
    traverseList(firstFromList);
    root = getTreeFromList(&firstFromList);
    prettyPrint(root, 0);
    return 0;
}

NodeL* getListFromTree(NodeT* root, NodeL** tail)
{
    NodeL* node;
    if (root==NULL)
    {
        node = addLast(tail, "*");
    }
    else
    {
        node = addLast(tail, root->data);
        getListFromTree(root->left, tail);
        getListFromTree(root->right, tail);
    }
    return node;
}

NodeT* getTreeFromList(NodeL** head)
{
    if (!strcmp((*head)->data, "*"))
    {
        delFirst(head);
        return NULL;
    }
    else
    {
        NodeT* node = (NodeT*)malloc(sizeof(NodeT));
        node->data = delFirst(head);
        node->left = getTreeFromList(head);
        node->right = getTreeFromList(head);
        return node;
    }
}


