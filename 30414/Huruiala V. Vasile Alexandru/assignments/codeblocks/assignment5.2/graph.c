#include "graph.h"

/// I/O
void readAdjMatrix(FILE * f, int* size, int*** mat)
{
    fscanf(f, "%d", size);
    int i, j;
    int** adjMat = (int**)malloc((*size)*sizeof(int*));
    for(i = 0; i < *size; i++)
    {
        *(adjMat + i) = (int*)malloc((*size)*sizeof(int));
    }
    for(i = 0; i < *size; i++)
        for(j = 0; j < *size; j++)
            fscanf(f, "%d", &adjMat[i][j]);

    *mat = adjMat;
}

void printAdjMatrix(int size, int** mat)
{
    int i,j;

    printf("\nThe matrix is:\n");
    printf("    ");
    for (i=0; i<size; i++)
    {
        printf("%c   ",65+i);
    }
    printf("\n");
    for (i=0; i<size; i++)
    {
        printf("%c ",65+i);
        for (j=0; j<size; j++)
            printf("%3d ", mat[i][j]);
        printf("\n");
    }
}

/// Adjacency matrix to lists

node** AdjMatToAdjList(int** mat, int size)
{
    ///The vector of nodes will be the heads of the lists
    node** AdjList = (node**)malloc(sizeof(node*) * size);
    int i;
    for(i = 0; i < size; i++)
    {
        *(AdjList + i) = NULL;
    }
    ///This will be for the tails of the lists(so enqueueue can be used)
    node** AdjListTail = (node**)malloc(sizeof(node*) * size);
    for(i = 0; i < size; i++)
        *(AdjListTail + i) = NULL;

    int j;
    for(i = 0; i < size; i++)
    {
        for(j = 0; j < size; j++)
        {
            if(mat[i][j] == 1)
            {
                int firstNode;
                enq(&AdjListTail[i], j, &firstNode);
                if(firstNode == 1)
                    AdjList[i] = AdjListTail[i];
            }
        }
    }
    return AdjList;
}

void printAdjList(node** adjList, int size)
{
    int i;
    for(i = 0; i < size; i++)
    {
        printf("%d: ", i);
        printQ(adjList[i]);
    }
}

///Longest path algorithm

///This is the recursive dfs traverse with a modification that
///that allows it to through every single path that starts from startingNode
void longestPathRecMat(int v, int vfinal, int* visited,
                       int* pathSoFar, int pathLengthSoFar, int* maxPath, int* maxPathLength,
                       int** mat, int size)
{
    if(visited[v] == UNVISITED)
    {
        int i;
        if(v == vfinal)
        {
            if(pathLengthSoFar + 1> *maxPathLength)
            {
                *maxPathLength = pathLengthSoFar;
                for(i = 0; i < *maxPathLength; i++)
                    maxPath[i] = pathSoFar[i];
                maxPath[*maxPathLength] = v;
                (*maxPathLength)++;
            }
        }
        visited[v] = VISITED;
        pathSoFar[pathLengthSoFar] = v;
        for(i = 0; i < size; i++)
            if(mat[v][i] == 1)
                longestPathRecMat(i, vfinal, visited,
                                  pathSoFar, pathLengthSoFar + 1, maxPath, maxPathLength,
                                  mat, size);
        ///By un-visiting the current node after leaving it
        ///we are able to revisit it in another path
        visited[v] = UNVISITED;
    }
}

void longestPathMat(int startingNode, int endingNode, int** mat, int size)
{
    int* visited = (int*)malloc(sizeof(int) * size);
    int i;
    for(i = 0; i < size; i++)
        visited[i] = UNVISITED;

    int* pathSoFar = (int*)malloc(sizeof(int) * size);
    for(i = 0; i < size; i++)
        pathSoFar[i] = 0;

    int* maxPath = (int*)malloc(sizeof(int) * size);
    for(i = 0; i < size; i++)
        maxPath[i] = 0;
    int maxPathLength = 0;

    longestPathRecMat(startingNode, endingNode, visited, pathSoFar, 0, maxPath, &maxPathLength, mat, size);

    for(i = 0; i < maxPathLength; i++)
                printf("%d ", maxPath[i]);
    printf("\n");

    free(visited);
    free(pathSoFar);
    free(maxPath);
}
///This is for lists
void longestPathRecLst(int v, int vfinal, int* visited,
                       int* pathSoFar, int pathLengthSoFar, int* maxPath, int* maxPathLength,
                       node** lst, int size)
{
    if(visited[v] == UNVISITED)
    {
        int i;
        if(v == vfinal)
        {
            if(pathLengthSoFar + 1> *maxPathLength)
            {
                *maxPathLength = pathLengthSoFar;
                for(i = 0; i < *maxPathLength; i++)
                    maxPath[i] = pathSoFar[i];
                maxPath[*maxPathLength] = v;
                (*maxPathLength)++;
            }
        }
        visited[v] = VISITED;
        pathSoFar[pathLengthSoFar] = v;

        node* aux = lst[v];
        while(aux != NULL)
        {
            longestPathRecLst(aux->data, vfinal, visited,
                                pathSoFar, pathLengthSoFar + 1, maxPath, maxPathLength,
                                lst, size);
            aux = aux->next;
        }

        visited[v] = UNVISITED;
    }
}

void longestPathLst(int startingNode, int endingNode, node** lst, int size)
{
    int* visited = (int*)malloc(sizeof(int) * size);
    int i;
    for(i = 0; i < size; i++)
        visited[i] = UNVISITED;

    int* pathSoFar = (int*)malloc(sizeof(int) * size);
    for(i = 0; i < size; i++)
        pathSoFar[i] = 0;

    int* maxPath = (int*)malloc(sizeof(int) * size);
    for(i = 0; i < size; i++)
        maxPath[i] = 0;
    int maxPathLength = 0;

    longestPathRecLst(startingNode, endingNode, visited, pathSoFar, 0, maxPath, &maxPathLength, lst, size);

    for(i = 0; i < maxPathLength; i++)
                printf("%d ", maxPath[i]);
    printf("\n");

    free(visited);
    free(pathSoFar);
    free(maxPath);
}
