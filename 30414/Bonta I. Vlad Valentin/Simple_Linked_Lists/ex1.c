#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_node{
	int data;
	struct s_node *next;
}t_node;

FILE *g;

t_node *head = NULL, *tail = NULL;
void	print_all()
{
	t_node *tmp = head;
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
		tmp = head;
		//fprintf(g, "Print the first %d elements from list if exists:\n", x);
		while (i <= x && tmp != NULL)
		{
			fprintf(g, "%d ", tmp->data);
			tmp = tmp->next;
			i++;
		}
		fprintf(g, "\n");
	}
}

int	ft_list_length()
{
	t_node *tmp;
	int i = 0;
	if (head == NULL)
		return (0);
	tmp = head;
	while (tmp != NULL)
	{
		i++;
		tmp=tmp->next;
	}
	return (i);
}

void	print_last(int x)
{
	int	n, i;
	t_node	*tmp;

	//fprintf(g, "Print the last %d elements in list if exists:\n", x);
	if (head == NULL)
		fprintf(g, "Empty list!\n");
	else
	{
		tmp = head;
		n = ft_list_length();
		i = 1;
		while (tmp != NULL && i <= n - x)
		{
			tmp = tmp->next;
			i++;
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
	if(head == NULL)
	{
		t_node *tmp;
		tmp = (t_node*)malloc(sizeof(t_node));
		if (tmp == NULL)
			fprintf(g, "\nNode creation failed!\n");
		tmp->data = data;
		tmp->next = NULL;
		head = tmp;
		tail = tmp;
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
			tmp->next = head;
			head = tmp;
		}	
	}
}

void    add_last(int data)
{
	if(head == NULL)
	{
		t_node *tmp;
		tmp = (t_node*)malloc(sizeof(t_node));
		if (tmp == NULL)
			fprintf(g, "\nNode creation failed!\n");
		else
		{
			tmp->data = data;
			tmp->next = NULL;
			head = tmp;
			tail = tmp;
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
			tail->next = ptr;
			tail = ptr;
		}
	}
}

void	delete_first()
{
	if (head == NULL)
		//fprintf(g, "Nothing to delete!\n");
		return;
	else if (head == tail)
	{
		head = NULL;
		tail = NULL;
	}
	else
	{
		t_node *tmp;
		tmp = (t_node*)malloc(sizeof(tmp));
		tmp = head;
		head = head->next;
		free(tmp);
		tmp = NULL;
	}
}

void	delete_last()
{
	if (head == NULL)
		//fprintf(g, "Nothing to delete!\n");
		return ;
	else if (head == tail)
	{
		head = NULL;
		tail = NULL;
	}   
	else
	{
		t_node *tmp;
		tmp = (t_node*)malloc(sizeof(tmp));
		tmp = head;
		while (tmp->next != tail)
			tmp = tmp->next;
		tmp->next = NULL;
		free(tail);
		tail = tmp;
	}	

}

void	doom_list()
{
	t_node *tmp;
	tmp = (t_node*)malloc(sizeof(t_node));
	while (head->next != NULL)
	{
		tmp = head;
		if (head->next)
			head = head->next;
		free(tmp);
		tmp = NULL;
	}
	free(head);
	head = NULL;
	//fprintf(g, "The list has been DOOMED!!!\n");
}

void	delete_at(int x)
{
	t_node *tmp;
	tmp = (t_node*)malloc(sizeof(t_node));
	if (head == NULL)
		fprintf(g, "No list!\n");
	else	if (head->data == x)
		delete_first();
	else 
	{
		tmp = head;
		while (tmp->next != NULL && tmp->next->next != NULL && tmp->next->data != x)
			tmp = tmp->next;
		if (tmp->next != NULL && tmp->next->data == x)
		{
			t_node *ptr;
			ptr = (t_node*)malloc(sizeof(t_node));
			ptr = tmp->next;
			tmp->next = ptr->next;
			free(ptr);
			ptr = NULL;
		}
		//else
		//	fprintf(g, "No element %d in the list!\n", x);
	}
}

int main(int argc, char **argv)
{
	FILE *f = fopen("input.dat", "r");
	g = fopen ("output.dat", "w");
	char *op;
	int value;

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
