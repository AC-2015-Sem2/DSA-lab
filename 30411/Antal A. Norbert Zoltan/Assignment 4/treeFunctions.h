#ifndef TREEFUNCTIONS_H_INCLUDED
#define TREEFUNCTIONS_H_INCLUDED
#include <stdio.h>
#include "AVL_Def.h"

NodeT* createNode(int);
int getHeight(NodeT*);
int heightDiff(NodeT*);
int isPresent(NodeT*, int);
NodeT* rotate_left(NodeT*);
NodeT* rotate_right(NodeT*);
NodeT* balanceF(NodeT*);
NodeT* insertUTIL(NodeT*, int);
NodeT* insertF(NodeT*, int);
NodeT* deleteUTIL(NodeT*, NodeT*);
NodeT* deleteF(NodeT*, int);
void prettyPrint(NodeT*, int, FILE*);

#endif // TREEFUNCTIONS_H_INCLUDED
