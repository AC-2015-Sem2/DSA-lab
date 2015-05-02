#include <stdio.h>
#include <stdlib.h>
#include "definition.h"

BinTree* createBinTreeNode(void* data)
{
    BinTree* NewNode = (BinTree*)malloc(sizeof(BinTree));
    NewNode->data = malloc(sizeof(char));
    *(char*)NewNode->data = *(char*)data;
    NewNode->left = NULL;
    NewNode->right = NULL;

    return NewNode;
}

BinTree* createBinTree(FILE* In)
{
    char c;
    do
        fscanf(In, "%c", &c);
    while(c == ' ');
    if(c == '*')
    {
        return NULL;
    }
    else
    {
        BinTree* New = createBinTreeNode((void*)&c);
        New->left = createBinTree(In);
        New->right = createBinTree(In);

        return New;
    }
}

DLL* createDLLNode(void* data)
{
    DLL* NewNode = (DLL*)malloc(sizeof(DLL));
    NewNode->data = malloc(sizeof(char));
    *(char*)NewNode->data = *(char*)data;
    NewNode->next = NULL;
    NewNode->prev = NULL;

    return NewNode;
}

//Add First would have worked as well,
//it would still have needed rewinding
void DLLAddLast(DLL** node, void* data)
{
    DLL* NewNode = createDLLNode(data);
    if(*node == NULL)
    {
        *node = NewNode;
    }
    else
    {
        (*node)->next = NewNode;
        NewNode->prev = (*node);
        *node = (*node)->next;
    }
}

//This is similar to preorder, but by adding a '*'
//where a left or right descendant would have existed
//The resulted sequence can be transformed back into a tree
void getListRec(BinTree* nodeT, DLL** ptr_nodeL)
{
    char c;
    if(nodeT == NULL)
    {
        c = '*';
        DLLAddLast(ptr_nodeL, (void*)&c);
    }
    else
    {
        c = *(char*)nodeT->data;
        DLLAddLast(ptr_nodeL, (void*)&c);
        getListRec(nodeT->left, ptr_nodeL);
        getListRec(nodeT->right, ptr_nodeL);
    }
}

DLL* BinTreeToDLList(BinTree* node)
{
    DLL* ResultingList = NULL;

    getListRec(node, &ResultingList);

    return ResultingList;
}

//We need to go back to the first element
void DLLRewind(DLL** node)
{
    if(*node != NULL)
    {
        while((*node)->prev != NULL)
            *node = (*node)->prev;}
}

void DLLPrint(FILE* O, DLL* node)
{
    DLL* current = node;
    while(current != NULL)
    {
        printf("%c ", *(char*)current->data);
        fprintf(O, "%c ", *(char*)current->data);
        current = current->next;
    }
    printf("\n");
    fprintf(O, "\n");
}

BinTree* getTreeRec(DLL** nodeL)
{
    char c = *(char*)(*nodeL)->data;
    *nodeL = (*nodeL)->next;
    if(c == '*')
    {
        return NULL;
    }
    else
    {
        BinTree* New = createBinTreeNode((void*)&c);
        New->left = getTreeRec(nodeL);
        New->right = getTreeRec(nodeL);
        return New;
    }
}

//Done as such to match the description document
//Does not modify the list or the parameter in the calling function
//in any way but if it had to it can easily be changed to do that
BinTree* DDListToBinTree(DLL* node)
{
    return getTreeRec(&node);
}
