#ifndef DEF_H_INCLUDED
#define DEF_H_INCLUDED

typedef struct nodel
{
    struct nodel *next;
    struct nodel *prev;
    char data;
} NodeL;
NodeL *head=NULL,*tail=NULL;

typedef struct nodet
{
    struct nodet *left;
    struct nodet *right;
    int data;
} NodeT;

#endif // DEF_H_INCLUDED
