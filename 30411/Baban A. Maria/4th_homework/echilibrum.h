#ifndef ECHILIBRUM_H_INCLUDED
#define ECHILIBRUM_H_INCLUDED
#include "print.h"
#include "create.h"
#include <stdio.h>
#include <stdlib.h>

void echilibrum(NodeT *p);
void maxPath(NodeT *p,int *maximum,int lung);
void preorderEchilibrum(NodeT *root);
void preorderCheck(NodeT *root);
void check(NodeT *root);
void AVLTree(NodeT *root);

#endif // ECHILIBRUM_H_INCLUDED
