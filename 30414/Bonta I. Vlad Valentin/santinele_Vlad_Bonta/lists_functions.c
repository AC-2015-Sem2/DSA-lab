#include "santinele.h"

void	add_last(t_country *x, int data)
{
	if(x->head == NULL)
	{
		t_wave *tmp;
		tmp = (t_wave*)malloc(sizeof(t_wave));
		if (tmp == NULL)
			printf("\nNode creation failed!\n");
		else
		{
			tmp->data = data;
			tmp->next = NULL;
			x->head = tmp;
			x->tail = x->head;
		}
	}
	else
	{
		t_wave *ptr;
		ptr = (t_wave*)malloc(sizeof(t_wave));

		if (ptr == NULL)
			printf("\nNode creation failed!\n");
		else
		{
			ptr->data = data;
			ptr->next = NULL;	
			x->tail->next = ptr;
			x->tail = ptr;
		}
	}
}
