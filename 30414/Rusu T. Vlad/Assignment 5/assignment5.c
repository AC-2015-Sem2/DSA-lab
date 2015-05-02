#include "graph.h"
#include "graphRepresentation.h"

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
			if (adjMat[i][j] == 1)
				addLast(i, j);
	}
}
