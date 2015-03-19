#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct s_customer
{
    char name[15];
    int money, time;

} t_customer;

typedef struct s_list
{
    t_customer *data;
    struct s_list *next;
} t_list;

typedef struct s_queue
{
    t_list *head;
    t_list *tail;
    int size;
} t_queue;

void init(t_queue *queue)
{
    queue->head=NULL;
    queue->tail=NULL;
    queue->size=0;
}
void  add_last(t_list **head, t_list **tail, t_customer *data)
{
    if(*head==NULL)
    {
        *head=(t_list*)malloc(sizeof(t_list));
        (*head)->data = data;
        (*head)->next=NULL;
        *tail=*head;
    }
    else
    {
        t_list *p;
        p=(t_list*)malloc(sizeof(t_list));
        p->data = data;
        p->next=NULL;
        (*tail)->next = p;
        *tail= p;
    }
}
void delete_first(t_list **head, t_list **tail)
{
    t_list *temp;
    if(*head==NULL)
        return ;
    temp= *head;
    *head = (*head)->next;
    free(temp);
    if(*head == NULL)
        *tail = NULL;
}
int main()
{
    FILE *f=fopen("customers.txt","r");
    FILE *g=fopen("output.txt","w");
    t_customer *p;
    char name[30];
    if(f==NULL)
        perror("Eroare deschidere fisier");
    t_queue *queue;
    queue = (t_queue*)malloc(sizeof(t_queue));
    init(queue);
    int t[10];
    int ti[10];
    int i;
    char sir[150];
    fgets(sir,150,f);
    int n=0;
    for(i=0;i<strlen(sir);i++)
    {    t[n] = atoi(sir + i);
         i = strchr(sir + i, ' ') - sir;
         n++;
    }
    for(i=0; i<n; i++)
        ti[i]=t[i];
    while(fscanf(f,"%s", name) == 1)
    {
        p=(t_customer*)malloc(sizeof(t_customer));
        fscanf(f,"%d",&(p->money));
        fscanf(f,"%d",&(p->time));
        add_last(&(queue->head),&(queue->tail), p);
    }
    int s[10]= {0,0,0,0,0,0,0,0,0,0};
    while(queue->head != NULL)
    {
        for(i=0;i<n;i++)
        {
            if(t[i]>=queue->head->data->time)
                {
                t[i]= t[i] - queue->head->data->time;
                s[i] = s[i] + queue->head->data->money;
                }
                else
                    t[i]=0;
        }
        delete_first(&(queue->head),&(queue->tail));
    }
    for(i=0;i<n;i++)
        fprintf(g, " After %d seconds: %d\n", ti[i], s[i]);
    return 0;
}
