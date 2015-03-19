#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_list
{
	int	data;
	struct s_list	*prev;
	struct s_list	*next;
} t_list;

typedef struct s_sentinel
{
	t_list	*head;
	t_list	*tail;
	int	len;
} t_sentinel;

void	add_first(t_sentinel *list, int data)
{
	if (list->head == NULL)
	{
		list->head = (t_list *)malloc(sizeof(t_list));
		list->head->data = data;
		list->head->prev = NULL;
		list->head->next = NULL;
		list->tail = list->head;
	}
	else
	{
		t_list	*new;
		new = (t_list *)malloc(sizeof(t_list));
		new->data = data;
		new->prev = NULL;
		new->next = list->head;
		list->head->prev = new;
		list->head = new;
	}
}

void	add_last(t_sentinel *list, int data)
{
	if (list->head == NULL)
	{
		list->head = (t_list *)malloc(sizeof(t_list));
		list->head->data = data;
		list->head->prev = NULL;
		list->head->next = NULL;
		list->tail = list->head;
	}
	else
	{
		t_list	*new;
		new = (t_list *)malloc(sizeof(t_list));
		new->data = data;
		new->prev = list->tail;
		new->next = NULL;
		list->tail->next = new;
		list->tail = new;
	}
}

void	delete_first(t_sentinel *list)
{
	t_list	*temp;

	if (list->head == NULL)
		return ;
	temp = list->head;
	list->head = list->head->next;
	list->head->prev = NULL;
	free(temp);
}

void	delete_last(t_sentinel *list)
{
	t_list	*temp;

	if (list->head == NULL)
		return ;
	temp = list->tail;
	list->tail = list->tail->prev;
	list->tail->next = NULL;
	free(temp);
	if (list->tail == NULL)
		list->head = NULL;
}

void	doom_the_list(t_sentinel *list)
{
	t_list	*p;

	while (list->head != NULL)
	{
		p = list->head;
		list->head = list->head->next;
		free(p);
	}
}

void	delete_element(t_sentinel *list, int x)
{
	t_list	*p;

	p = list->head;
	while (p != NULL)
	{
		if (p->data == x)
		{
			if (p == list->head)
				delete_first(list);
			else if (p == list->tail)
				delete_last(list);
			else
			{
				p->prev->next = p->next;
				p->next->prev = p->prev;
				free(p);
			}
			return ;
		}
		p = p->next;
	}
}

void	print_all(FILE *f, t_sentinel *list)
{
	t_list	*p;

	p = list->head;
	while (p != NULL)
	{
		fprintf(f, "%d ", p->data);
		p = p->next;
	}
	fprintf(f, "\n");
}

void	print_first(FILE *f, t_sentinel *list, int x)
{
	t_list	*p;
	int	i;

	p = list->head;
	i = 0;
	while ((p != NULL) && (i < x))
	{
		fprintf(f, "%d ", p->data);
		++i;
		p = p->next;
	}
	fprintf(f, "\n");
}

void	print_last(FILE *f, t_sentinel *list, int x)
{
	t_list	*p;
	int	i;

	p = list->tail;
	i = 1;
	while ((p != NULL) && (i < x))
	{
		p = p->prev;
		++i;
	}
	if (p == NULL)
		p = list->head;
	while (p != NULL)
	{
		fprintf(f, "%d ", p->data);
		p = p->next;
	}
	fprintf(f, "\n");
}

int	main()
{
	t_sentinel	*list;
	FILE	*f;
	FILE	*g;
	char	*cmd;
	int		data;

	f = fopen("input.dat", "r");
	g = fopen("output.dat", "w");

	list = (t_sentinel *)malloc(sizeof(t_sentinel));
	list->head = NULL;
	list->tail = NULL;

	cmd = (char *)malloc(sizeof(char) * 20);

	while (fscanf(f, "%s", cmd) != EOF)
	{
		fscanf(f, "%d", &data);
		if (strcmp(cmd, "AF") == 0)
			add_first(list, data);
		else if (strcmp(cmd, "AL") == 0)
			add_last(list, data);
		else if (strcmp(cmd, "DF") == 0)
			delete_first(list);
		else if (strcmp(cmd, "DL") == 0)
			delete_last(list);
		else if (strcmp(cmd, "DOOM_THE_LIST") == 0)
			doom_the_list(list);
		else if (strcmp(cmd, "DE") == 0)
			delete_element(list, data);
		else if (strcmp(cmd, "PRINT_ALL") == 0)
			print_all(g, list);
		else if (strcmp(cmd, "PRINT_F") == 0)
			print_first(g, list, data);
		else if (strcmp(cmd, "PRINT_L") == 0)
			print_last(g, list, data);
	}
	fclose(f);
	fclose(g);
	return (0);
}
