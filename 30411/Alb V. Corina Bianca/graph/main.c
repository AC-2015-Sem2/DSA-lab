#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "stack.h"
#include "graph.h"

int main()
{
    FILE * f = fopen("matrix.txt","r");
    readFromAdjMatrix(f);
    printAdjMatrix();

    //CREATE ADJECENCY LIST FROM MATRIX

    int i;
    struct adjgraph *graph=creategraph(nrOfVerteces);
    for(i=0;i<nrOfVerteces;i++){
        int nrOfNeighbors=getNumberOfNeighborsOfVertex(i);
        int *neighbors=getAllNeighborsOfVertex(i);
        int j;
        for(j=0;j<nrOfNeighbors;j++){
            addedge(graph,i,neighbors[j]);
        }
    }
    printgraph(graph);


    //CREATE ADJACENCY MATRIX FOM LIST
    createadjmatrix(nrOfVerteces);
    for(i=0;i<nrOfVerteces;i++){
        matrix(graph->array[i].head,i);
    }
    return 0;
    bfs(0);
    dfs(0);
    dfsRecurs(0);
    return 0;
}
