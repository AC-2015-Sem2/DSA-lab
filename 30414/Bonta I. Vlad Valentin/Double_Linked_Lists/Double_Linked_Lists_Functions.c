#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_node{
	int data;
	struct s_node *next;
	struct s_node *prev;
}t_node;

typedef struct s_header
{
	int length;
	t_node *head;
	t_node *tail;
}t_header;

FILE *g;
t_header *list;

void	print_all()
{
	t_node *tmp = list->head;
	while (tmp != NULL)
	{
		fprintf(g, "%d ", tmp->data);
		tmp = tmp->next;
	}
	fprintf(g, "\n");

}

void	print_first(int x)
{
	int i = 1;
	t_node *tmp;
	tmp = (t_node*)malloc(sizeof(t_node));

	if (tmp == NULL)
		fprintf(g, "\nNode creation failed!\n");
	else
	{
		tmp = list->head;
		while (i <= x && tmp != NULL)
		{
			fprintf(g, "%d ", tmp->data);
			tmp = tmp->next;
			i++;
		}
		fprintf(g, "\n");
	}
}

void	print_last(int x)
{
	t_node	*tmp;

	tmp = (t_node*)malloc(sizeof(t_node));
	if (list->head == NULL)
		fprintf(g, "Empty list!\n");
	else
	{
		tmp = list->tail;
		while (x > 1 && tmp != NULL)
		{
			if (tmp->prev != NULL)
				tmp = tmp->prev;
			x--;
		}
		while (tmp != NULL)
		{
			fprintf(g, "%d ", tmp->data);
			tmp = tmp->next;
		}
		fprintf(g, "\n");
	}
}

void    add_first(int data)
{
	if(list->head == NULL)
	{
		t_node *tmp;
		tmp = (t_node*)malloc(sizeof(t_node));
		if (tmp == NULL)
			fprintf(g, "\nNode creation failed!\n");
		tmp->data = data;
		tmp->next = NULL;
		tmp->prev = NULL;
		list->head = tmp;
		list->tail = tmp;
	}
	else
	{
		t_node *tmp;
		tmp = (t_node*)malloc(sizeof(t_node));
		if (tmp == NULL)
			fprintf(g, "\nNode creation failed!\n");
		else
		{
			tmp->data = data;
			tmp->next = list->head;
			tmp->prev = NULL;
			if (list->tail->prev == NULL)
				list->tail->prev = tmp;
			list->head = tmp;
		}	
	}
	list->length++;
}

void    add_last(int data)
{
	if(list->head == NULL)
	{
		t_node *tmp;
		tmp = (t_node*)malloc(sizeof(t_node));

		if (tmp == NULL)
			fprintf(g, "\nNode creation failed!\n");
		else
		{
			tmp->data = data;
			tmp->next = NULL;
			tmp->prev = NULL;
			list->head = tmp;
			list->tail = tmp;
		}
	}
	else
	{
		t_node *ptr;
		ptr = (t_node*)malloc(sizeof(t_node));

		if (ptr == NULL)
			fprintf(g, "\nNode creation failed!\n");
		else
		{
			ptr->data = data;
			ptr->next = NULL;	
			ptr->prev = list->tail;
			list->tail->next = ptr;
			list->tail = ptr;
		}
	}
	list->length++;
}

void	delete_first()
{
	if (list->head == NULL)
	{
		//fprintf(g, "Nothing to delete!\n");
		return;
	}
	else if (list->head == list->tail)
	{
		list->head = NULL;
		list->tail = NULL;
	}
	else
	{
		t_node *tmp;
		tmp = (t_node*)malloc(sizeof(tmp));
		if (tmp == NULL)
			fprintf(g, "\nNode creation failed\n");
		else
		{
			tmp = list->head;
			list->head = list->head->next;
			list->head->prev = NULL;
			free(tmp);
			tmp = NULL;
		}
	}
	if (list->length > 0)
		list->length--;
}

void	delete_last()
{
	if (list->head == NULL)
	{
		//fprintf(g, "Nothing to delete!\n");
		return ;
	}
	else if (list->head == list->tail)
	{
		list->head = NULL;
		list->tail = NULL;
	}   
	else
	{
		t_node *tmp;
		tmp = (t_node*)malloc(sizeof(tmp));
		if (tmp == NULL)
			fprintf(g, "\nNode creation failed\n");
		else
		{
			tmp = list->tail;
			list->tail = list->tail->prev;
			list->tail->next = NULL;
			free(tmp);
			tmp = NULL;
		}
	}
	if (list->length > 0)
		list->length--;
}

void	doom_list()
{
	t_node *tmp;
	tmp = (t_node*)malloc(sizeof(t_node));
	if (tmp == NULL)
	{
		fprintf(g, "\nNode creation failed\n");
		return ;
	}
	while (list->head->next != NULL)
	{
		tmp = list->head;
		if (list->head->next)
			list->head = list->head->next;
		free(tmp);
		tmp = NULL;
	}
	free(list->head);
	list->head = NULL;
}

void	delete_at(int x)
{
	t_node *tmp;
	tmp = (t_node*)malloc(sizeof(t_node));
	if (list->head == NULL)
		fprintf(g, "No list!\n");
	else	if (list->head->data == x)
		delete_first();
	else 
	{
		tmp = list->head;
		while (tmp != NULL && tmp->data != x)
			tmp = tmp->next;
		if (tmp != NULL && tmp->data == x)
		{
				tmp->prev->next = tmp->next;
				tmp->next->prev = tmp->prev;
				free(tmp);
				tmp = NULL;
		}
		//else
		//	fprintf(g, "No element %d in the list!\n", x);
	}
}

int main(void)
{
	FILE *f = fopen("input.dat", "r");
	g = fopen ("output.dat", "w");
	char *op;
	int value;

	list = (t_header*)malloc(sizeof(t_header));
	list->head = (t_node*)malloc(sizeof(t_node));
	list->head = NULL;
	list->tail = (t_node*)malloc(sizeof(t_node));
	list->tail = NULL;
	list->length = 0;
	op = (char*)malloc(sizeof(char) * 10);
	while(fscanf(f, "%s", op) > 0)
	{
		if(strcmp(op, "AF") == 0)
		{
			fscanf(f, "%d", &value);
			add_first(value);
		}
		else if(strcmp(op, "AL") == 0)
		{
			fscanf(f, "%d", &value);
			add_last(value);
		}
		else if(strcmp(op, "DF") == 0)
			delete_first();
		else if(strcmp(op, "DL") == 0)
			delete_last();
		else if(strcmp(op, "DOOM_THE_LIST") == 0)
			doom_list();
		else if(strcmp(op, "DE")==0)
		{
			fscanf(f, "%d", &value);
			delete_at(value);
		}
		else if(strcmp(op, "PRINT_ALL")==0)
			print_all();
		else if(strcmp(op, "PRINT_F")==0)
		{
			fscanf(f, "%d", &value);
			print_first(value);
		}
		else if(strcmp(op, "PRINT_L")==0)
		{
			fscanf(f, "%d", &value);
			print_last(value);
		}
	}
	fclose(f);
	fclose(g);
	return (0);
}
