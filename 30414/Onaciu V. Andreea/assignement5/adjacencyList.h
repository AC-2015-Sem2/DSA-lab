#include "node.h"
void addLast(NodeT *vertexList,int adjVertex);
NodeT **adjacencyList(int nrOfVerteces,int** adjMatrix);
void printAll(NodeT *list);
int getNumberOfNeighborsOfVertexFromList(int v);
void dfsList(int searchNode);
void bfsList(int searchNode);
int** adjacencyMatrix(NodeT** adjList);
