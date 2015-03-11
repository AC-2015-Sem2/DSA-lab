#ifndef _SANTNELE_H
# define _SANTINELE_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct s_wave{
                int data;
                struct s_wave *next;
}t_wave;

typedef struct s_country{
		char *name;
		t_wave *head;
		t_wave *tail;
		
}t_country;

typedef struct s_info{
		int n_sant, n_count;
		int *sant;
		FILE *f, *g;
		t_country *team;
			}t_info;
void    add_last(t_country *x, int data);
void	find_the_greatest_countries(t_info info);
void	kill_jim_kong_nu(t_info info);
#endif
