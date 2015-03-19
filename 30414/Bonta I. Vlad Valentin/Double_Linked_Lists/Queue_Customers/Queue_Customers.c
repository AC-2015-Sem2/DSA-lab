#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_node{
	int money;
	int wait;
	char *name;
	struct s_node *next;
	struct s_node *prev;
}t_node;

typedef struct s_nodet{
	struct s_nodet *next;
	struct s_nodet *prev;
	int data;
}t_nodet;

typedef struct s_header{
	t_node *head;
	t_node *tail;
	t_nodet *thead;
	t_nodet *ttail;
	int length;
	int leftSec;
	char *name;
	int money;
	int wait;
	int rez;
}t_header;

FILE *f;
FILE *g;

void    enqueue(t_header *x)
{
	if(x->head == NULL)
	{
		t_node *tmp;
		tmp = (t_node*)malloc(sizeof(t_node));
		if (tmp == NULL)
			fprintf(g, "\nNode creation failed!\n");
		tmp->money = x->money;
		tmp->name = (char*)malloc(sizeof(char) * strlen(x->name));
		strcpy(tmp->name, x->name);
		tmp->wait = x->wait;
		tmp->prev = NULL;
		tmp->next = NULL;
		x->head = tmp;
		x->tail = tmp;
	}
	else
	{
		t_node *tmp;
		tmp = (t_node*)malloc(sizeof(t_node));
		if (tmp == NULL)
			fprintf(g, "\nNode creation failed!\n");
		else
		{
			tmp->money = x->money;
			tmp->name = (char*)malloc(sizeof(char) * strlen(x->name));
			strcpy(tmp->name, x->name);
			tmp->wait = x->wait;	
			tmp->next = NULL;
			tmp->prev = x->tail;
			x->tail->next = tmp;
			x->tail = tmp;
		}
	}
}

void    dequeue(t_header *x)
{
	if (x->head == NULL)
	{
		fprintf(g, "Nothing to delete!\n");
		return;
	}
	else if (x->head == x->tail)
	{
		x->head = NULL;
		x->tail = NULL;
	}
	else
	{
		t_node *tmp;
		tmp = (t_node*)malloc(sizeof(tmp));
		tmp = x->head;
		x->head = x->head->next;
		free(tmp);
		tmp = NULL;
	}
}

t_node* peek(t_header *x)
{
	return (x->head);
}


void	enqueuet(t_header *x, int data)
{
	if(x->thead == NULL)
	{
		t_nodet *tmp;
		tmp = (t_nodet*)malloc(sizeof(t_nodet));
		if (tmp == NULL)
			fprintf(g, "\nNode creation failed!\n");
		tmp->data = data;
		tmp->prev = NULL;
		tmp->next = NULL;
		x->thead = tmp;
		x->ttail = tmp;
	}
	else
	{
		t_nodet *tmp;
		tmp = (t_nodet*)malloc(sizeof(t_nodet));
		if (tmp == NULL)
			fprintf(g, "\nNode creation failed!\n");
		else
		{
			tmp->data = data;
			tmp->next = NULL;
			tmp->prev = x->ttail;
			x->ttail->next = tmp;
			x->ttail = tmp;
		}
	}
}


int main(void)
{
	f = fopen("input.dat", "r");
	g = fopen("output.out", "w");
	t_header *x;
	int aux, leftsec = 0;

	x = (t_header*)malloc(sizeof(t_header));
	x->thead = (t_nodet*)malloc(sizeof(t_nodet));
	x->thead = NULL;
	x->ttail = (t_nodet*)malloc(sizeof(t_nodet));
	x->ttail = NULL;
	x->head = (t_node*)malloc(sizeof(t_node));
	x->head = NULL;
	x->tail = (t_node*)malloc(sizeof(t_node));
	x->tail = NULL;
	x->name = (char*)malloc(sizeof(char) * 1024);
	x->rez = 0;
	while (fscanf(f, "%d ", &aux) == 1)
		enqueuet(x, aux);
	//dprintf(2, "head->data==%d\n", head->data);
	while (fscanf(f, "%s %d %d\n", x->name, &x->money, &x->wait) == 3)
		enqueue(x);
	while (x->head != NULL)
	{
		t_node *tmp;
		tmp = (t_node*)malloc(sizeof(t_node));
		tmp = peek(x);
		while (tmp->wait >= 0)
		{
			if (tmp->wait == 0)
				x->rez += tmp->money;
			if (x->thead != NULL && x->thead->data == leftsec)
			{
				fprintf(g, "After %d seconds : %d ruble\n", x->thead->data, x->rez);
				t_nodet *aux;
				aux = (t_nodet*)malloc(sizeof(t_nodet));
				aux = x->thead;
				x->thead = x->thead->next;
				if (x->thead != NULL)
				x->thead->prev = NULL;
				free(aux);
				aux = NULL;
			}
			tmp->wait--;
			leftsec++;
		}
		dequeue(x);
	}
	while (x->thead != NULL)
	{
		fprintf(g, "After %d seconds : %d ruble\n", x->thead->data, x->rez);
		t_nodet *aux;
		aux = (t_nodet*)malloc(sizeof(t_nodet));
		aux = x->thead;
		x->thead = x->thead->next;
		if (x->thead != NULL)
			x->thead->prev = NULL;
		free(aux);
		aux = NULL;
	}
	return (0);
}
