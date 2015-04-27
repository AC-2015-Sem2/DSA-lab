#include <stdio.h>
#include <stdlib.h>

#include "graph.h"
#include "stack.h"
#include "queue.h"

//! representation



NodeT* addLast(int code, NodeT* head)
{
    if (head==NULL)
    {
        head=(struct node*)malloc(sizeof(struct node*));
        head->content=code;
        head->next=NULL;
    }
    else
    {
        NodeT* val=head;
        while (val->next!=NULL)
            val=val->next;
        struct node *p=(struct node*)malloc(sizeof(struct node*));
        p->content=code;
        p->next=NULL;
        val->next=p;
    }

    return head;
}

NodeT** CreateList(int** adjMatrix)
{
    int i,j;
    NodeT** v=(NodeT**)malloc(nrOfVerteces*sizeof(NodeT));
    for (i=0; i<=nrOfVerteces; i++)
        v[i]=0;

    for (i=0; i<nrOfVerteces; i++)
    {
        for(j=0; j<nrOfVerteces; j++)
            if (adjMatrix[i][j]==1)
                v[i]=addLast(j,v[i]);
    }
    return v;
}

int** createMatrix(NodeT** list)
{
    int i,j;
    int **matrix;
    matrix=(int**)malloc(nrOfVerteces*sizeof(int*));
    for (i=0; i<nrOfVerteces; i++)
    {
        *(matrix+i)=(int*)malloc(nrOfVerteces*sizeof(int));
    }
    for (i=0; i<nrOfVerteces; i++)
        for(j=0; j<nrOfVerteces; j++)
            matrix[i][j]=0;
    for (i=0; i<nrOfVerteces; i++)
    {
        NodeT *aux =list[i];
        while (aux!=NULL)
        {
            matrix[i][aux->content]=1;
            aux=aux->next;

        }
    }
    return matrix;
}



void printMatrix(int** matrix)
{
    int i,j;
    for(i=0; i<nrOfVerteces; i++)
    {
        for(j=0; j<nrOfVerteces; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
}

void printlist(NodeT* head)
{
    struct node *p=head;
    while (p!=NULL)
    {
        printf("%d ",p->content);
        p=p->next;
    }
    printf("\n");
}

void printAllList(NodeT** v)
{
    int i;
    for (i=0; i<=nrOfVerteces; i++)
    {
        printf("%d ",i);
        printlist(v[i]);


    }

}
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
    int c=0,i;
    for(i=0; i<nrOfVerteces; i++)
        if (adjMatrix[v][i]==1) c++;
    return c;
}

int * getAllNeighborsOfVertex(int v)
{
    int *a=(int*)malloc(sizeof(int)*nrOfVerteces);
    int i;
    int ct=0;
    for (i=0; i<nrOfVerteces; i++)
        if (adjMatrix[v][i]==1)
        {
            a[ct]=i;
            ct++;
        }
    return a;
}

//! traversals

void bfs(int searchNode)
{
    int mark[100];
    int i;
    for (i=0; i<100; i++)
        mark[i]=0;
    mark[searchNode]=1;
    printf("%d ",searchNode);
    enqueue(searchNode);
    while (!isEmptyQueue())
    {
        int v=peekQueue()->content;
        dequeue();
        int ct=getNumberOfNeighborsOfVertex(v);
        int *a=getAllNeighborsOfVertex(v);
        for (i=0; i<ct; i++)
            if (mark[a[i]]==0)
            {
                mark[a[i]]=1;
                enqueue(a[i]);
                printf("%d ",a[i]);
            }
    }
}



int getNumberOfNeighborsOfVertexList(int v,NodeT *adjList[nrOfVerteces])
{
    int ct=0;
    NodeT *node=adjList[v];
    while (node!=NULL)
    {
        ct++;
        node=node->next;
    }
    return ct;
}
int *getAllNeighborsOfVertexList(int v,NodeT *adjList[nrOfVerteces])
{
    int *a=(int*)malloc(sizeof(int)*nrOfVerteces);
    int i;
    int ct=0;
    NodeT *node=adjList[v];
    while (node!=NULL)
    {
        a[ct]=node->content;
        ct++;
        node=node->next;
    }
    return a;
}
void bfsList(int searchNode,NodeT *adjList[nrOfVerteces])
{
    int mark[nrOfVerteces];
    int i;
    for (i=0; i<nrOfVerteces; i++)
        mark[i]=0;
    mark[searchNode]=1;
    printf("%d ",searchNode);
    enqueue(searchNode);
    while (!isEmptyQueue())
    {
        int v=peekQueue()->content;
        dequeue();
        int ct=getNumberOfNeighborsOfVertexList(v,adjList);
        int *a=getAllNeighborsOfVertexList(v,adjList);
        for (i=0; i<ct; i++)
            if (mark[a[i]]==0)
            {
                mark[a[i]]=1;
                enqueue(a[i]);
                printf("%d ",a[i]);
            }
    }
}

void dfsList(int searchNode,NodeT *adjList[nrOfVerteces])
{
    printf("\n");
    int mark[100];
    int i;
    for (i=0; i<100; i++)
        mark[i]=0;
    push(searchNode);
    while (!isEmptyStack())
    {
        int v=peekStack()->content;
        pop();
        if (mark[v]==0)
        {
            mark[v]=1;
            int ct=getNumberOfNeighborsOfVertexList(v,adjList);
            int *a=getAllNeighborsOfVertexList(v,adjList);
            for (i=ct-1; i>=0; i--)
            {
                if (mark[a[i]]!=1)
                {
                    push(a[i]);
                }
            }
            printf("%d ",v);
        }
    }
}

void dfs(int searchNode)
{
    printf("\n");
    int mark[100];
    int i;
    for (i=0; i<100; i++)
        mark[i]=0;
    push(searchNode);
    while (!isEmptyStack())
    {
        int v=peekStack()->content;
        pop();
        if (mark[v]==0)
        {
            mark[v]=1;
            int ct=getNumberOfNeighborsOfVertex(v);
            int *a=getAllNeighborsOfVertex(v);
            for (i=ct-1; i>=0; i--)
            {
                if (mark[a[i]]!=1)
                {
                    push(a[i]);
                }
            }
            printf("%d ",v);
        }
    }
}
void dfsRec(int v, int * mark)
{

}

void dfsRecurs(int v)
{

}
