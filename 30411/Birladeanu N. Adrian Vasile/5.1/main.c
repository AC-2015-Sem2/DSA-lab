#include <stdio.h>
#include <stdlib.h>
#include "matrix.h" //contine readAdjMatrix, printMatrix, getList, printList, getMatrix
#include "list.h" //inlocuieste node.h
#include "graph.h" //contine dfs, bfs


int main()
{
    FILE *f=fopen("matrix.txt", "r");
    readFromAdjMatrix(f);
    NodeT** adjList=getListfromMatrix(adjMatrix);
    printList(adjList);
    printf("\nBFS: ");
    bfs(adjList, 0);
    printf("\nDFS: ");
    dfs(adjList, 0);
    printf("\nDFS Recursiv: ");
    dfsRecurs(0, adjList);
    printf("\nMatricea initiala: \n");
    printMatrix(adjMatrix);
    printf("\nMatricea obtinuta din lista: \n");
    int** matrix=getMatrixfromList(adjList);
    printMatrix(matrix);
    printf("\n");
    //printf("\n %d ", getNumberOfNeighborsOfVertex(0, adjList));
    fclose(f);
    return 0;
}
