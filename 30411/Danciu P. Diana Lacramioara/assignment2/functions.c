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
    p = s->head ;
    s->head = s->head->next ; //nonempty list assumed
    free(p); // release memory taken by node
    s->length--;
    if (s->head == NULL )
        s->tail = NULL; // list became empty
    else
        s->head->prev = NULL;
}

void RemoveLast(void)
{
    NodeT *p;

    p = (NodeT *)malloc(sizeof(NodeT));
    s->tail = s->tail->prev; // nonempty list assumed
    s->length--;
    if ( s->tail == NULL )
        s->head = NULL; // list became empty
    else
        s->tail->next = NULL;
    free ( p ) ; // release memory taken by node

}

void RemoveNodeX(int code)
{
    NodeT *p;

    p = (NodeT *)malloc(sizeof(NodeT));
    p = s->head;
    while (s->head->data == code)
    {
        RemoveFirst();
    }
    while (p != s->tail) // last element of the list
    {
        if (p->data == code)
        {
            p->next->prev = p->prev;
            p->prev->next = p->next;
            s->length--;
            free(p);
        }
        else
            p=p->next;
    }
    if (s->tail->data == code)
    {
        RemoveLast();
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
    s->length = 0;
}

void PrintList(FILE *f)
{
    NodeT *p;

    p = (NodeT *)malloc(sizeof(NodeT));
    p=s->head;
    while (p != NULL )
    {
        fprintf(f, "%d", p->data);
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
            fprintf(f, "%d", p->data);
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
    int i;

    i = 0;
    p = (NodeT *)malloc(sizeof(NodeT));
    p=s->tail;
    if (code < s->length)
    {
        while (i <= code && p != NULL)
        {
            fprintf(f, "%d", p->data);
            p=p->prev;
            i++;
        }
    }
    else
        PrintList(f);

}
