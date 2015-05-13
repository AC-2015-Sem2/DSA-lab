#include "queue.h"
#include "stack.h"
#include "graph.h"

int main()
{
    FILE * f = fopen("matrix.txt","r");
    readFromAdjMatrix(f);
    printAdjMatrix();
    bfs(0);
    dfs(0);
    dfsRecurs(0);

    adjMatrix_list();
    printAdjList();
    bfsList(0);
    dfsList(0);


    adjList_Matrix();
    printAdjMatrix();
    bfs(0);
    dfs(0);


    return 0;
}
