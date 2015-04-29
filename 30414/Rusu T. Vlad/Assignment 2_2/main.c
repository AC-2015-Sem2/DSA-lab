#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_customer
{
    int money;
    int time;
} t_customer;

typedef struct s_list
{
    t_customer  *data;
    struct s_list *next;
} t_list;

typedef struct s_queue
{
    t_list  *head;
    t_list  *tail;
    int     size;
} t_queue;

void init(t_queue *queue)
{
    queue->head = NULL;
    queue->tail = NULL;
    queue->size = 0;
}

void add_last(t_list **head, t_list **tail, t_customer *data)
{
    if (*head == NULL)
    {
        *head = (t_list *)malloc(sizeof(t_list));
        (*head)->data = data;
        (*head)->next = NULL;
        *tail = *head;
    }
    else
    {
        t_list *p;

        p = (t_list *)malloc(sizeof(t_list));
        p->data = data;
        p->next = NULL;
        (*tail)->next = p;
        *tail = p;
    }
}

void delete_first(t_list **head, t_list **tail)
{
    t_list *temp;

    if (*head == NULL)
        return ;
    temp = *head;
    *head = (*head)->next;
    free(temp);
    if (*head == NULL)
        *tail = NULL;
}

int main()
{
    FILE *f, *g;
    t_customer *p;
    char name[30];
	char times[50];
	char *c;
    t_queue *queue;
    int t[15], t2[15], n, sum[15], i;

	f = fopen("input.dat", "r");
	g = fopen("output.dat", "w");

    queue = (t_queue *)malloc(sizeof(t_queue));
    init(queue);
    memset(sum, 0, sizeof(int) * 15);

    n = 0;
	fgets(times, 50, f);
	c = times;
	while (c != NULL)
	{
		t[n] = atoi(c);
		t2[n] = t[n];
		n++;
		c = strchr(c + 1, ' ');
	}
    while (fscanf(f, "%s", name) == 1)
    {
        p = (t_customer *)malloc(sizeof(t_customer));
        fscanf(f, "%d", &(p->money));
        fscanf(f, "%d", &(p->time));
        add_last(&(queue->head), &(queue->tail), p);
    }

    while (queue->head != NULL)
    {
		for (i = 0 ; i < n ; ++i)
			if (t[i] >= queue->head->data->time)
			{
				t[i] -= queue->head->data->time;
				sum[i] += queue->head->data->money;
			}
			else
				t[i] = -1;
        delete_first(&(queue->head), &(queue->tail));
    }

	for (i = 0 ; i < n ; ++i)
		fprintf(g, "After %d seconds: %d\n", t2[i], sum[i]);

    fclose(f);
	fclose(g);
    return 0;
}
