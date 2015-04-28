#ifndef EXTRA_H_INCLUDED
#define EXTRA_H_INCLUDED

#include "myHW.h"

void longestPath(int a, int b);
void longestPathUtil(int a, int b, int c, int*** paths, int* nrPath, int level);
int** allocateMatrixAndInitialise(int val);

List* gotoVertex(int v);
int** addVertexToList(int** a, int nrPath, int c);
int alreadyThere(int** a, int nrPath, int c);
void findMaxPath(int** a);

#endif // EXTRA_H_INCLUDED
