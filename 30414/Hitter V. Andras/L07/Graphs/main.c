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
    MatrixToList(adjMatrix);
    printList();
    dfsRecurs(0);
    ListToMatrix(L,f);
    printNEWAdjMatrix();
    return 0;
}
