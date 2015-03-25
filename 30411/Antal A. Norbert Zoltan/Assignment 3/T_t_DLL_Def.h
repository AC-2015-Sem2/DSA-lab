#ifndef T_T_DLL_DEF_H_INCLUDED
#define T_T_DLL_DEF_H_INCLUDED

typedef struct nodeT
{
    char* data;
    struct nodeT *left, *right;
} NodeT;

typedef struct nodeL
{
    char* data;
    struct nodeL *next, *prev;
} NodeL;

#endif // T_T_DLL_DEF_H_INCLUDED
