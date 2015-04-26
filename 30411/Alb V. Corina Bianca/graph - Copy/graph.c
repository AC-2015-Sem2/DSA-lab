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

void printAdjMatrix()
{
    int i,j;

    printf("\nThe matrix is:\n");
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

int getNumberOfNeighborsOfVertex(int v)
{
    int nr=0,i;
    for (i=0;i<nrOfVerteces;i++)
        nr=nr+adjMatrix[i][v];
    return nr;
}

int * getAllNeighborsOfVertex(int v)
{
    int nrOfNeighbors=getNumberOfNeighborsOfVertex(v);
    int *allNeighbors=(int*)malloc(nrOfNeighbors*sizeof(int));
    int i,j=0;
    for(i=0;i<nrOfVerteces;i++){
        if(adjMatrix[i][v]==1) *(allNeighbors+j)=i;
        j++;
    }
    return allNeighbors;
}

//! traversals

void bfs(int searchNode)
{
    int *mark=(int*)malloc(nrOfVerteces*sizeof(int));
    int i;
    for (i=0;i<nrOfVerteces;i++)
       mark[i]=UNVISITED;
    mark[searchNode]=VISITED;
    enqueue(searchNode);
    printf("%d ",searchNode);
    while(!isEmptyQueue()){
        int v=(int)peekQueue();
        dequeue();
        int *neighbors=getAllNeighborsOfVertex(v);
        int nr=getNumberOfNeighborsOfVertex(v);
        for(i=0;i<nr;i++){
            if (mark[neighbors[i]]==UNVISITED){
                enqueue(neighbors[i]);
                mark[neighbors[i]]=VISITED;
                printf("%d",neighbors[i]);
            }
        }
    }
}

struct adjlistnodes{
    int data;
    struct adjlistnodes* next;
};

struct adjlist{
    struct adjlistnodes * head;
};

struct adjgraph {
    int v;
    struct adjlist *array;
};

struct adjlistnodes * addnode(int data){
    struct adjlistnodes *newnode=(struct adjlistnodes*)malloc(sizeof(struct adjlistnodes));
    newnode->data=data;
    newnode->next=NULL;
    return newnode;
}

struct adjgraph * creategraph(int v){
    struct adjgraph *graph=(struct adjgraph*)malloc(sizeof(struct adjgraph));
    graph->v=v;
    graph->array=(struct adjlist*)malloc(sizeof(struct adjlist)*v);
    int i;
    for(i=0;i<v;i++)
        graph->array[i].head=NULL;
    return graph;
}

void addedge(struct adjgraph * graph , int src, int data){
    struct adjlistnodes *newnode=addnode(data);
    newnode->next=graph->array[src].head;
    graph->array[src].head=newnode;

    newnode=addnode(src);
    newnode->next=graph->array[data].head;
    graph->array[data].head=newnode;
}

void printgraph(struct adjgraph *graph){
    int i;
    for(i=0;i<graph->v;i++){
        struct adjlistnodes *p=graph->array[i].head;
        printf("adjacency list of vertex %d \n : ",i);
        while(p){
            printf(" -> %d",p->data);
            p=p->next;
        }
        printf("\n");
    }
}


void createadjmatrix(int n){
    adjmatrix=(int**)malloc(n*sizeof(int*));
    int i,j;
    for (i=0; i<n; i++)
    {
        *(adjmatrix+i)=(int*)malloc(n*sizeof(int));
    }
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            adjmatrix[i][j]=0;
}

void matrix(struct adjlist *graph, int n){
    while(graph->head){
        adjmatrix[n][graph->head->data]=1;
        graph->head=graph->head->next;
    }
}

void dfs(int searchNode)
{
    push(searchNode);
    int *mark=(int*)malloc(nrOfVerteces*sizeof(int));
    int i;
    for(i=0;i<nrOfVerteces;i++)
        mark[i]=UNVISITED;
    while (!isEmptyStack()){
        int v=(int)peekStack();
        pop();

        if (mark[v] == UNVISITED){
            int *neighbor=getAllNeighborsOfVertex(v);
            int nr=getNumberOfNeighborsOfVertex(v);
            mark[v]=VISITED;
            int i;
            for(i=0;i<nr;i++)
                if (mark[neighbor[i]]==UNVISITED)
                    push (neighbor[i]);
        printf("%d ",v);
    }
}
}

void dfsRec(int v, int * mark)
{
    mark[v]=VISITED;
    int nrOfNeighbors=getNumberOfNeighborsOfVertex(v);
    int *neighbors=getAllNeighborsOfVertex(v);
    printf("%d ",v);
    int i;
    for (i=nrOfNeighbors-1; i>=0; i--) {
        if (mark[neighbors[i]]==UNVISITED)
            dfsRec(v,mark);
    }
}

void dfsRecurs(int v){
    int *mark=(int*)malloc(sizeof(int)*nrOfVerteces);
    int i;
    for (i=0;i<nrOfVerteces;i++)
        mark[i]=UNVISITED;
    dfsRec(v,mark);
}
