#include <stdio.h>

/*
Definition of the Node type
*/
typedef struct struct_Node Node;
struct struct_Node
{
    void* data;
    Node* next;
    Node* prev;
};

/*
The sentinel
*/
typedef struct struct_List List;
struct struct_List
{
    Node* head;
    Node* tail;
    //int length;//Not required, DLL makes this simpler

    void (*AddFirst)(List* L, void* data);
    void (*AddLast)(List* L, void* data);
    void (*DeleteFirst)(List* L);
    void (*DeleteLast)(List* L);
    void (*Anihilate)(List* L);
    void (*Delete)(List* L, void* data);
    void (*PrintAll)(List* L, FILE* Out);
    void (*PrintF)(List* L, FILE* Out, int data);
    void (*PrintL)(List* L, FILE* Out, int data);
    int (*Interpret)(List* L, char* cmd, void* data, FILE* Out);
    void (*Solve)(List* L, FILE* IN, FILE* Out);
};

void ListInit(List** L);

