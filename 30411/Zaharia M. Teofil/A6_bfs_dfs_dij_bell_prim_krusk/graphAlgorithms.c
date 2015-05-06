#include "graph.h"
#include "graphRepresentation.h"
#include "graphAlgorithms.h"

//! Prim related stuff
edgeT getMinimumEdgeForCurrentlyVisitedNodes(int * visited)
{
    edgeT* min = (edgeT*) malloc (sizeof (edgeT));
    min->weight = MAX;

    int nNb, *nb;

    int i, j;
    for (i = 0; i < nrOfVerteces; i++) {
        if (visited[i]) {
            nNb = getNumberOfNeighborsOfVertex(i);
            nb = getAllNeighborsOfVertex(i);

            for (j = 0; j < nNb; j++) {
                if (adjMatrix[i][nb[j]]) {
                    if (!visited[nb[j]]) {
                        if (adjMatrix[i][nb[j]] < min->weight) {
                            min->weight = adjMatrix[i][nb[j]];

                            min->source = i;
                            min->destination = nb[j];
                        }
                    }
                }
            }
        }
    }
    visited[min->destination] = 1;
    return *min;
}

void printEdges(edgeT* edges, int n)
{
    int i;
    for(i=0; i<n; i++)
    {
        printf("%c -> %c\t",edges[i].source+65, edges[i].destination+65);
    }
    printf("\n");
}

void prim(int startNode)
{
    int* visited = (int*) calloc(nrOfVerteces, sizeof(int));
    edgeT* edges = (edgeT*) malloc ((nrOfVerteces-1) * sizeof(edgeT));
    int visNo = 1;
    visited[startNode] = 1;

    while (visNo < nrOfVerteces) {
        edges[visNo-1] = getMinimumEdgeForCurrentlyVisitedNodes(visited);
        visNo++;
    }

    printEdges(edges, nrOfVerteces-1);

}

//! Kruskal related stuff
edgeT getMinimumEdgeForAdjacencyMatrix(int ** adjMat)
{
    int i,j;
    edgeT minEdge;
    minEdge.weight=MAX;
    for (i=0; i<nrOfVerteces; i++)
    {
        for (j=0; j<nrOfVerteces; j++)
        {
            if(adjMat[i][j] > 0)
            {
                if(adjMat[i][j]<minEdge.weight)
                {
                    minEdge.source = i;
                    minEdge.destination = j;
                    minEdge.weight = adjMat[i][j];
                }
            }
        }
    }

    return minEdge;
}

int ** getCopyOfAdjecencyMatrix()
{
    int i,j;
    int ** copyAdjMatrix =(int**)malloc(nrOfVerteces*sizeof(int*));
    for (i=0; i<nrOfVerteces; i++)
    {
        *(copyAdjMatrix+i)=(int*)malloc(nrOfVerteces*sizeof(int));
        for(j=0; j<nrOfVerteces; j++)
        {
            copyAdjMatrix[i][j] = adjMatrix[i][j];
        }
    }
    return copyAdjMatrix;
}

int getParent(int * parent, int i)
{
    while (parent[i] != i) {
        i = parent[i];
    }

    return i;
}

int uni(int * parent, int i,int j)
{
    int pi = getParent(parent, i);
    int pj = getParent(parent, j);

    if (pi != pj) {
        parent[pi] = pj;
        return 1;
    }

    return 0;
}

void kruskal()
{
    printf("Kruskal start\n\n");
    int i;
    int* parent = (int*) malloc (sizeof(int));
    edgeT* edges = (edgeT*) malloc ((nrOfVerteces-1) * sizeof(edgeT));
    int** adjMatrCpy = getCopyOfAdjecencyMatrix(adjMatrix);

    // set each edges as its own tree
    for (i = 0; i < nrOfVerteces; i++) {
        parent[i] = i;
    }

    int noOfTrees = nrOfVerteces;
    int noOfEdges = 0;
    edgeT minE;


    while (noOfTrees > 1) {
        // find min edge
        minE = getMinimumEdgeForAdjacencyMatrix(adjMatrCpy);

        // remove min edge
        adjMatrCpy[minE.source][minE.destination] = 0;
        adjMatrCpy[minE.destination][minE.source] = 0;

        // if the minE.u and minE.v are in different trees, unite
        if (uni(parent, minE.destination, minE.source)) {
            edges[noOfEdges++] = minE;
            noOfTrees--;
        }
        //noOfTrees--;
    }
    printf("Min Spanning tree edges:\n");
    printEdges(edges, nrOfVerteces-1);
    free(edges);

    printf("\nKruskal end\n\n");
}

//! Dijsktra related stuff
int getMinDistanceVertex(int * distances, int * visited){
    int i, min = MAX+1, minV = 0;
    for (i = 0; i < nrOfVerteces; i++) {
        if (!visited[i]) {
            if (distances[i] < min) {
                minV = i;
                min = distances[i];
            }
        }
    }
    return minV;
}

void dijkstra(int startNode)
{
    int* parent = (int*) malloc (nrOfVerteces * sizeof(int));
    int* visited = (int*) malloc (nrOfVerteces * sizeof(int));
    int* distances = (int*) malloc (nrOfVerteces * sizeof(int));

    int i;
    for (i = 0; i < nrOfVerteces; i++) {
        parent[i] = i;
        visited[i] = 0;
        distances[i] = MAX;
    }

    distances[startNode] = 0;
    int minV;

    printf("Dijkstra start:\n\n");

    int j;
    for (i = 0; i < nrOfVerteces; i++) {

        minV = getMinDistanceVertex(distances, visited);
        visited[minV] = 1;
        printf("MinV:%d ", minV);
        for (j = 0; j < nrOfVerteces; j++) {
            if (adjMatrix[minV][j] && !visited[j] && distances[minV] + adjMatrix[minV][j] < distances[j]) {
                distances[j] = distances[minV] + adjMatrix[minV][j];
                parent[j] = minV;
            }
        }
        for (j = 0; j < nrOfVerteces; j++) {
            printf("%d ", distances[j]);
        }
        printf("\n");
    }

    int* path = (int*) calloc(nrOfVerteces, sizeof(int));
    int n = nrOfVerteces-1;


    // create multiple paths
    int it = 0;
    for (it = 0; it < nrOfVerteces; it++) {
    int k = it;
    n = nrOfVerteces-1;
    while (parent[k] != k) {
        path[n--] = k;
        k = parent[k];
    }
    path[n] = k;

    printf("%c ", startNode+65);
    for (i = 0; i < nrOfVerteces; i++) {
        if (path[i]) {
            printf("%c ", path[i]+65);
        }
    }
    printf("\n");
    }
    printf("\nDijkstra end\n\n");
}

void bellman(int startNode) {
    printf("Bellman start\n\n");

    // init
    int *parent = (int*) calloc(nrOfVerteces, sizeof(int));
    int *distance = (int*) calloc(nrOfVerteces, sizeof(int));

    int i;
    for (i = 0; i < nrOfVerteces; i++) {
        parent[i] = i;
        distance[i] = MAX;
    }
    distance[startNode] = 0;

    // dijkstra-like, but V-1 times for EACH edge
    int u, v;
    for (i = 0; i < nrOfVerteces - 1; i++) {
        // check each edge (u, v) => E steps
        for (u = 0; u < nrOfVerteces; u++) {
            // directed graph, have to check (u, v), (v, u)
            for (v = 0; v < nrOfVerteces; v++) {
                // if (u, v) is an edge
                if (u != v && adjMatrix[u][v]) {
                    if (distance[u] + adjMatrix[u][v] < distance[v]) {
                        distance[v] = distance[u] + adjMatrix[u][v];
                        parent[v] = u;
                    }
                }
            }
        }
    }

    //complexity V * U

    // check for negative edge cycles
    int hasNegativeEdges = hasNegativeEdgeCycles(distance);

    if (!hasNegativeEdges) {
        reconstructPaths(startNode, parent, distance);
    }

    printf("Bellman end\n");
}

int hasNegativeEdgeCycles(int* distance) {
    // check for negative edge cycles;
    int u, v;

    for (u = 0; u < nrOfVerteces; u++) {
        for (v = 0; v < nrOfVerteces; v++) {
            if (u != v && adjMatrix[u][v]) {
                if (distance[u] + adjMatrix[u][v] < distance[v]) {
                    printf("Contains negative edge cycles");
                    return 1;
                }
            }
        }
    }

    return 0;
}

void reconstructPaths(int startNode, int* parent, int* distance) {
    int endNode, kNode;

    int* path = (int*) malloc((nrOfVerteces-1) * sizeof(int));
    int pathLen = 0, i; //path vars

    printf("StartNode : %d\n", startNode);

    for (endNode = 0; endNode < nrOfVerteces; endNode++) {
        if (endNode != startNode) {
            printf("Node : %d; Distance from startNode : %d\n", endNode, distance[endNode]);

            // clear previous path
            pathLen = 0;
            path[pathLen++] = endNode;

            // create new path
            kNode = endNode;
            while (parent[kNode] != kNode) {
                kNode = parent[kNode];
                path[pathLen++] = kNode;
            }

            // display path
            printf("Path : ");
            for (i = pathLen-1; i >= 0; i--) {
                printf("%d ", path[i]);
            }
            printf("\n\n");
        }
    }
}
