#include "list.h"
#include "io.h"

nodeT * createNode(char * content)
{
    nodeT * n = (nodeT*) malloc(sizeof(nodeT));
    n->content = (char*) malloc(sizeof(char) * MAX_STRING_LENGTH);
    strcpy(n->content, content);
    n->next = NULL;
    return n;
}

void addToList(listT *l, char * content)
{
    //! add last
	
	nodeT *node;
	node = createNode(content);

	if (l->head == NULL)
	{
		l->head = l->tail = node;
		l->size++;
	}
	else
	{
		l->tail->next = node;
		l->tail = node;
		l->size++;
	}
}
