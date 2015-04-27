#include "list.h"

void	addLast(int label, int data)
{
	if (head[label] == NULL)
		head[label] = createNode(data);
	else
	{
		NodeT *p;

		p = head[label];
		while (p->next != NULL)
			p = p->next;
		p->next = createNode(data);
	}
}

void	deleteLast(int label)
{
	NodeT *p;

	if (head[label] == NULL)
		return ;
	p = head[label];
	while (p->next != NULL)
		p = p->next;
	free(p);
	if (head[label] == p)
		head[label] == NULL;
}
