#include "graphAlgorithms.h"

int** getCopyOfAdjecencyMatrix(int** adjMat, int size)
{
    int i, j;
    int** copyAdjMat =(int**)malloc(sizeof(int*) * size);
    for(i = 0; i < size; i++)
    {
        *(copyAdjMat+i)=(int*)malloc(sizeof(int) * size);
        for(j = 0; j < size; j++)
        {
            copyAdjMat[i][j] = adjMat[i][j];
        }
    }
    return copyAdjMat;
}

edge extractMinEdge(int** adjMat, int size)
{
    int i, j;
    edge minEdge;
    minEdge.weight = -1;

    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            if(adjMat[i][j] > 0)
            {
                if(adjMat[i][j] < minEdge.weight || minEdge.weight == -1)
                {
                    minEdge.source = i;
                    minEdge.destination = j;
                    minEdge.weight = adjMat[i][j];
                }
            }
        }
    }
    ///Delete min edge form the matrix
    adjMat[minEdge.source][minEdge.destination] = 0;
    adjMat[minEdge.destination][minEdge.source] = 0;

    return minEdge;
}

int adjMatIsEmpty(int** adjMat, int size)
{
    int isEmpty = 1;

    int i, j;
    for(i = 0; i < size && isEmpty == 1; i++)
        for(j = 0; j < size && isEmpty == 1; j++)
            if(adjMat[i][j] > 0)
                isEmpty = 0;

    return isEmpty;
}

///Basically it the pseudocode from wiki if you consider treeComponent as a set family of all the sets
void kruskal(int** adjMat, int size)
{
    int i;
    int** adjMatAux = getCopyOfAdjecencyMatrix(adjMat, size);
    ///I use this to denote which connected subtree the node is in
    int* treeComponent = (int*)malloc(sizeof(int) * size);
    ///Every node is its own connected component
    for(i = 0; i < size; i++)
        treeComponent[i] = i;

    int minCost = 0;
    while(adjMatIsEmpty(adjMatAux, size) == 0)
    {
        edge minEdge = extractMinEdge(adjMatAux, size);
        ///Both belong to a different subtree
        if(treeComponent[minEdge.source] != treeComponent[minEdge.destination])
        {
            ///The other component will be marked with this value
            int priorityComponent = 0;
            ///The one with the smaller value will be the priority new component(it actually does not matter, could be any of them)
            if(treeComponent[minEdge.source] < treeComponent[minEdge.destination])
                priorityComponent = treeComponent[minEdge.source];
            else if(treeComponent[minEdge.source] > treeComponent[minEdge.destination])
                priorityComponent = treeComponent[minEdge.destination];
            ///The nodes marked with this value will change to being marked with priorityComponent
            int targetComponent = 0;
            ///If it isn't the first it surely is the second
            if(treeComponent[minEdge.source] == priorityComponent)
                targetComponent = treeComponent[minEdge.destination];
            else if(treeComponent[minEdge.destination] == priorityComponent)
                targetComponent = treeComponent[minEdge.source];
            ///Find & replace
            for(i = 0; i < size; i++)
                if(treeComponent[i] == targetComponent)
                    treeComponent[i] = priorityComponent;

            minCost += minEdge.weight;
            printf("%c <-> %c, ", minEdge.source + 65, minEdge.destination + 65);
        }
    }
    printf("\n%d\n", minCost);
}

void bellman_ford(int** adjMat, int size, int startingNode)
{
    int i;
    int minCost = 0;
    int* weight = (int*)malloc(sizeof(int) * size);
    int* parent = (int*)malloc(sizeof(int) * size);
    ///Initialization
    for(i = 0; i < size; i++)
    {
        weight[i] = 0;
        parent[i] = 0;
        if(i == startingNode)
        {
            weight[i] = 0;
            parent[i] = 42 - 65;
        }
        else
        {
            weight[i] = INT_MAX;
            parent[i] = 0;
        }
    }
    ///chill bro
    for(i = 0; i < size - 1; i++)
    {
        int i1;
        int j1;
        for(i1 = 0; i1 < size; i1++)
        {
            for(j1 = 0; j1 < size; j1++)
            {
                if(adjMat[i1][j1] > 0)
                {
                    if(weight[i1] + adjMat[i1][j1] < weight[j1])
                    {
                        weight[j1] = weight[i1] + adjMat[i1][j1];
                        parent[j1] = i1;
                    }
                }
            }
        }
    }
    ///Calculate the minCost
    for(i = 0; i < size; i++)
        if(i != startingNode)
            minCost += adjMat[i][parent[i]];

    for(i = 0; i < size; i++)
    {
        printf("%c -> %c, ", parent[i] + 65, i + 65);
    }
    printf("\n%d\n", minCost);
}
