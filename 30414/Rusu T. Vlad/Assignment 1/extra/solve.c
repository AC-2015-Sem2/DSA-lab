#include "extra.h"


int	jim_kong_killed(t_country *countries, int m, int sent, FILE *g)
{
	int	c_sum, i;

	c_sum = 0;
	for (i = 0 ; i < m ; ++i)
		c_sum += (countries + i)->sum;
	if (c_sum >= sent)
	{
		fprintf(g, "The tyrant was killed!\n");
		return (1);
	}
	else
	{
		fprintf(g, "The tyrant was not killed!\n");
		return (0);
	}
}

void	last_strike(t_country *countries, int m,  int sum, FILE *g)
{
	int	i, army_left;

	if (jim_kong_killed(countries, m, sum, g))
	{
		while (1)
		{
			army_left = 0;
			for (i = 0 ; i < m ; ++i)
				if ((countries + i)->head)
				{
					army_left = 1;
					sum -= (countries + i)->head->data;
					delete_first(&(countries + i)->head, &(countries + i)->tail);
					if (sum <= 0)
					{
						fprintf(g, "The last hit was done by: %s\n", (countries + i)->name);
						return ;
					}
				}
			if (army_left == 0)
				return ;
		}
	}
}

void	the_strongest(t_country *countries, int m, FILE *g)
{
	t_list2	*head;
	t_list2	*tail;
	int	maxim, i;

	head = NULL;
	tail = NULL;
	maxim = -1;

	for (i = 0 ; i < m ; ++i)
		if ((countries + i)->sum >= maxim)
		{
			if ((countries + i)->sum > maxim)
				doom_the_list(&head, &tail);
			maxim = (countries + i)->sum;
			add_last2(&head, &tail, (countries + i)->name);
		}

	if (head->next != NULL)
		fprintf(g, "The strongest countries were: ");
	else
		fprintf(g, "The strongest country was: ");
	while (head != NULL)
	{
		if (head->next != NULL)
			fprintf(g,"%s, ", head->data);
		else
			fprintf(g, "%s\n", head->data);
		delete_first2(&head, &tail);
	}
}

void	the_weakest(t_country *countries, int m, FILE *g)
{
	t_list2	*head;
	t_list2	*tail;
	int	minim, i;

	head = NULL;
	tail = NULL;
	minim = ~(1 << 31); // -MININT

	for (i = 0 ; i < m ; ++i)
		if ((countries + i)->sum <= minim)
		{
			if ((countries + i)->sum < minim)
				doom_the_list(&head, &tail);
			minim = (countries + i)->sum;
			add_last2(&head, &tail, (countries + i)->name);
		}

	if (head->next != NULL)
		fprintf(g, "The weakest countries were: ");
	else
		fprintf(g, "The weakest country was: ");
	while (head != NULL)
	{
		if (head->next != NULL)
			fprintf(g, "%s, ", head->data);
		else
			fprintf(g, "%s\n", head->data);
		delete_first2(&head, &tail);
	}
}

void	who_could_by_itself(t_country *countries, int m, int *sentinels, int sum, FILE *g)
{
	t_list2	*head;
	t_list2	*tail;
	int	maxim, i;

	head = NULL;
	tail = NULL;

	for (i = 0 ; i < m ; ++i)
		if ((countries + i)->sum >= sum)
			add_last2(&head, &tail, (countries + i)->name);
	if (head != NULL)
		while (head != NULL)
		{
			if (head->next != NULL)
				fprintf(g, "%s, ", head->data);
			else
				fprintf(g, "%s ", head->data);
			fprintf(g, "could have defeated all the sentinels.\n");
			delete_first2(&head, &tail);
		}
	else
	{
		fprintf(g, "No country could have defeated all the sentinels.\n");
		maxim = -1;
		for (i = 0 ; i < m ; ++i)
			if ((countries + i)->sum >= maxim)
			{
				if ((countries + i)->sum > maxim)
					doom_the_list(&head, &tail);
				maxim = (countries + i)->sum;
				add_last2(&head, &tail, (countries + i)->name);
			}
		while (head != NULL)
		{
			if (head->next != NULL)
				fprintf(g, "%s, ", head->data);
			else
				fprintf(g, "%s ", head->data);
			delete_first2(&head, &tail);
		}
		i = 0;
		while (maxim - sentinels[i] > 0)
		{
			maxim -= sentinels[i];
			++i;
		}
		fprintf(g, "could have brought down the first %d sentinels and would have chipped off %d life points from sentinel %d.\n", i, maxim, i + 1);
	}
}
