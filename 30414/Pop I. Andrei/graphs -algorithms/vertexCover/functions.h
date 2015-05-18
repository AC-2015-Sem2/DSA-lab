# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include "list.h"

int ** adjMatrix;
int nrOfVerteces;

void vertexCover();
void readFromAdjMatrix(FILE *);
edgeT *getTheEdges(int **);


