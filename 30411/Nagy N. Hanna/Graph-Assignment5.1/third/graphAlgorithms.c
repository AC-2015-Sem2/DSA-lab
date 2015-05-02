#include "graphAlgorithms.h"
#include "queue.h"
#include "representation.h"
#include "stack.h"

int getNumberOfNeighborsOfVertex(int v, nodeT** adjList)
{
    int n=0;
    nodeT* aux=adjList[v]->next;
    while(aux!=NULL)
    {
        n++;
        aux=aux->next;
    }
    return n;
}

int *getAllNeighborsOfVertex(int v, nodeT** adjList)
{
    int n=getNumberOfNeighborsOfVertex(v, adjList);
    int* a=(int*)malloc(n*sizeof(int));
    int i=0;
    nodeT* aux=adjList[v]->next;
    while(aux!=NULL)
    {
        a[i]=aux->code;
        i++;
        aux=aux->next;
    }
    return a;
}

void bfs(nodeT** adjList, int searchNode)
{
    int *Visited, *neighbors;
    nodeT *V;
    int i,nr,w;

    Visited = (int *)calloc(nrOfVerteces, sizeof(int));
    Visited[searchNode]=1;
    printf("%c, ", searchNode+65);
    enqueue(searchNode);
    while (!isEmptyQueue())
    {
        V=peekQueue();
        dequeue();
        neighbors=getAllNeighborsOfVertex(V->code, adjList);
        nr=getNumberOfNeighborsOfVertex(V->code, adjList);
        for (i=0; i<nr; i++)
        {
            w=neighbors[i];
            if (Visited[w]==0)
            {
                enqueue(w);
                Visited[w]=1;
                printf("%c, ",w+65);
            }
        }
    }
}

void dfs(nodeT** adjList, int searchNode)
{
    int *Visited, *neighbors;

    int i,nr,w, v;

    Visited = (int *)malloc(nrOfVerteces* sizeof(int));
    push(searchNode);
    while(!isEmptyStack())
    {
        v=peekStack()->code;
        pop();
        if(Visited[v]==0)
        {
            Visited[v]=1;
            neighbors=getAllNeighborsOfVertex(v, adjList);
            nr=getNumberOfNeighborsOfVertex(v, adjList);
            for(i=0; i<nr; i++)
            {
                w=neighbors[i];
                if(Visited[w]==0)
                    push(w);
            }
            printf("%c, ", v+65);
        }

    }
}

void dfsRec(int v, int * mark, nodeT** adjList)
{

    mark[v]=1;
    int nr=getNumberOfNeighborsOfVertex(v, adjList);
    int *neighbors=getAllNeighborsOfVertex(v, adjList);
    printf("%c, ", v+65);
    int i;
    for(i=0; i<nr; i++)
        {
            int w=neighbors[i];
            if(mark[w]==0)
                dfsRec(w, mark, adjList);
        }

}

void dfsRecurs( nodeT** adjList,int v)
{
    int* mark = (int *)malloc(nrOfVerteces* sizeof(int));
    dfsRec(v, mark, adjList);
}
