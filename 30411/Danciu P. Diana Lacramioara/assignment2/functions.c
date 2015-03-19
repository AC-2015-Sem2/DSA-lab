#include "header.h"

void AddNodeFirst(int code)
{
    NodeT *p;

    p = (NodeT *)malloc(sizeof(NodeT));
    if (s->head == NULL)
    {
        // empty list
        s->head = s->tail = p;
        p->data = code;
        p->next = p->prev = NULL;
        s->length++;
    }
    else
    {
        // nonempty list
        p->next = s->head ;
        p->prev = NULL;
        p->data = code;
        s->head->prev = p;
        s->head = p;
        s->length++;
    }
}

void AddNodeLast(int code)
{
    NodeT *p;

    p=(NodeT *)malloc(sizeof(NodeT));
    if ( s->head == NULL )
    {
        // empty list
        s->head= s->tail = p;
        p->data = code;
        p->next = p->prev = NULL;
        s->length++;
    }
    else
    {
        // nonempty list
        p->next = NULL;
        p->prev =s->tail;
        p->data = code;
        s->tail->next = p;
        s->tail = p;
        s->length++;
    }
}

void RemoveFirst(void)
{
    NodeT *p;

    p = (NodeT *)malloc(sizeof(NodeT));
    if (s->head != NULL)
    {
        if (s->head == s->tail)
        {
            free(s->head);
            s->head = NULL;
            s->tail = NULL;
        }
        else
        {
            p = s->head;
            s->head= s->head->next;
            s->head->prev=NULL;
            free(p);
        }
    }
    s->length--;
}

void RemoveLast(void)
{
    NodeT *p;

    p = (NodeT *)malloc(sizeof(NodeT));

    if (s->head != NULL)
    {
        if (s->head == s->tail)
        {
            free(s->head);
            s->head = NULL;
            s->tail = NULL;
        }
        else
        {
            p = s->tail;
            s->tail= s->tail->prev;
            s->tail->next=NULL;
            free(p);
        }
    }
    s->length--;
}

void RemoveNodeX(int code)
{
    NodeT *p;
    int ok;

    ok=0;
    p = (NodeT *)malloc(sizeof(NodeT));
    p = s->head;
    if (p->data == code)
        RemoveFirst();
    if (s->tail->data == code)
        RemoveLast();
    while (p->next != s->tail && ok == 0) // different from the last element of the list
    {
        if (p->data == code)
        {
            NodeT *delete_n;
            delete_n = (NodeT *)malloc(sizeof(NodeT));
            delete_n = p;
            delete_n->next->prev = delete_n->prev;
            delete_n->prev->next = delete_n->next;
            s->length--;
            ok=1;
            free(delete_n);
        }
        p=p->next;
    }
}

void DeleteList(void)
{
    NodeT *p;

    p = (NodeT *)malloc(sizeof(NodeT));
    while (s->head != NULL )
    {
        p = s->head;
        s->head = s->head->next ;
        free ( p );
    }
    s->tail = NULL;
    s->head=NULL;
    s->length = 0;
}

void PrintList(FILE *f)
{
    NodeT *p;

    p = (NodeT *)malloc(sizeof(NodeT));
    p=s->head;
    while (p != NULL )
    {
        fprintf(f, "%d ", p->data);
        p=p->next;
    }
}

void PrintListFront(FILE *f, int code)
{
    NodeT *p;
    int i;

    i = 0;
    p = (NodeT *)malloc(sizeof(NodeT));
    p=s->head;
    if (code < s->length)
    {
        while (p != NULL && i < code)
        {
            fprintf(f, "%d ", p->data);
            p=p->next;
            i++;
        }
    }
    else
        PrintList(f);
}

void PrintListLast(FILE *f, int code)
{
    NodeT *p;
    int i,elem;

    i = 0;
    elem=0;
    p = (NodeT *)malloc(sizeof(NodeT));
    p=s->head;
    while (p!= NULL)
    {
        elem++;
        p=p->next;
    }
    s->length=elem;
    p=s->head;
    if (code < s->length)
    {
        while (p != NULL)
        {
            if (s->length - i > code)
            {
                i++;
                p=p->next;
            }
            else
            {
                fprintf(f, "%d ", p->data);
                p=p->next;
                i++;
            }
        }
    }
    else
        PrintList(f);
}
