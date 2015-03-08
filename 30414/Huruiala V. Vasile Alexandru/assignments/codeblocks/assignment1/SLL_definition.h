#include <stdio.h>

/*Definition of the Node type
*/
typedef struct struct_Node
{
    void* data;
    struct struct_node* next;
} Node;

/*
An object-like structure
*/
typedef struct struct_List
{
    Node* head;
    Node* tail;
    int length;

    void (*AddFirst)(struct struct_List* L, void* data);
    void (*AddLast)(struct struct_List* L, void* data);
    void (*DeleteFirst)(struct struct_List* L);
    void (*DeleteLast)(struct struct_List* L);
    void (*Anihilate)(struct struct_List* L);
    void (*Delete)(struct struct_List* L, void* data);
    void (*PrintAll)(struct struct_List* L, FILE* Out);
    void (*PrintF)(struct struct_List* L, FILE* Out,int data);
    void (*PrintL)(struct struct_List* L, FILE* Out,int data);
    int (*Interpret)(struct struct_List* L, char* cmd, void* data, FILE* Out);
} List;

