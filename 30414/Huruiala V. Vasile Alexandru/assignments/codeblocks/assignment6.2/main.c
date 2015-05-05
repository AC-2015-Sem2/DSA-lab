#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "graphAlgorithms.h"
#include "vertex_cover.h"
#include "utility.h"

int main()
{
    FILE* f = fopen("matrix6.txt", "r");
    int nrVert = 0;
    int** adjMat = NULL;
    initRand();

    readAdjMatrixEdges(f, &nrVert, &adjMat);
    printAdjMatrix(nrVert, adjMat);

    node** adjList = AdjMatToAdjList(adjMat, nrVert);
    printAdjList(adjList, nrVert);

    int** adjMat1 = AdjListToAdjMat(adjList, nrVert);
    printAdjMatrix(nrVert, adjMat1);

    printf("BFS for the 2 matrices(original and the one converted form matrix to list and back)\n");
    bfsMat(0, adjMat, nrVert);
    bfsMat(0, adjMat1, nrVert);
    printf("DFS for the 2 matrices(original and the one converted form matrix to list and back)\n");
    dfsMat(0, adjMat, nrVert);
    dfsMat(0, adjMat1, nrVert);
    printf("DFS recursive for the 2 matrices(original and the one converted form matrix to list and back)\n");
    dfsRecursiveMat(0, adjMat, nrVert);
    dfsRecursiveMat(0, adjMat1, nrVert);
    printf("BFS for the list converted form the matrix\n");
    bfsLst(0, adjList, nrVert);
    printf("DFS for the list converted form the matrix\n");
    dfsLst(0, adjList, nrVert);
    printf("DFS recursive for the list converted form the matrix\n");
    dfsRecursiveLst(0, adjList, nrVert);

    printf("Kruskal algorithm:(undirected edges)\n");
    kruskal(adjMat, nrVert);
    printf("Bellman Ford algorithm(parent->node):\n");
    bellman_ford(adjMat, nrVert, 0);

    printf("Minimum vertex cover approximation:\n");
    minVertexCover(adjMat1, nrVert);
    minVertexCoverNTimes(adjMat1, nrVert, 1000000);



    return 0;
}
