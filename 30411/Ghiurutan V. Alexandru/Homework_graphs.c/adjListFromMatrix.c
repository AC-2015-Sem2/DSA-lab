#include "adjListFromMatrix.h"

void bfsAdj(int startNode)
{
    int i, first, Node;
    int* visited = (int*) calloc(nrOfVertices, sizeof(int));

    printf("\nbfs on adjList\n");
    printf("%c ", startNode+65);

    enqueue(startNode);

    while (!isEmptyQueue())
    {
        first = peekQueue()->content;
        dequeue();

        visited[first] = 1;

        for (i = 0; i < adjListlength[first]; i++)
        {
            Node = adjList[first][i];
            if (!visited[Node])
            {
                visited[Node] = 1;
                enqueue(Node);
                printf("%c ", Node+65);
            }
        }
    }

    printf("\n");
    free(visited);
}

void dfsAdj(int startNode)
{
    int i, first, Node;
    int* visited = (int*) calloc(nrOfVertices, sizeof(int));


    push(startNode);
    visited[startNode] = 1;

    printf("\ndfs on adjList\n");
    while (!isEmptyStack())
    {
        first = peekStack()->content;
        pop();


        for (i = adjListlength[first]-1; i >=0; i--)
        {
            Node = adjList[first][i];
            if (!visited[Node])
            {
                visited[Node] = 1;
                push(Node);
            }
        }
        printf("%c ", first+65);
    }
    printf("\n");
    free(visited);
}

void dfsRecAdj(int v, int * mark)
{
    int i, Node;
    printf("%c ", v+65);
    for (i = 0; i < adjListlength[v]; i++)
    {
        Node = adjList[v][i];
        if (!mark[Node])
        {
            mark[Node] = 1;
            dfsRecAdj(Node, mark);
        }
    }
}

void dfsRecursAdj(int v)
{
    int* mark  = (int*) calloc (nrOfVertices, sizeof(int));

    printf("\ndfsRecurs on adjList\n");
    mark[v] = 1;
    dfsRecAdj(v, mark);
    printf("\n");
    free(mark);
}

void createAdjList(int** adjMatrix)
{
    adjListlength = (int*) malloc(nrOfVertices * sizeof(int));
    adjList = (int**) malloc (nrOfVertices * sizeof(int*));

    int i;
    for (i = 0; i < nrOfVertices; i++)
    {
        adjListlength[i] = getNumberOfNeighborsOfVertex(i);
        adjList[i] = getAllNeighborsOfVertex(i);
    }
}

void printAdjList()
{
    int i, j;

    printf("\nadjList\n");
    for (i = 0; i < nrOfVertices; i++)
    {
        printf("%c: ", i+65);
        for (j = 0; j < adjListlength[i]; j++)
        {
            printf("%c ", adjList[i][j] + 65);
        }
        printf("\n");
    }
    printf("\n");
}

int** listToMatrix(int** adjList, int* adjListlength)
{
    int** newAdjMatr = (int**) malloc (nrOfVertices * sizeof(int*));

    int i, j;
    for (i = 0; i < nrOfVertices; i++)
    {
        newAdjMatr[i] = (int*) calloc (nrOfVertices, sizeof(int));
        for (j = 0; j < adjListlength[i]; j++)
        {
            newAdjMatr[i][adjList[i][j]] = 1;
        }
    }
    return newAdjMatr;
}

void add(char** dest, int src)
{
    char toAdd[3];
    toAdd[0] = ' ';
    toAdd[1] = (char)(src + 65);
    toAdd[2] = '\0';

    strcat(*dest, toAdd);
}
int dfsRecLen(int v, int* mark, char** c)
{
    int i, Node, terminalNode = 1, maxLen = 0, len;
    int markedLast;

    for (i = 0; i < adjListlength[v]; i++)
    {
        Node = adjList[v][i];
        if (!mark[Node])
        {
            mark[Node] = 1;
            terminalNode = 0;

            len = dfsRecLen(Node, mark, c) + 1;
            if (len > maxLen)
            {
                maxLen = len;
                markedLast = Node;
            }
        }
    }

    if (terminalNode)
    {
        return 1;
    }
    else
    {
        add(c, markedLast);
        return maxLen;
    }
}
