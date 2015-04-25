#include "graph.h"
#include "stack.h"

/// I/O
void readAdjMatrix(FILE * f, int* size, int*** mat)
{
    fscanf(f, "%d", size);
    int i, j;
    int** adjMat = (int**)malloc((*size)*sizeof(int*));
    for(i = 0; i < *size; i++)
    {
        *(adjMat + i) = (int*)malloc((*size)*sizeof(int));
    }
    for(i = 0; i < *size; i++)
        for(j = 0; j < *size; j++)
            fscanf(f, "%d", &adjMat[i][j]);

    *mat = adjMat;
}

void printAdjMatrix(int size, int** mat)
{
    int i,j;

    printf("\nThe matrix is:\n");
    printf("    ");
    for (i=0; i<size; i++)
    {
        printf("%c   ",65+i);
    }
    printf("\n");
    for (i=0; i<size; i++)
    {
        printf("%c ",65+i);
        for (j=0; j<size; j++)
            printf("%3d ", mat[i][j]);
        printf("\n");
    }
}

/// Adjacency matrix to lists

node** AdjMatToAdjList(int** mat, int size)
{
    ///The vector of nodes will be the heads of the lists
    node** AdjList = (node**)malloc(sizeof(node*) * size);
    int i;
    for(i = 0; i < size; i++)
    {
        *(AdjList + i) = NULL;
    }
    ///This will be for the tails of the lists(so enqueueue can be used)
    node** AdjListTail = (node**)malloc(sizeof(node*) * size);
    for(i = 0; i < size; i++)
        *(AdjListTail + i) = NULL;

    int j;
    for(i = 0; i < size; i++)
    {
        for(j = 0; j < size; j++)
        {
            if(mat[i][j] == 1)
            {
                int firstNode;
                enq(&AdjListTail[i], j, &firstNode);
                if(firstNode == 1)
                    AdjList[i] = AdjListTail[i];
            }
        }
    }
    return AdjList;
}

void printAdjList(node** adjList, int size)
{
    int i;
    for(i = 0; i < size; i++)
    {
        printf("%d: ", i);
        printQ(adjList[i]);
    }
}

/// Adjacency list to matrix

int** AdjListToAdjMat(node** adjList, int size)
{
    int** adjMat = (int**)malloc(sizeof(int*) * size);
    int i;
    for(i = 0; i < size; i++)
    {
        *(adjMat + i) = (int*)malloc(sizeof(int) * size);
        int j;
        for(j = 0; j < size; j++)
        {
            adjMat[i][j] = 0;
        }
    }

    for(i = 0; i < size; i++)
    {
        node* aux = adjList[i];
        while(aux != NULL)
        {
            adjMat[i][aux->data]++;
            aux = aux->next;
        }
    }

    return adjMat;
}

int getNumberOfNeighborsOfVertex(int startingVector, int size, int** mat)
{
    int nNeighbours = 0;
    int i = 0;
    for(i = 0; i < size; i++)
        if(mat[startingVector][i] == 1)
            nNeighbours++;
    return nNeighbours;
}

int* getAllNeighborsOfVertex(int startingVector, int size, int** mat)
{
    int nNeighbours = getNumberOfNeighborsOfVertex(startingVector, size, mat);
    int* allNeighbours = (int*)malloc(sizeof(int)*nNeighbours);
    int i = 0;
    int j = 0;
    for(i = 0; i < size; i++)
        if(mat[startingVector][i] == 1)
        {
            allNeighbours[j] = i;
            j++;
        }
    return allNeighbours;
}

void bfsMat(int startingNode, int** mat, int size)
{
    int* visited = (int*)malloc(sizeof(int)*size);
    int i;
    for(i = 0; i < size; i++)
        visited[i] = UNVISITED;

    visited[startingNode] = VISITED;
    printf("%d ", startingNode);
    node* head = NULL;
    node* tail = NULL;
    int temp;
    enq(&tail, startingNode, &temp);
    head = tail;

    while(head != NULL)
    {
        int v = head->data;
        deq(&head);
        for(i = 0; i < size; i++)
            if(mat[v][i] == 1 && visited[i] == UNVISITED)
            {
                visited[i] = VISITED;
                printf("%d ", i);
                enq(&tail, i, &temp);
                if(head == NULL)
                    head = tail;
            }
    }
    printf("\n");
}

void dfsMat(int startingNode, int** mat, int size)
{
    int* visited =(int*)malloc(sizeof(int) * size);
    int i;
    for(i = 0; i < size; i++)
        visited[i] = UNVISITED;

    node* head = NULL;
    push(&head, startingNode);

    while(head != NULL)
    {
        int v = head->data;
        pop(&head);
        if(visited[v] == UNVISITED)
        {
            visited[v] = VISITED;
            for(i = size - 1; i >= 0; i--)
                if(mat[v][i] == 1)
                    if(visited[i] == UNVISITED)
                        push(&head, i);

            printf("%d ", v);
        }
    }
    printf("\n");
}

void bfsLst(int startingNode, node** lst, int size)
{
    int* visited = (int*)malloc(sizeof(int)*size);
    int i;
    for(i = 0; i < size; i++)
        visited[i] = UNVISITED;

    visited[startingNode] = VISITED;
    printf("%d ", startingNode);
    node* head = NULL;
    node* tail = NULL;
    int temp;
    enq(&tail, startingNode, &temp);
    head = tail;

    while(head != NULL)
    {
        int v = head->data;
        deq(&head);
        node* aux = lst[v];
        while(aux != NULL)
        {
            if(visited[aux->data] == UNVISITED)
            {
                visited[aux->data] = VISITED;
                printf("%d ", aux->data);
                enq(&tail, aux->data, &temp);
                if(head == NULL)
                    head = tail;
            }
            aux = aux->next;
        }
    }
    printf("\n");
}

///This is a bit tricky because the matrix equivalent uses a reverse for
///in order to do that with a list, I took all the elements
///from the list of the respective vertex
///and I put them in another stack, reversing their order
void dfsLst(int startingNode, node** lst, int size)
{
    int* visited =(int*)malloc(sizeof(int) * size);
    int i;
    for(i = 0; i < size; i++)
        visited[i] = UNVISITED;

    node* head = NULL;
    push(&head, startingNode);

    while(head != NULL)
    {
        int v = head->data;
        pop(&head);
        if(visited[v] == UNVISITED)
        {
            visited[v] = VISITED;
            ///We build another stack which is the adjacency list
            ///for the vertex in reverse order
            node* aux1 = lst[v];
            node* aux2 = NULL;
            while(aux1 != NULL)
            {
                push(&aux2, aux1->data);
                aux1 = aux1->next;
            }
            while(aux2 != NULL)
            {
                if(visited[aux2->data] == UNVISITED)
                    push(&head, aux2->data);
                pop(&aux2);
            }

            printf("%d ", v);
        }
    }
    printf("\n");
}

void dfsMatRec(int v, int* visited, int** mat, int size)
{
    if(visited[v] == UNVISITED)
    {
        printf("%d ", v);

        visited[v] = VISITED;

        int i;
        for(i = 0; i < size; i++)
        {
            if(mat[v][i] == 1)
                dfsMatRec(i, visited, mat, size);
        }
    }
}

void dfsRecursiveMat(int startingNode, int** mat, int size)
{
    int* visited = (int*)malloc(sizeof(int) * size);
    int i;
    for(i = 0; i < size; i++)
        visited[i] = UNVISITED;

    dfsMatRec(startingNode, visited, mat, size);
    printf("\n");
}

void dfsLstRec(int v, int* visited, node** lst, int size)
{
    if(visited[v] == UNVISITED)
    {
        printf("%d ", v);

        visited[v] = VISITED;

        node* aux = lst[v];
        while(aux != NULL)
        {
            dfsLstRec(aux->data, visited, lst, size);
            aux = aux->next;
        }
    }
}

void dfsRecursiveLst(int startingNode, node** lst, int size)
{
    int* visited = (int*)malloc(sizeof(int) * size);
    int i;
    for(i = 0; i < size; i++)
        visited[i] = UNVISITED;

    dfsLstRec(startingNode, visited, lst, size);
    printf("\n");
}
