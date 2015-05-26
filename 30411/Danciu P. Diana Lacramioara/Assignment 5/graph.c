#include <stdio.h>
#include <stdlib.h>

#include "graph.h"
#include "stack.h"
#include "queue.h"

//! representation

void readFromAdjMatrix(FILE * f)
{
    int n;
    fscanf(f,"%d",&n);
    nrOfVerteces=n;
    int i,j;
    adjMatrix=(int**)malloc(n*sizeof(int*));
    for (i=0; i<n; i++)
    {
        *(adjMatrix+i)=(int*)malloc(n*sizeof(int));
    }

    for (i=0; i<n; i++)
        for (j=0; j<n; j++)
            fscanf(f,"%d",&adjMatrix[i][j]);
    fclose(f);
}

NodeT **fromMatrixtoList(int **adjMatrix) //from Adjacency Matrix to Adjacency List
{
    int i, j;

    NodeT **adjList;
    NodeT *aux;

    adjList = (NodeT**)calloc(nrOfVerteces, sizeof(NodeT*)); //set the memory to null with calloc

    for (i=0; i<nrOfVerteces; i++)
    {
        adjList[i]=(NodeT*)calloc(nrOfVerteces, sizeof(NodeT)); //set all the values to null with calloc
        adjList[i]->content=i;
        aux=adjList[i];
        for (j=0; j<nrOfVerteces; j++)
        {
            if (adjMatrix[i][j] == VISITED)
            {
                aux->next = createNode(j);
                aux=aux->next;
            }
        }
    }
    return(adjList);
}

int **fromListtoMatrix(NodeT **adjlist) //from adjacency List to adjacenc Matrix
{
    int i;
    NodeT *aux;
    int **matrix;

    matrix = (int **)calloc(nrOfVerteces, sizeof(int*));
    for (i=0; i<nrOfVerteces; i++)
    {
        matrix[i]=(int *)calloc(nrOfVerteces, sizeof(int));
    }
    aux = (NodeT *)calloc(1, sizeof(NodeT));

    for (i=0; i<nrOfVerteces; i++)
    {
        aux=adjlist[i];
        aux=aux->next;
        while (aux != NULL)
        {
            matrix[i][aux->content] = 1;
            aux= aux->next;
        }
    }
    return(matrix);
}

void printAdjMatrix()
{
    int i,j;

    printf("    ");
    for (i=0; i<nrOfVerteces; i++)
    {
        printf("%c   ",65+i);
    }
    printf("\n");
    for (i=0; i<nrOfVerteces; i++)
    {
        printf("%c ",65+i);
        for (j=0; j<nrOfVerteces; j++)
            printf("%3d ",adjMatrix[i][j]);
        printf("\n");
    }
}

void printAdjList(NodeT **adjList)  //print the adjacency list of the graph
{
    int i;

    NodeT *aux;

    aux = (NodeT *)calloc(1,sizeof(NodeT));

    for (i=0; i<nrOfVerteces; i++)
    {
        printf("Node %d has the the following adjacent nodes : ", i);
        aux=adjList[i];
        aux=aux->next;
        while (aux != NULL)
        {
            printf("%d ", aux->content);
            aux=aux->next;
        }
        printf("\n");
    }
}

int getNumberOfNeighborsOfVertex(int v)
{
    int i, nr;

    nr=0;
    for (i=0; i<nrOfVerteces; i++)
    {
        if (adjMatrix[v][i] == VISITED)
            nr++;
    }
    return(nr);
}

int *getAllNeighborsOfVertex(int v)
{
    int *c;
    int nr,j,i;

    nr = getNumberOfNeighborsOfVertex(v);
    c = (int *)malloc(sizeof(int)*nr);
    j=0;
    for (i=0; i<nrOfVerteces; i++)
    {
        if (adjMatrix[v][i] == VISITED)
        {
            c[j]=i;
            j++;
        }
    }
    return(c);
}

//! traversals

void bfs(int searchNode)
{
    int *Visited, *neighbors;
    NodeT *V;
    int i,nr,w;

    Visited = (int *)calloc(nrOfVerteces, sizeof(int));
    Visited[searchNode]=VISITED;
    printf("%d ", searchNode);
    enqueue(searchNode);
    while (!isEmptyQueue())
    {
        V=peekQueue();
        dequeue();
        neighbors=getAllNeighborsOfVertex(V->content);
        nr=getNumberOfNeighborsOfVertex(V->content);
        for (i=0; i<nr; i++)
        {
            w=neighbors[i];
            if (Visited[w]==UNVISITED)
            {
                enqueue(w);
                Visited[w]=VISITED;
                printf("%d ",w);
            }
        }
    }
}

void dfs(int searchNode)
{
    int *Visited, *neighbors;
    int v,i,w,nr_neigh;

    Visited = (int *)calloc(nrOfVerteces, sizeof(int));
    push(searchNode);
    while (!isEmptyStack())
    {
        v=peekStack()->content;
        pop();
        if (Visited[v]==UNVISITED)
        {
            Visited[v] = VISITED;
            neighbors = getAllNeighborsOfVertex(v);
            nr_neigh=getNumberOfNeighborsOfVertex(v);
            for (i=nr_neigh-1; i>=0; i--)
            {
                w=neighbors[i];
                if (Visited[w] == UNVISITED)
                    push(w);
            }
            printf("%d ", v);
        }
    }
}

void dfsRec(int v, int *mark)
{
    int i;
    mark[v]=VISITED;
    int nrofNeigh=getNumberOfNeighborsOfVertex(v);
    int *neighbors = getAllNeighborsOfVertex(v);
    printf("%d ", v);
    for (i=0; i<nrofNeigh; i++)
    {
        int w = neighbors[i];
        if (mark[w] ==UNVISITED)
            dfsRec(w,mark);
    }
}

void dfsRecurs(int v)
{
    int *Visited;

    Visited = (int *)calloc(nrOfVerteces, sizeof(int));
    dfsRec(v, Visited);
}

int getNumberOfNeighborsOfVertexfromList(int v, NodeT **adjList) //function get number of neighbors of vertex using adjacency list
{
    int nr;
    NodeT *aux;
    nr=0;

    aux = (NodeT *)calloc(1, sizeof(NodeT));

    aux = adjList[v];
    aux=aux->next;
    while (aux!=NULL)
    {
        nr++;
        aux=aux->next;
    }
    return(nr);
}

int *getAllNeighborsOfVertexFromList(int v, NodeT **adjList) ////function get the neighbors of vertex using adjacency list
{
    int *c;
    int nr,j;
    NodeT *aux;

    nr = getNumberOfNeighborsOfVertexfromList(v, adjList);
    c = (int *)malloc(sizeof(int)*nr);
    aux = (NodeT*)calloc(1, sizeof(NodeT));
    aux = adjList[v];
    aux=aux->next;
    j=0;
    while (aux != NULL)
    {
        c[j]=aux->content;
        j++;
        aux=aux->next;
    }
    return(c);
}

void bfsList(int searchNode, NodeT **adjList) //bfs using adjacency list
{
    int *Visited, *neighbors;
    NodeT *V;
    int i,nr,w;

    Visited = (int *)calloc(nrOfVerteces, sizeof(int));
    Visited[searchNode]=VISITED;
    printf("%d ", searchNode);
    enqueue(searchNode);
    while (!isEmptyQueue())
    {
        V=peekQueue();
        dequeue();
        neighbors=getAllNeighborsOfVertexFromList(V->content, adjList);
        nr=getNumberOfNeighborsOfVertexfromList(V->content, adjList);
        for (i=0; i<nr; i++)
        {
            w=neighbors[i];
            if (Visited[w]==UNVISITED)
            {
                enqueue(w);
                Visited[w]=VISITED;
                printf("%d ",w);
            }
        }
    }
}

void dfsList(int searchNode, NodeT **adjList) //dfs using adjacency list
{
    int *Visited, *neighbors;
    int v,i,w,nr_neigh;

    Visited = (int *)calloc(nrOfVerteces, sizeof(int));
    push(searchNode);
    while (!isEmptyStack())
    {
        v=peekStack()->content;
        pop();
        if (Visited[v]==UNVISITED)
        {
            Visited[v] = VISITED;
            neighbors = getAllNeighborsOfVertexFromList(v, adjList);
            nr_neigh=getNumberOfNeighborsOfVertexfromList(v,adjList);
            for (i=nr_neigh-1; i>=0; i--)
            {
                w=neighbors[i];
                if (Visited[w] == UNVISITED)
                    push(w);
            }
            printf("%d ", v);
        }
    }
}

void dfsRecList(int v, int *mark, NodeT **adjList)  //dfs rec using adjacency list
{
    int i;
    mark[v]=VISITED;
    int nrofNeigh=getNumberOfNeighborsOfVertexfromList(v,adjList);
    int *neighbors = getAllNeighborsOfVertexFromList(v, adjList);
    printf("%d ", v);
    for (i=0; i<nrofNeigh; i++)
    {
        int w = neighbors[i];
        if (mark[w] == UNVISITED)
            dfsRec(w,mark);
    }
}

void dfsRecursList(int v, NodeT **adjList)
{
    int *Visited;

    Visited = (int *)calloc(nrOfVerteces, sizeof(int));
    dfsRecList(v, Visited, adjList);
}
