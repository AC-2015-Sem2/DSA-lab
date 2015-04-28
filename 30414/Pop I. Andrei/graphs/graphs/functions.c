# include "functions.h"
# include "stack.h"
# include "queue.h"

void readMatrix(FILE *in)
{
    int n, i, j;
    fscanf(in, "%d", &n);
    nrOfVeritces = n;
    adjMatrix = (int**) malloc(n*sizeof(int*));

    for(i=0; i<n; i++)
    {
        *(adjMatrix+i) = (int*) malloc (n*sizeof(int));
    }

    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            fscanf(in, "%d", &adjMatrix[i][j]);
}

void printList()
{
    int i;
    NodeT *p;
    for(i=0; i<nrOfVeritces; i++)
    {
        p = listAdr[i];
        printf("%d-> ", i);
        while(p!=NULL)
        {
            printf("%d ", p->content);
            p=p->next;
        }
        printf("\n");
    }
    printf("\n");
}

void addToList(int where, int node)
{
    NodeT * head = listAdr[where];

    NodeT *p = (NodeT*) malloc (sizeof(NodeT));
    p->content = node;

    if(head == NULL)
    {
        p->next = NULL;
        listAdr[where] = p;
    }
    else
    {
        while(head->next!=NULL)
            head = head->next;
        head->next = p;
        p->next = NULL;
    }
}

void printMatrix()
{
    int i, j;
    for(i=0; i<nrOfVeritces; i++)
    {
        for(j=0; j<nrOfVeritces; j++)
            printf("%d ", adjMatrix[i][j]);
        printf("\n");

    }
    printf("\n");
}

void createEmptyList()
{
    int i;
    listAdr = (NodeT**) malloc (nrOfVeritces * sizeof(NodeT*));

    for(i=0; i<nrOfVeritces; i++)
        listAdr[i] = NULL;

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
    {
        free(adjMatrix[i]);
    }
}

void createEmptyMatrix()
{
    int i, j;

    for(i=0; i<nrOfVeritces; i++)
    {
        adjMatrix[i] = (int*) malloc (nrOfVeritces * sizeof(int));
    }

    for(i=0; i<nrOfVeritces; i++)
        for(j=0; j<nrOfVeritces; j++)
            adjMatrix[i][j] = 0;
}

void listToMatrix()
{
    int i;

    deleteOldMatrix();
    createEmptyMatrix();

    NodeT *p;

    for(i=0; i<nrOfVeritces; i++)
    {
        p=listAdr[i];
        while(p!=NULL)
        {
            adjMatrix[i][p->content] = 1;
            p=p->next;
        }
    }

}

void addToQueue(NodeT *p, int *visited)
{
    while(p != NULL)
    {
        if(!visited[p->content])
            enqueue(p->content);
        p = p->next;
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
    NodeT *p;

    for(i = 0; i<nrOfVeritces; i++)
        visited[i] = UNVISITED;

    push(nod);

    while(!isEmptyStack())
    {
        p = peekStack();
        v = p->content;
        visited[v] = VISITED;
        pop();
        addToStack(listAdr[v], visited);
        printf("%d ", v);
    }
    printf("\n");
}

int getNrOfNeighbours(int nod)
{
    int i, nr = 0;
    for(i=0; i<nrOfVeritces; i++)
        if(adjMatrix[nod][i] == 1)
            nr+=1;

    return nr-1;
}

int *getNeighbours(int nod, int *visited)
{
    int *nodes = (int*) malloc (getNrOfNeighbours(nod) * sizeof(int)), i, nr = 0;
    for(i=0; i<nrOfVeritces; i++)
    {
        if(adjMatrix[nod][i] == 1 && visited[i] == 0)
        {
            nodes[nr] = i;
            nr+=1;
        }
    }
    return nodes;
}

void getPath(int nod, int *visited, int *path, int pathLength, int *maxPath, int *maxLen)
{
    int i, *nodes, nrNodes = getNrOfNeighbours(nod);
    nodes = (int*) malloc (nrNodes * sizeof(int));

    visited[nod] = VISITED;

    if(nrNodes == 0)
    {
        path[pathLength] = nod;
        path[pathLength] = nod;
        pathLength +=1;
        if(pathLength -1 > *maxLen)
        {
            *maxLen = pathLength;
            memcpy(maxPath, path, pathLength * sizeof(int));
        }
    }
    else
    {
        path[pathLength] = nod;
        pathLength +=1;

        nodes = getNeighbours(nod, visited);

        for(i=0; i<nrNodes; i++)
            getPath(nodes[i], visited, path, pathLength, maxPath, maxLen);

        visited[nod] = UNVISITED;
    }

}

int *findPath(int nod)
{
    int * visited = (int *) malloc (sizeof(int) * nrOfVeritces), i;
    int * path = (int*) malloc ((sizeof(int)) * nrOfVeritces), pathLength = 0;
    int * maxPath = (int*) malloc(sizeof(int) * nrOfVeritces), maxLen = 0;
    for(i=0; i<nrOfVeritces; i++)
        visited[i] = UNVISITED;

    getPath(nod, visited, path, pathLength, maxPath, &maxLen);

    printf("\nThe longest path is:\n");
    for(i=0; i<maxLen; i++)
        printf("%d ", maxPath[i]);

    return maxPath;
}


