#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
    int data;
    struct s_list *next;
} t_list;

void add_last(t_list **head, int data)
{
    if (*head == NULL)
    {
        *head = (t_list *)malloc(sizeof(t_list));
        (*head)->data = data;
        (*head)->next = NULL;
    }
    else
    {
        t_list *New, *p;
        p = *head;
        while (p->next != NULL)
            p = p->next;
        New = (t_list *)malloc(sizeof(t_list));
        New->data = data;
        New->next = NULL;
        p->next = New;
    }
}

void print_all(FILE *f, t_list *head)
{
    t_list *p;

    p = head;
    while (p != NULL)
    {
        fprintf(f, "%d ", p->data);
        p = p->next;
    }
    fprintf(f, "\n");
}

void AlternatingSplit(t_list *source, t_list **aRef, t_list **bRef)
{
    t_list *s;

    if (source == NULL)
        return;
    *aRef = NULL;
    *bRef = NULL;
    s = source;
    while (s != NULL)
    {
        add_last(aRef, s->data);
        s = s->next;
        if (s == NULL)
            break ;
        add_last(bRef, s->data);
        s = s->next;
    }
}

int main()
{
    FILE *f;
    FILE *g;
    t_list *source;
    t_list *aRef;
    t_list *bRef;
    int data;

    f = fopen("input.txt", "r");
    g = fopen("output.txt", "w");

    source = 0;
    while (fscanf(f, "%d", &data) == 1)
        add_last(&source, data);

    AlternatingSplit(source, &aRef, &bRef);
    fprintf(g, "The initial list is: ");
    print_all(g, source);
    fprintf(g, "The first list is: ");
    print_all(g, aRef);
    fprintf(g, "The second list is: ");
    print_all(g, bRef);

    fclose(f);
    fclose(g);
    return 0;
}
