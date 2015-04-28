#include "graph.h"
#include "queue.h"
#include "stack.h"
#include "graph.h"

NodeT **head;

void	addLast(int i, int data)
{
	if (head[i] == NULL)
		head[i] = createNode(data);
	else
	{
		NodeT *x;
		x = head[i];
		while (x->next != NULL)
			x = x->next;
		x->next = createNode(data);
	}
}

void	init(NodeT **head)
{
	int i;
	for (i = 0 ; i < numberOfVerteces ; ++i)
		head[i] = NULL;
}

void	matrixToList()
{
	int i, j;
	head = (NodeT **)malloc(sizeof(NodeT *) * numberOfVerteces);
	init(head);
	for (i = 0 ; i < numberOfVerteces ; ++i)
	{
		for (j = 0 ; j < numberOfVerteces ; ++j)
			if (adjMatrix[i][j])
				addLast(i, j);
	}
}

int main()
{
    FILE * f = fopen("matrix.txt","r");
    readFromAdjMatrix(f);
    printAdjMatrix();
    matrixToList();
    bfs(0);
    dfs(0);
    dfsRecurs(0);
    return 0;
}
