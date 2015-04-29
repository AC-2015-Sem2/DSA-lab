#include "graph.h"
#include "node.h"
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "stack.h"
NodeT** adjList;

void addLast(NodeT **vertexList,int adjVertex)
{

    if((*vertexList )== NULL)
    {
        (*vertexList) = createNode(adjVertex);
    }
    else
    {
        NodeT * aux =(*vertexList) ;
        while(aux->next!=NULL)
        {
            aux=aux->next;
        }

        aux->next=createNode(adjVertex);
    }


}

/*****From Matrix to adjacency list*****/
NodeT **adjacencyList(int nrOfVerteces,int** adjMatrix)
{

    int i,j;
    adjList=(NodeT**)malloc(nrOfVerteces*sizeof(NodeT));

    for (i=0; i<nrOfVerteces; i++)
    {
        adjList[i]=NULL;
        for (j=0; j<nrOfVerteces; j++)
        {
            if (adjMatrix[i][j]==1)   addLast(&adjList[i],j);
        }
    }
    return adjList;
}
/****Function that prints a list knowing its head****/
void printAll(NodeT *list)
{
    NodeT *p=list;

    while (p!=NULL)
    {
        printf("%d ",p->content);
        p=p->next;
    }
    printf("\n");
}


int getNumberOfNeighborsOfVertexFromList(int v)
{
    int nr=0;
    NodeT* p=adjList[v];
    while (p!=NULL)
    {
        nr++;
        p=p->next;
    }
    return nr;
}

int* getAllNeighborsOfVertexFromList(int v)
{
    int i=0;
    int *aux=(int *)malloc(getNumberOfNeighborsOfVertexFromList(v)*sizeof(int));
    NodeT* p=adjList[v];
    while (p!=NULL)
    {
        aux[i]=p->content;
        i++;
        p=p->next;
    }
    return aux;
}
/***Bfs for adjacency list***/

void bfsList(int searchNode)
{
    int* visited=(int*)malloc(nrOfVerteces*sizeof(int));
    int i;
    int v;
    int n;
    int w;
    for (i=0; i<nrOfVerteces; i++)
        visited[i]=UNVISITED;
    visited[searchNode]=VISITED;
    enqueue(searchNode);
    printf("%d ",searchNode);
    while (!isEmptyQueue())
    {
        v=peekQueue()->content;
        dequeue();
        int* aux=(int*) malloc(getNumberOfNeighborsOfVertexFromList(v)*sizeof(int));
        aux=getAllNeighborsOfVertexFromList(v);
        n=getNumberOfNeighborsOfVertexFromList(v);
        for (w=0; w<n; w++)
        {
            if (visited[aux[w]]==UNVISITED)
            {
                visited[aux[w]]=VISITED;
                enqueue(aux[w]);
                printf("%d ",aux[w]);
            }
        }
    }
}

/***Dfs for adjacency list***/

void dfsList(int searchNode)
{
    int i;
    int v;
    int w;


    int *visited=(int*)malloc(nrOfVerteces*sizeof(int));
    for (i=0; i<nrOfVerteces; i++)
        visited[i]=UNVISITED;
    push(searchNode);
    while (! isEmptyStack())
    {
        v=peekStack()->content;
        pop();
        int *aux=(int*) malloc(getNumberOfNeighborsOfVertexFromList(v)*sizeof(int));
        aux=getAllNeighborsOfVertexFromList(v);
        if (visited[v]==UNVISITED)
        {
            visited[v]=VISITED;
            for (w=getNumberOfNeighborsOfVertexFromList(v)-1; w>=0; w--)
                if (visited[aux[w]]==UNVISITED)
                    push(aux[w]);
            printf(" %d",v);
        }
    }
}
/***Function that creates the adjacency Matrix from the adjacency list***/
int** adjacencyMatrix(NodeT** adjList)
{
    int i,j;
    int n=nrOfVerteces;
    adjMatrix=(int**)malloc(n*sizeof(int*));
    for (i=0; i<n; i++)
    {
        *(adjMatrix+i)=(int*)malloc(n*sizeof(int));
    }
    for (i=0; i<n; i++)
        for(j=0; j<n; j++)
            adjMatrix[i][j]=0;
    for (i=0; i<n; i++)
    {
        NodeT* p=adjList[i];
        while (p!=NULL)
        {
            adjMatrix[i][p->content]=1;
            p=p->next;
        }
    }
    return adjMatrix;
}

