#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "NodeT.h"

NodeT* createNode(void *content)
{
    NodeT* newNode = (NodeT*)malloc(sizeof(NodeT));
    newNode->content = content;
    newNode->left = NULL;
    newNode->right= NULL;
    newNode->height = 1;
    return newNode;
}

void printStringElement(NodeT * node)
{
    printf ( "%s " ,(char*) node->content );
}

void printIntegerElement(NodeT * node)
{
    printf ( "%d|%d " ,(int) node->content, node->height );
}

void * getStringContent(char * content)
{
    return content;
}

void * getIntegerContent(char * content)
{
    return (void*)atoi(content);
}

int cmpIntegerContents(NodeT* n1, NodeT* n2) {
    return ((int)n1->content) - ((int)n2->content);
}
int cmpStringContents(NodeT* n1, NodeT* n2) {
    return strcmp((char*)n1->content, (char*)n2->content);
}

int getHeight(NodeT* nt) {
    if (!nt)
        return 0;
    else
        return nt->height;
}
