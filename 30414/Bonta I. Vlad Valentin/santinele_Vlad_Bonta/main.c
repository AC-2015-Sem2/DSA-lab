#include "santinele.h"

int main()
{
	int i, data;
	t_info info;

	info.f = fopen("input.dat", "r");
	info.g = fopen("output.dat", "w");

	// Read the numbers of sentinels

	fscanf(info.f, "%d\n", &info.n_sant);
	info.sant = (int*)malloc(sizeof(int) * (info.n_sant + 1));

	// Read every life points of every sentinels

	for(i = 0; i < info.n_sant; ++i)
	{
		fscanf(info.f, "%d ", &info.sant[i]);
		if (i == info.n_sant - 1)
			info.sant[i]++;
	}

	// Read the number of countries

	fscanf(info.f, "%d\n", &info.n_count);
	info.team = (t_country*)malloc(sizeof(t_country) * info.n_count);
	// Read every country and introduce in lists the waves from every country

	for (i = 0; i < info.n_count; i++)
	{
		info.team[i].name = (char*)malloc(sizeof(char) * 1024);
		fscanf(info.f, "%s ", info.team[i].name);
		info.team[i].head = NULL;
		info.team[i].tail = NULL;
		do
		{
			data = -1;
			fscanf(info.f, "%d ", &data);
			if (data != -1)
				add_last(&info.team[i], data);
		}while (data != -1);
	}
	kill_jim_kong_nu(info);
<<<<<<< .mine
	fclose(f);
	fclose(g);
=======
	fclose(info.f);
	fclose(info.g);
>>>>>>> .theirs
	return (0);
}
