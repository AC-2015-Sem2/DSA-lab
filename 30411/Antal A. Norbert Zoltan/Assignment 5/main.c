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
    toList();
    bfs(0);
    dfs(0);
    dfsRecurs(0);
    toMatrix();
    bfs(0);
    dfs(0);
    dfsRecurs(0);
    return 0;
}
