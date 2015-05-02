#ifndef INSERT_H_INCLUDED
#define INSERT_H_INCLUDED
#include "Echilibru.h"

NodeT *insertNode(NodeT*,int);
NodeT *balancing(NodeT *);
NodeT *createNode(int );
NodeT *simpleRotationLeft(NodeT *);
NodeT *simpleRotationRight(NodeT *);
NodeT *doubleRotationLeft(NodeT *);
NodeT *doubleRotationRight(NodeT *);

#endif // INSERT_H_INCLUDED
