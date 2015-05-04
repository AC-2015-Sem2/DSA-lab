#include "queue.h"
#include "stack.h"
#include "graph.h"

int main()
{
    FILE *f = fopen("matrix.txt","r");
    NodeT **adjacencyList;
    int **adjacencyMatrix;

    readFromAdjMatrix(f);
    printf("The matrix is : \n");
    printAdjMatrix();
    printf("The output of BFS algorithm is : \n");
    bfs(0);
    printf("\n");
    printf("The output of DFS algorithm is : \n");
    dfs(0);
    printf("\n");
    printf("The output of DFSrecurs is : \n");
    dfsRecurs(0);
    printf("\n\n");
    printf("The algorithm using adjacency list is : \n\n");
    adjacencyList = fromMatrixtoList(adjMatrix);
    printf("The adjacency List is : \n");
    printAdjList(adjacencyList);
    adjacencyMatrix=fromListtoMatrix(adjacencyList);
    adjMatrix=adjacencyMatrix;
    printf("\n\n");
    printf("The adjacency matrix from the adjacency list is : \n");
    printAdjMatrix();
    printf("\n\n");
    printf("The output of BFS algorithm is : \n");
    bfsList(0, adjacencyList);
    printf("\n");
    printf("The output of DFS algorithm is : \n");
    dfsList(0, adjacencyList);
    printf("\n");
    printf("The output of DFSrecurs is : \n");
    dfsRecursList(0, adjacencyList);
    return 0;
}
