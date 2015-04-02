#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "definition.h"

#define MAX_LINE_SIZE 256

DLL* createDLLNode(void* data)
{
    DLL* New = (DLL*)malloc(sizeof(DLL));
    char* c = malloc(sizeof(char)*(strlen((char*)data)+1));
    strcpy(c, (char*)data);
    New->data = (void*)c;
    New->next = NULL;
    New->prev = NULL;

    return New;
}

void DLLAddLast(DLL** node, void* data)
{
    DLL* New = createDLLNode(data);
    if(*node == NULL)
    {
        *node = New;
    }
    else
    {
        (*node)->next = New;
        New->prev = *node;
        *node = New;
    }
}

void DLLPrint(DLL* node)
{
    DLL* current = node;
    while(current != NULL)
    {
        printf("%s ", (char*)current->data);
        current = current->next;
    }
    printf("\n");
}

BinTree* createBinTreeNode(void* data)
{
    BinTree* New = (BinTree*)malloc(sizeof(BinTree));
    char* c = malloc(sizeof(char)*(strlen((char*)data)+1));
    strcpy(c, (char*)data);
    New->data = (void*)c;
    New->left = NULL;
    New->right = NULL;

    return New;
}

DLL* getListFromFile(FILE* I)
{
    DLL* New = NULL;

    char* Line = (char*)malloc(sizeof(char)*(MAX_LINE_SIZE + 1));
    fgets(Line, MAX_LINE_SIZE, I);

    char* p = strtok(Line, " ");
    while(p != NULL)
    {
        DLLAddLast(&New, (void*)p);
        p = strtok(NULL, " ");
    }

    return New;
}

void DLLRewind(DLL** node)
{
    while((*node)->prev != NULL)
        *node = (*node)->prev;
}

BinTree* createBinTree(DLL** nodeL)
{
    char* c = (char*)(*nodeL)->data;
    BinTree* New = createBinTreeNode((*nodeL)->data);
    *nodeL = (*nodeL)->next;
    //If it is a operand, it will be a leaf, otherwise it is an internal node(2 more function calls)
    //the strlen condition is necessary since a negative number would be seen as an operator
    if((strlen(c) == 1)&&
       ((c[0] == '+')||(c[0] == '-')||(c[0] == '*')||(c[0] == '/')))
    {
        New->left = createBinTree(nodeL);
        New->right = createBinTree(nodeL);
        return New;
    }
    else
    {
        return New;
    }
}

