#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef	struct		s_list
{
	int				data;
	struct s_list	*next;
}					t_list;

t_list	*head;
t_list	*tail;

void	add_first(int data)
{
	t_list	*new;

	if (head == NULL)
	{
		head = (t_list *)malloc(sizeof(t_list));
		head->data = data;
		head->next = NULL;
		tail = head;
	}
	else
	{
		new = (t_list *)malloc(sizeof(t_list));
		new->data = data;
		new->next = head;
		head = new;
	}
}

void	add_last(int data)
{
	t_list	*new;

	if (head == NULL)
	{
		head = (t_list *)malloc(sizeof(t_list));
		head->data = data;
		head->next = NULL;
		tail = head;
	}
	else
	{
		new = (t_list *)malloc(sizeof(t_list));
		new->data = data;
		new->next = NULL;
		tail->next = new;
		tail = new;
	}
}

void	delete_first()
{
	t_list	*temp;

	if (head == NULL)
		return ;
	if (head == tail)
		tail = NULL;
	temp = head;
	head = head->next;
	free(temp);
}

void	delete_last()
{
	t_list	*p;

	if (head == NULL)
		return ;
	if (head == tail)
	{
		free(head);
		head = NULL;
		tail = NULL;
	}
	p = head;
	while (p->next != tail)
		p = p->next;
	p->next = NULL;
	free(tail);
	tail = p;
}

void	doom_the_list()
{
	t_list	*p;

	if (head == NULL)
		return ;
	p = head->next;
	tail = NULL;
	while (p != NULL)
	{
		free(head);
		head = p;
		p = p->next;
	}
	free(head);
	head = NULL;
}

void	delete_element(int data)
{
	t_list	*p;
	t_list	*prev;

	p = head;
	while ((p != NULL) && (p->data != data))
	{
		prev = p;
		p = p->next;
	}
	if (p != NULL)
	{
		if (p == head)
			delete_first();
		else if (p == tail)
			delete_last();
		else
		{
			prev->next = p->next;
			free(p);
		}
	}
}

void	print_all(FILE *g)
{
	t_list	*p;

	p = head;
	while (p != NULL)
	{
		fprintf(g, "%d ", p->data);
		p = p->next;
	}
	fprintf(g, "\n");
}

void	print_first(FILE *g, int n)
{
	t_list	*p;

	p = head;
	while ((p != NULL) && (n > 0))
	{
		fprintf(g, "%d ", p->data);
		p = p->next;
		--n;
	}
	fprintf(g, "\n");
}

void	print_last(FILE *g, int n)
{
	int		i;
	t_list	*p;
	t_list	*start;

	p = head;
	start = head;
	i = 0;
	while (p != NULL)
	{
		if (i >= n)
			start = start->next;
		p = p->next;
		++i;
	}
	while (start != NULL)
	{
		fprintf(g, "%d ", start->data);
		start = start->next;
	}
	fprintf(g, "\n");
}

int		main()
{
	FILE	*f;
	FILE	*g;
	char	*cmd;
	int		data;

	f = fopen("input.dat", "r");
	g = fopen("output.dat", "w");

	head = NULL;
	tail = NULL;

	cmd = (char *)malloc(sizeof(char) * 20);

	while (fscanf(f, "%s", cmd) != EOF)
	{
		fscanf(f, "%d", &data);
		if (strcmp(cmd, "AF") == 0)
			add_first(data);
		else if (strcmp(cmd, "AL") == 0)
			add_last(data);
		else if (strcmp(cmd, "DF") == 0)
			delete_first();
		else if (strcmp(cmd, "DL") == 0)
			delete_last();
		else if (strcmp(cmd, "DOOM_THE_LIST") == 0)
			doom_the_list();
		else if (strcmp(cmd, "DE") == 0)
			delete_element(data);
		else if (strcmp(cmd, "PRINT_ALL") == 0)
			print_all(g);
		else if (strcmp(cmd, "PRINT_F") == 0)
			print_first(g, data);
		else if (strcmp(cmd, "PRINT_L") == 0)
			print_last(g, data);
	}
	fclose(f);
	fclose(g);
	return (0);
}
