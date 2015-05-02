#include "treeFunctions.h"

nodeT* allocTreeNode()
{
    return (nodeT*)malloc(sizeof(nodeT));
}

nodeT* createTreeNode(int data)
{
    nodeT *tempNode = allocTreeNode();
    tempNode->data = data;
    tempNode->left = NULL;
    tempNode->right = NULL;
    return tempNode;
}

nodeT* createBinaryTree()
{
    nodeT* p;
    char* data = (char*)malloc(sizeof(char)*100);
    fscanf(f, "%s", data);
    if(strcmp(data, "*") == 0)
    {
        return NULL;
    }
    else
    {
        p = createTreeNode(atoi(data));
        p->left = createBinaryTree();
        p->right = createBinaryTree();
    }
    return p;
}

void preorder(nodeT* tempNode, nodeL** listNode)
{
    if(tempNode != NULL)
    {
        char* tempData = (char*)malloc(sizeof(char)*100);
        itoa(tempNode->data, tempData, 10);
        addLast(listNode, tempData);

        preorder(tempNode->left, listNode);
        preorder(tempNode->right, listNode);
    }
    else
    {
        addLast(listNode, "*");
    }
}

nodeL* getListFromTree(nodeT* root)
{
    nodeL* listNode = NULL;
    preorder(root, &listNode);
    return listNode;
}

void prettyPrint(nodeT *root,int recLevel)
{
    if(root==NULL)
    {
        recLevel--;
        return;
    }
    recLevel++;
    prettyPrint(root->right,recLevel);
    int j=0;

    for(j=0; j<recLevel-1; j++)
    {
        printf("     ");
    }

    printf("%d", root->data);

    printf("\n");

    prettyPrint(root->left,recLevel);
}

nodeT* createTreeFromList(nodeL **node)
{
    nodeT* p;

    char *c = (*node)->data;
    *node = (*node)->next;
    if(strcmp(c, "*") == 0)
    {
        return NULL;
    }
    else
    {
        p = createTreeNode(atoi(c));
        p->left = createTreeFromList(node);
        p->right = createTreeFromList(node);
    }

    return p;
}

nodeT* getTreeFromList(nodeL *node)
{
    return createTreeFromList(&node);
}
