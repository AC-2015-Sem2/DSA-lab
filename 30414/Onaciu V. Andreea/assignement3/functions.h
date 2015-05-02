#include "structDef.h"
nodeT * createNode(char d);
nodeT *createStaticBinTree();
void inorder(nodeT* root);
nodeT* createTreeFromList();
void addLast(char x);
void printAll(nodeL* head);
nodeL *createListFromTree(nodeT* root);
void prettyPrint(nodeT *root,int recLevel);
