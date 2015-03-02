#include "extra.h"

void	add_last(t_list **head, t_list **tail, int data)
{
	t_list	*new;

	if (*head == NULL)
	{
		*head = (t_list *)malloc(sizeof(t_list));
		(*head)->data = data;
		(*head)->next = NULL;
		*tail = *head;
	}
	else
	{
		new = (t_list *)malloc(sizeof(t_list));
		new->data = data;
		new->next = NULL;
		(*tail)->next = new;
		*tail = new;
	}
}

void	delete_first(t_list **head, t_list **tail)
{
	t_list	*temp;

	if (*head == NULL)
		return ;
	if (*head == *tail)
		*tail = NULL;
	temp = *head;
	*head = (*head)->next;
	free(temp);
}

void	add_last2(t_list2 **head, t_list2 **tail, char *data)
{
	t_list2	*new;

	if (*head == NULL)
	{
		*head = (t_list2 *)malloc(sizeof(t_list2));
		(*head)->data = data;
		(*head)->next = NULL;
		*tail = *head;
	}
	else
	{
		new = (t_list2 *)malloc(sizeof(t_list2));
		new->data = data;
		new->next = NULL;
		(*tail)->next = new;
		*tail = new;
	}
}

void	delete_first2(t_list2 **head, t_list2 **tail)
{
	t_list2	*temp;

	if (*head == NULL)
		return ;
	if (*head == *tail)
		*tail = NULL;
	temp = *head;
	*head = (*head)->next;
	free(temp);
}

void	doom_the_list(t_list2 **head, t_list2 **tail)
{
	t_list2	*p;

	if (*head == NULL)
		return ;
	p = (*head)->next;
	*tail = NULL;
	while (p != NULL)
	{
		free(*head);
		*head = p;
		p = p->next;
	}
	free(*head);
	*head = NULL;
}
