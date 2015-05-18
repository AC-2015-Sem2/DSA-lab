#include <stdio.h>
#include <stdlib.h>
#include "structures.h"
#include "code.h"

int main()
{
    // create the graph
    FILE *f;
    int V;
    f=fopen("matrix.txt.","r");
    fscanf(f,"%d",&V);
    int** adjMat=getMatrix(f,V);
    struct Graph* graph = createGraph(V);
    int i,j;
    printf("  The matrix is : \n\n");
    printMatrix(adjMat,V);

    //for a un-oriented graph
    for(i=0;i<V;i++)
        for(j=i;j<V;j++)
            if(adjMat[i][j]==1)
                addEdge(graph, i,j);
    printGraph(graph);// print the adjacency list representation of the above graph

    //create adjacency graph from adjacency list
    printf("\n\n");
    int** adjMatFromList=createAdjMatFromList(graph, V);
    printMatrix(adjMatFromList,V);
    return 0;
}
