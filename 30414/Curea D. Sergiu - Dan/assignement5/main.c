


#include "graph.h"
#include "adjacencyList.h"
int main()
{
    int i;
    FILE * f = fopen("matrix.txt","r");
    readFromAdjMatrix(f);
    printAdjMatrix();
    NodeT** adjList=(NodeT**)malloc(nrOfVerteces*sizeof(NodeT));
    adjList=adjacencyList(nrOfVerteces,adjMatrix);
    printf("\nThe adjancecy list:\n");
    for (i=0; i<nrOfVerteces; i++)
    {
        printf("%d: ",i);
        printAll(adjList[i]);
    }
    printf("\n Traversals using adjancecy list:\nbfs Traversal: ");
    bfsList(0);
    printf("\ndfs Traversal:");
    dfs(0);
    printf("\n");
    adjMatrix=adjacencyMatrix(adjList);
    printf("\n The adjacency matrix obtained from the adjancency list:");
    printAdjMatrix();
    return 0;
}

