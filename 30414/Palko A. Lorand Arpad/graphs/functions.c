# include "functions.h"
# include "stack.h"
# include "queue.h"

void readMatrix(FILE *f)
{
    int n,i,j;
    fscanf(f,"%d",&n);
    nrOfVeritces=n;
    adjMatrix =(int**)malloc(n*sizeof(int*));
    for(i=0;i<n;i++)
        *(adjMatrix+i)=(int*)malloc(n*sizeof(int));
    for(i=0;i<n; i++)
        for(j=0;j<n;j++)
            fscanf(f,"%d",&adjMatrix[i][j]);
}

void printList()
{
    int i;
    NodeT *aux;
    for(i=0; i<nrOfVeritces; i++)
    {
        aux=listAdr[i];
        printf("%d-> ", i);
        while(aux!=NULL)
        {
            printf("%d",aux->content);
            aux=aux->next;
        }
        printf("\n");
    }
    printf("\n");
}

void addToList(int where, int node)
{
    NodeT *head=listAdr[where];
    NodeT *aux=(NodeT*)malloc(sizeof(NodeT));
    aux->content=node;
    if(head==NULL)
    {
        aux->next=NULL;
        listAdr[where]=aux;
    }
    else
    {
        while(head->next!=NULL)
            head=head->next;
        head->next=aux;
        aux->next=NULL;
    }
}

void printMatrix()
{
    int i,j;
    for(i=0;i<nrOfVeritces;i++)
    {
        for(j=0; j<nrOfVeritces; j++)
            printf("%d ",adjMatrix[i][j]);
        printf("\n");

    }
    printf("\n");
}

void createEmptyList()
{
    int i;
    listAdr=(NodeT**)malloc(nrOfVeritces*sizeof(NodeT*));
    for(i=0;i<nrOfVeritces;i++)
        listAdr[i]=NULL;

}

void deleteOldList()
{
    int i;
    if (listAdr == NULL)
        return;
    else
        for(i=0; i<nrOfVeritces; i++)
            free(listAdr[i]);
}

void matrixToList()
{
    int i, j;

    deleteOldList();
    createEmptyList();
    for(i=0; i<nrOfVeritces; i++)
        for(j=0; j<nrOfVeritces; j++)
            if(adjMatrix[i][j] == 1)
                addToList(i, j);
}

void deleteOldMatrix()
{
    int i;
    for(i=0; i<nrOfVeritces; i++)
        free(adjMatrix[i]);
}

void createEmptyMatrix()
{
    int i, j;
    for(i=0; i<nrOfVeritces; i++)
           adjMatrix[i]=(int*)malloc(nrOfVeritces*sizeof(int));
    for(i=0; i<nrOfVeritces; i++)
        for(j=0; j<nrOfVeritces; j++)
            adjMatrix[i][j] = 0;
}

void listToMatrix()
{
    int i;
    deleteOldMatrix();
    createEmptyMatrix();
    NodeT *aux;
    for(i=0; i<nrOfVeritces; i++)
    {
        aux=listAdr[i];
        while(aux!=NULL)
        {
            adjMatrix[i][aux->content]=1;
            aux=aux->next;
        }
    }

}

void addToQueue(NodeT *aux, int *visited)
{
    while(aux!= NULL)
    {
        if(!visited[aux->content])
            enqueue(aux->content);
        aux=aux->next;
    }
}

void bfsOnLists(int nod)
{
    int *visited =(int *) malloc (sizeof(int) * nrOfVeritces), v, i;
    NodeT *p;

    for(i = 0; i<nrOfVeritces; i++)
        visited[i] = UNVISITED;

    enqueue(nod);

    while(!isEmptyQueue())
    {
        p = peekQueue();
        v = p->content;
        visited[v] = VISITED;
        dequeue();
        addToQueue(listAdr[v], visited); //adaug toti vecinii in coada;
        printf("%d ", v);
    }
    printf("\n");
}

void addToStack(NodeT *p, int *visited)
{
    if(p==NULL)
        return;
    else
    {
        addToStack(p->next, visited);
        if(!visited[p->content])
            push(p->content);
    }
}

void dfsOnLists(int nod)
{
    int *visited =(int *) malloc (sizeof(int) * nrOfVeritces), v, i;
    NodeT *aux;

    for(i = 0; i<nrOfVeritces; i++)
        visited[i] = UNVISITED;

    push(nod);

    while(!isEmptyStack())
    {
        aux=peekStack();
        v=aux->content;
        visited[v]=VISITED;
        pop();
        addToStack(listAdr[v], visited);
        printf("%d ",v);
    }
    printf("\n");
}

int getNrOfNeighbours(int nod)
{
    int i,nr=0;
    for(i=0;i<nrOfVeritces;i++)
        if(adjMatrix[nod][i]==1)
            nr+=1;
    return nr-1;
}

int *getNeighbours(int nod, int *visited)
{
    int *nodes=(int*)malloc(getNrOfNeighbours(nod)*sizeof(int)),i,nr = 0;
    for(i=0;i<nrOfVeritces;i++)
    {
        if(adjMatrix[nod][i]==1&&visited[i]==0)
        {
            nodes[nr]=i;
            nr+=1;
        }
    }
    return nodes;
}


