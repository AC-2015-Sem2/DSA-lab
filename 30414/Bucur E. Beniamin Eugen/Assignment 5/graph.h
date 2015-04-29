#include <stdio.h>
#include "node.h"

#define UNVISITED 0
#define VISITED 1

int     **adjMatrix;
int     nrOfVertices;
NodeT   **adjList;

void    listToMatrix();
void    matrixToList();
void    printAdjMatrix();
void    printAdjList();
void    bfs(int searchNode);
void    dfs(int searchNode);
void    dfsRecurs(int searchNode);
void    readFromAdjMatrix(FILE * f);
void    lBfs(int searchNode);
void    lDfs(int searchNode);
