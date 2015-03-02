#include "extra.h"

int	main()
{
	FILE	*f;
	FILE	*g;

	int	n, m, i, x;
	int	*sentinels;
	int	sum;

	t_country	*countries;
	
	f = fopen("input.dat", "r");
	g = fopen("ouput.dat", "w");

	fscanf(f, "%d", &n);
	sum = 0;
	sentinels = (int *)malloc(sizeof(int) * n);
	for (i = 0 ; i < n ; ++i)
	{
		fscanf(f, "%d", sentinels + i);
		sum += sentinels[i];
	}

	fscanf(f, "%d", &m);
	countries = (t_country *)malloc(sizeof(t_country) * m);
	memset(countries, 0, sizeof(t_country) * m);
	for (i = 0 ; i < m ; ++i)
	{
		fscanf(f, "%s", (countries + i)->name);
		while (fscanf(f, "%d", &x) == 1)
		{
			add_last(&(countries + i)->head, &(countries + i)->tail, x);
			(countries + i)->sum += x;
		}
	}

	last_strike(countries, m, sum + 1, g);
	the_strongest(countries, m, g);
	the_weakest(countries, m, g);
	who_could_by_itself(countries, m, sentinels, sum, g);

	fclose(f);
	fclose(g);
	return (0);
}
