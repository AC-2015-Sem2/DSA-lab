#ifndef INSERT_H_INCLUDED
#define INSERT_H_INCLUDED
#include "echilibrum.h"
#include "print.h"
#include "create.h"
#include <stdio.h>
#include <stdlib.h>

NodeT *createNode(int x);
NodeT *insertNode(NodeT *p,int data);
NodeT* createStaticTree();
NodeT *rotateRight(NodeT *p);
NodeT *rotateLeft(NodeT *p);
NodeT *rotateRight_Left(NodeT *p);
NodeT *rotateLeft_Right(NodeT *p);
NodeT *balancedTree(NodeT *p);

#endif // INSERT_H_INCLUDED
