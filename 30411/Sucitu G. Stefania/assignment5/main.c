#include "graphRepresentation.h"
#include "graphTraversals.h"
#include "queue.h"
#include "stack.h"
#include "graph.h"
NodeT* addLast(NodeT *head,int code)
{
    if (head==NULL)
    {
        head=(struct node*)malloc(sizeof(struct node*));
        head->content=code;
        head->next=NULL;
    }
    else
    {
        NodeT *aux=head;
        while (aux->next!=NULL)
            aux=aux->next;
        struct node *p=(struct node*)malloc(sizeof(struct node*));
        p->content=code;
        p->next=NULL;
        aux->next=p;
    }
    return head;
}
NodeT **createAdjList()
{
    int i,j,k,n;
    NodeT **adjArray;
    adjArray=(NodeT**)malloc(sizeof(NodeT)*nrOfVerteces);
    n=nrOfVerteces;
    for(k=0; k<n; k++)
        adjArray[k] = 0;
    for(i=0; i<n; i++)
    {
        for( j=0; j<n; j++)
            if(adjMatrix[i][j] == 1)
                adjArray[i]=addLast(adjArray[i],j);
    }

    return adjArray;
}
void printAdjList(NodeT *adjList[nrOfVerteces])
{
    int j;
    for(j=0; j<nrOfVerteces; j++)
    {
        printf("%d ",j);
        NodeT *node=adjList[j];
        while (node!=NULL)
        {
            printf("%d ",node->content);
            node=node->next;
        }
        printf("\n");
    }
}

void createAdjMatrix(NodeT *adjList[nrOfVerteces])
{
    int i,j;
    for (i=0; i<nrOfVerteces; i++)
        for (j=0; j<nrOfVerteces; j++)
            adjMatrix[i][j]=0;
    for (i=0; i<nrOfVerteces; i++)
    {
        NodeT* node=adjList[i];
        while (node!=NULL)
        {
            adjMatrix[i][node->content]=1;
            node=node->next;
        }
    }
}
int NrOfNeighList(int v,NodeT *adjList[nrOfVerteces])
{
    int number=0;
    NodeT *node=adjList[v];
    while (node!=NULL)
    {
        number++;
        node=node->next;
    }
    return number;
}
int allNeighList(int v, NodeT *adjList[nrOfVerteces])
{
    int *all=(int*)malloc(sizeof(int)*nrOfVerteces);
    int number=0;
    NodeT *node=adjList[v];
    while (node!=NULL)
    {
        all[number]=node->content;
        number++;
        node=node->next;
    }
    return all;
}
void bfsList(int startnode,NodeT *adjList[nrOfVerteces])
{
    int mark[nrOfVerteces];
    int i;
    for (i=0; i<nrOfVerteces; i++)
        mark[i]=UNVISITED;
    mark[startnode]=VISITED;
    printf("%d",startnode);
    enqueue(startnode);

    while (!isEmptyQueue())
    {
        int v=peekQueue()->content;
        dequeue();
        int n=NrOfNeighList(v,adjList);
        int *all=allNeighList(v,adjList);
        for (i=0; i<n; i++)
            if (mark[all[i]]==UNVISITED)
            {
                mark[all[i]]=VISITED;
                enqueue(all[i]);
                printf("%d",all[i]);
            }
    }
}

void dfsList(int startnode,NodeT *adjList[nrOfVerteces])
{
    int *mark=(int*)malloc(nrOfVerteces*sizeof(int));
    int i;
    for (i=0; i<nrOfVerteces; i++)
        mark[i]=UNVISITED;
    push(startnode);

    while (!isEmptyStack())
    {
        int v=peekStack()->content;
        pop();
        if (mark[v]==UNVISITED)
        {
            mark[v]=VISITED;
            int n=NrOfNeighList(v,adjList);
            int *all=allNeighList(v,adjList);
            for(i=n-1; i>=0; i-- )
            {
                if (mark[all[i]]==UNVISITED)
                {
                    push(all[i]);
                }
            }
            printf("%d", v);
        }
    }
}
int main()
{
    FILE * f = fopen("matrix.txt","r");
    readFromAdjMatrix(f);
    printAdjMatrix();
    bfs(0);
    dfs(0);
    printf("\n");
    NodeT **adjList;
    adjList=createAdjList();
    printAdjList(adjList);
    createAdjMatrix(adjList);
    printAdjMatrix();
    printf("\n");
    bfsList(0,adjList);
    printf("\n");
    dfsList(0,adjList);
    return 0;
}
