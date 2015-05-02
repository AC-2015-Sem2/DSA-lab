#include "queue.h"
#include "stack.h"
#include "graph.h"

int main()
{
    FILE *q = fopen("Adj.txt","r");
    readFromAdjMatrix(q);
    printAdjMatrix();
    NodeT** v=(NodeT**)malloc(nrOfVerteces*sizeof(NodeT));
    v=CreateList(adjMatrix);
    int **matrix=(int**)malloc(sizeof(int*)*nrOfVerteces);
    matrix=createMatrix(v);
    printAllList(v);
    printMatrix(matrix);
    bfs(0);
    dfs(0);
    dfsRecurs(0);
    return 0;
}
