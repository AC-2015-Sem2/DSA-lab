#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_node{
	int data;
	struct s_node *next;
}t_node;

t_node *head = NULL, *tail = NULL;

void	PRINT_ALL()
{
	t_node *tmp = head;
	while (tmp != NULL)
	{
		printf("%d ", tmp->data);
		tmp = tmp->next;
	}
	printf("\n");
}

void	PRINT_F(int x)
{
	int i = 1;
	t_node *tmp;
	tmp = (t_node*)malloc(sizeof(t_node));
	tmp = head;
	//printf("Print the first %d elements from list if exists:\n", x);
	while (i <= x && tmp)
	{
		printf("%d ", tmp->data);
		tmp = tmp->next;
		i++;
	}
	printf("\n");
}

int	ft_list_length()
{
	t_node *tmp;
	int i = 0;
	if (head == NULL)
		return (0);
	tmp = head;
	while (tmp)
	{
		i++;
		tmp=tmp->next;
	}
	return (i);
}

void	PRINT_L(int x)
{
	int	n, i;
	t_node	*tmp;

	//printf("Print the last %d elements in list if exists:\n", x);
	if (head == NULL)
		printf("Empty list!\n");
	else
	{
		tmp = head;
		n = ft_list_length();
		i = 1;
		while (tmp && i <= n - x)
		{
			tmp = tmp->next;
			i++;
		}
		while (tmp)
			{
				printf("%d ", tmp->data);
				tmp = tmp->next;
			}
		printf("\n");
	}
		
}

void    AF(int data)
{
	if(head == NULL)
	{
		t_node *tmp;
		tmp = (t_node*)malloc(sizeof(t_node));
		if (tmp == NULL)
			printf("\nNode creation failed!\n");
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
			printf("\nNode creation failed!\n");
		else
		{
			tmp->data = data;
			tmp->next = head;
			head = tmp;
		}	
	}
}

void    AL(int data)
{
	if(head == NULL)
        {
                t_node *tmp;
                tmp = (t_node*)malloc(sizeof(t_node));
                if (tmp == NULL)
                                printf("\nNode creation failed!\n");
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
                        printf("\nNode creation failed!\n");
		else
		{
			ptr->data = data;
			ptr->next = NULL;	
               		tail->next = ptr;
            		tail = ptr;
		}
        }
}

void	DF()
{
	if (head == NULL)
		//printf("Nothing to delete!\n");
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

void	DL()
{
	if (head == NULL)
                //printf("Nothing to delete!\n");
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

void	DOOM_THE_LIST()
{
	t_node *tmp;
	tmp = (t_node*)malloc(sizeof(t_node));
	while (head->next)
	{
		tmp = head;
		if (head->next)
			head = head->next;
		free(tmp);
		tmp = NULL;
	}
	free(head);
	head = NULL;
	//printf("The list has been DOOMED!!!\n");
}

void	DE(int x)
{
	t_node *tmp;
	tmp = (t_node*)malloc(sizeof(t_node));
	if (head == NULL)
		printf("No list!\n");
	else	if (head->data == x)
		DF();
	else 
	{
		tmp = head;
		while (tmp->next != NULL && tmp->next->next != NULL && tmp->next->data != x)
			tmp = tmp->next;
		if (tmp->next && tmp->next->data == x)
			{
				t_node *ptr;
				ptr = (t_node*)malloc(sizeof(t_node));
				ptr = tmp->next;
				tmp->next = ptr->next;
				free(ptr);
				ptr = NULL;
			}
		//else
		//	printf("No element %d in the list!\n", x);
	}
}

int main(int argc, char **argv)
{
	AF(5);
	AF(6);
	AF(21);
	AL(12);
	DF();
	DL();
	DE(3);
	DE(6);
	AF(2);
	AL(200);
	PRINT_ALL();
	AF(1);
	PRINT_F(2);
	PRINT_L(3);
	DOOM_THE_LIST();
	DL();
	AF(42);
	AL(24);
	AF(9);
	PRINT_ALL();
	PRINT_L(2);
	return (0);
}
