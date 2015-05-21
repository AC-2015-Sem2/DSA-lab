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

void addToList(listT l, char * content)
{
    if (l.head == NULL)
	{
		l.head = createNode(content);
		l.tail = l.head;
	}
	else
	{
		l.tail->next = createNode(content);
		l.tail = l.tail->next;
	}
}
