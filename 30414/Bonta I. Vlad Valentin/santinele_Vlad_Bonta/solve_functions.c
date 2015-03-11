#include "santinele.h"

void	kill_jim_kong_nu(t_info info)
{
	int ok, i, j, *damaged_points, sant_sum, aux, *country_sum, *sant;
	t_wave *c, *x;
	sant = (int*)malloc(sizeof(int) * info.n_sant);
	for (i = 0;i < info.n_sant; ++i)
		sant[i] = info.sant[i];
	country_sum = (int*)malloc(sizeof(int) * info.n_count);
	for (i = 0; i < info.n_count; ++i)
	{
		x = info.team[i].head;
		while (x)
		{
			country_sum[i] += x->data;
			x = x->next;
		}
	}
	sant_sum = 0;
	for (i = 0;i < info.n_sant;++i)
		sant_sum += info.sant[i];
	aux = sant_sum;
	i = 0;
	damaged_points = (int*)malloc(sizeof(int) * info.n_count);
	do
	{
		j = 0;
		ok = 0;
		while (j < info.n_count)
		{
			c = info.team[j].head;
			while (c->next && c->data <= 0)
			{
				c = (c->next);
			}

			if (sant_sum > 0 && c->data > 0)
			{
				ok = 1;
				if (sant_sum > c->data)
				{
					damaged_points[j] += c->data;
					sant_sum = sant_sum - c->data;
					c->data = 0;
				}
				else
				{
					damaged_points[j] += sant_sum;
					c->data = c->data - sant_sum;
					sant_sum = 0;
				}
			}
			if (sant_sum <= 0)
			{
				if (sant_sum <= 0)
				{
					fprintf(info.g, "The tyrant was killed!\n");
					fprintf(info.g, "The last hit was done by: %s\n", info.team[j].name);
					ok = -1;
					break;
				}
			}
			j++;
		}
		if (ok == 0)
			break;
	}while (ok == 1);
	if (ok != -1)
		fprintf(info.g, "The tyrant was not killed!\n");

	int minn = -1, maxx = -1;
	for (i = 0;i < info.n_count;++i)
	{
		if (damaged_points[i] < minn || minn == -1)
		{
			minn = damaged_points[i];
		}
		if (damaged_points[i] > maxx || maxx == -1)
		{
			maxx = damaged_points[i];
		}
	}
	fprintf(info.g, "The strongest country was: ");
	for (i = 0; i < info.n_count; ++i)
	{
		if (damaged_points[i] == maxx)
		{
			fprintf(info.g, "%s ", info.team[i].name);

		}
	}

	fprintf(info.g, "\n");
	fprintf(info.g, "The weakest country was: ");
	for (i = 0; i < info.n_count; ++i)
	{
		if (damaged_points[i] == minn)
		{
			fprintf(info.g, "%s ", info.team[i].name);
		}
	}
	fprintf(info.g, "\n");
	sant_sum = aux - 1;
	ok = 0;
	for (i = 0; i < info.n_count; i++)
	{
		if (country_sum[i] >= sant_sum)
		{
			if (ok == 0)
				fprintf(info.g, "The countries that could defeated all the sentinels alone: %s ", info.team[i].name);
			else
				fprintf(info.g, "%s ", info.team[i].name);
			ok = 1;
		}
	}
	if (ok == 1)
		fprintf(info.g, "\n");
	else
		fprintf(info.g, "No country could have defeated all the sentinels.\n");


	if (ok == 0)
	{
		int maxx = -1;
		for (i = 0;i < info.n_count; ++i)
		{
			if (country_sum[i] > maxx || maxx == -1)
			{
				maxx = country_sum[i];
			}
		}
		int j;
		for (j = 0;j < info.n_count; ++j)
		{
			if (country_sum[j] == maxx)
			{
				sant_sum = 0;
				for (i = 0;i < info.n_sant;++i)
					sant_sum += info.sant[i];
				sant_sum--;
				int downed_sentineles = 0, last_damage = 0;
				i = 0;
				while (country_sum[j] > 0 && i < info.n_sant)
				{
					if (country_sum[j] > sant[i])
					{
						downed_sentineles++;
					}
					if (country_sum[j] - sant[i] <= 0)
					{
						last_damage = country_sum[j];
					}
					country_sum[j] = country_sum[j] -sant[i];
					i++;
				}
				if (downed_sentineles == 0)
					fprintf(info.g, "No country could have defeated any sentinel.\n");
				else
				{       if (downed_sentineles == 1)
					fprintf(info.g, "%s could have brought down first sentinel ", info.team[j].name);
					else
						fprintf(info.g, "%s could have brought down first %d ", info.team[j].name, downed_sentineles);
					if (last_damage != 0)
						fprintf(info.g, "and would have had chipped of %d life points from sentinel %d.\n", last_damage, downed_sentineles + 1);
					else
						fprintf(info.g, ".\n");

				}
			}
		}
	}
	free(c);
	free(x);
}
