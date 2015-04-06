#ifndef NODET_H
#define NODET_H

typedef struct node {
    void* content;
    struct node *left, *right;
    int height;
} NodeT;

// constructor
NodeT* createNode(void* content);

// print functions
void (*printElement)(NodeT*);

void printStringElement(NodeT* node);
void printIntegerElement(NodeT* node);

// getters
void* (*getContent)(char*);

void* getStringContent(char* content);
void* getIntegerContent(char* content);

// compare elements
int (*cmpContents)(NodeT*, NodeT*);

int cmpIntegerContents(NodeT* n1, NodeT* n2);
int cmpStringContents(NodeT* n1, NodeT* n2);

int getHeight(NodeT* nt);

#endif // NODET_H
