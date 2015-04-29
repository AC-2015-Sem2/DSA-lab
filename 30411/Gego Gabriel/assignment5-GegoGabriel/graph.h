#include <stdio.h>
#include "node.h"


#define UNVISITED 0
#define VISITED 1

int nrOfVertices;
void dfsRecurs(int searchNode);

NodeT** MatrixToList(int **adjMatrix);
void AdjListToMatrix(NodeT** adjList);
