#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

NodeL* tail;
FILE* f;

NodeT* createBinTree();
NodeL* getListFromTree(NodeT*);
void traverseList(NodeL*);
NodeT* getTreeFromList(NodeL**);
void prettyPrint(NodeT*, int);

int main()
{
    f = fopen("inp.txt", "r");
    NodeT* root = createBinTree();
    NodeL* firstFromList = getListFromTree(root);
    traverseList(firstFromList);
    root = getTreeFromList(&firstFromList);
    prettyPrint(root, 0);
    return 0;
}

NodeT* createBinTree()
{
    char* data = (char*)malloc(30);
    fscanf(f, "%s", data);
    if (!strcmp(data, "*"))
    {
        return NULL;
    }
    else
    {
        NodeT* node = (NodeT*)malloc(sizeof(NodeT));
        node->data = data;
        node->left = createBinTree();
        node->right = createBinTree();
        return node;
    }
}

NodeL* getListFromTree(NodeT* root)
{
    NodeL* node = (NodeL*)malloc(sizeof(NodeL));
    if (root==NULL)
    {
        node->data = (char*)malloc(1);
        strcpy(node->data, "*");
    }
    else
    {
        node->data = (char*)malloc(30);
        strcpy(node->data, root->data);
    }
    node->next = NULL;
    node->prev = tail;
    if (tail!=NULL)
    {
        tail->next = node;
    }
    tail = node;
    if (root!=NULL)
    {
        getListFromTree(root->left);
        getListFromTree(root->right);
    }
    return node;
}

NodeT* getTreeFromList(NodeL** head)
{
    if (!strcmp((*head)->data, "*"))
    {
        *head = (*head)->next;
        return NULL;
    }
    else
    {
        NodeT* node = (NodeT*)malloc(sizeof(NodeT));
        node->data = (*head)->data;
        *head = (*head)->next;
        free((*head)->prev);
        node->left = getTreeFromList(head);
        node->right = getTreeFromList(head);
        return node;
    }
}

void traverseList(NodeL* head)
{
    while (head!=NULL)
    {
        printf("%s ", head->data);
        head = head->next;
    }
    printf("\n");
}

void prettyPrint(NodeT* root, int x)
{
    if (root==NULL) return;
    prettyPrint(root->right, x+1);
    int i;
    for (i=0; i<x; i++)
    {
        printf("   ");
    }
    printf("%s\n", root->data);
    prettyPrint(root->left, x+1);
};
