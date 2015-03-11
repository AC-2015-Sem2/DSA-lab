#ifndef EXTRA_H
# define EXTRA_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct s_list
{
	int	data;
	struct s_list *next;
} t_list;

typedef struct s_list2
{
	char *data;
	struct s_list2 *next;
} t_list2;

typedef struct s_country
{
	char	name[30];
	int		sum;
	t_list	*head;
	t_list	*tail;
} t_country;

int	jim_kong_killed(t_country *countries, int m, int sent, FILE *g);
void	last_strike(t_country *countries, int m, int sum, FILE *g);
void	the_strongest(t_country *countries, int m, FILE *g);
void	the_weakest(t_country *countries, int m, FILE *g);
void	who_could_by_itself(t_country *countries, int m, int *sentinels, int sum, FILE *g);
void	add_last(t_list **head, t_list **tail, int data);
void	delete_first(t_list **head, t_list **tail);
void	add_last2(t_list2 **head, t_list2 **tail, char *data);
void	delete_first2(t_list2 **head, t_list2 **tail);
void	doom_the_list(t_list2 **head, t_list2 **tail);

#endif
