#include "queue.h"
#include "stack.h"
#include "graph.h"
#include "list.h"
#include "algorithms.h"

int main()
{
    FILE * f = fopen("matrix.txt","r");
    //FILE * f = fopen("matrix2.txt","r");
    readFromAdjMatrix(f);
    printAdjMatrix();
    int startNode=0;
    int finishNode=6;


    ///
    getNumberOfNeighborsOfVertex=&getNumberOfNeighborsOfVertex1;
    getAllNeighborsOfVertex=&getAllNeighborsOfVertex1;
    printf("The longest path is: \n" );
    getLongestRecurs(startNode,finishNode);
    bfs(0);
    dfs(0);
    printf("\nRecursively:");
//    dfsRecurs(0);

    ///
    adjArray=listFromMatrix(adjMatrix);

    getNumberOfNeighborsOfVertex=&getNumberOfNeighborsOfVertex2;
    getAllNeighborsOfVertex=&getAllNeighborsOfVertex2;
    bfs(0);
    dfs(0);
   // dfsRecurs(0);

    ///
    matrixFromList(adjArray);
    getNumberOfNeighborsOfVertex=&getNumberOfNeighborsOfVertex1;
    getAllNeighborsOfVertex=&getAllNeighborsOfVertex1;
    bfs(0);
    dfs(0);
    printf("\nRecursively:");
  //  dfsRecurs(0);

    return 0;
}
