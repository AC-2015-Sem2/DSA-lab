#include "queue.h"
#include "stack.h"
#include "graph.h"

int main()
{
     FILE * f = fopen("matrix.txt","r");
    readFromAdjMatrix(f);
    printAdjMatrix(adjMatrix);

    int n = getNumberOfNeighborsOfVertex(4);
    int* v = getAllNeighborsOfVertex(4);
    int i;

    createAdjList(adjMatrix);
    printAdjList();

    bfs(0);
    dfs(0);
    dfsRecurs(0);

    int** newAdjMatr = list2matrix(adjList, adjListlength);
    printAdjMatrix(newAdjMatr);


}
