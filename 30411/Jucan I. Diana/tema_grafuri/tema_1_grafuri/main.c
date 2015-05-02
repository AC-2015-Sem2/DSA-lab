#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

struct AdjListNode
{
    int dest;
    struct AdjListNode* next;
};

struct AdjList
{
    struct AdjListNode *head;  // pointer to head node of list
};
struct Graph
{
    int V;
    struct AdjList* array;
};

struct AdjListNode* newAdjListNode(int dest)
{
    struct AdjListNode* newNode =
        (struct AdjListNode*) malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int V)
{
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->V = V;

    // Create an array of adjacency lists.  Size of array will be V
    graph->array = (struct AdjList*) malloc(V * sizeof(struct AdjList));

    // Initialize each adjacency list as empty by making head as NULL
    int i;
    for (i = 1; i <= V; i++)
        graph->array[i].head = NULL;

    return graph;
}
void addEdge(struct Graph* graph, int src, int dest)
{
    // Add an edge from src to dest.  A new node is added to the adjacency
    // list of src.  The node is added at the begining
    struct AdjListNode* newNode = newAdjListNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
}
void printGraph(struct Graph* graph) // print the adjency list
{
    int v;
    for (v = 1; v <= graph->V; ++v)
    {
        struct AdjListNode* pCrawl = graph->array[v].head;
        printf("\n Adjacency list of vertex %d\n head ", v);
        while (pCrawl)
        {
            printf("-> %d", pCrawl->dest);
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }
}
void FromMatrixToList(struct Graph* graph)
{
    int i,j;
    for(i=1; i<=nrOfVerteces; i++)
        for(j=1; j<=nrOfVerteces; j++)
            if(adjMatrix[i][j]==1)
            addEdge(graph,i,j);
}

int main()
{
    FILE * f = fopen("matrix.txt","r");
    readFromAdjMatrix(f);
    int V;
    printf("give the number of vertices of the graph:\n");
    scanf("%d",&V);
    struct Graph* graph = createGraph(V);
    FromMatrixToList(graph);
    printGraph(graph);
    createAdjList(adjMatrix);
    int** newAdjMatr = ListToMatrix(adjList, adjListlength);
   printAdjMatrix(newAdjMatr);

    return 0;
}
