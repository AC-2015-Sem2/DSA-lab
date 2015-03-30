#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//include string because of the * (stars)
typedef struct node
{
    char* data;
    struct node *left;
    struct node *right;
} NodeT;

typedef struct node_list
{
    char* data;
    struct node_list *next;
    struct node_list *prev;
} NodeL;

NodeL* tail;
FILE* f;

//function to create the binary tree
NodeT* create_bin_tree()
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
        node->left = create_bin_tree();
        node->right = create_bin_tree();
        return node;
    }
}
//function that turn the tree into a list
NodeL* tree2list(NodeT* root)
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
        tree2list(root->left);
        tree2list(root->right);
    }
    return node;
}
//function that turns the tree back into a list
NodeT* list2tree(NodeL** head)
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
        node->left = list2tree(head);
        node->right = list2tree(head);
        return node;
    }
}
//go through the list and print it
void preorder(NodeL* head)
{
    while (head!=NULL)
    {
        printf("%s ", head->data);
        head = head->next;
    }
    printf("\n");
}
//from Git
void prettyPrint(NodeT* root, int x)
{
    if (root==NULL) return;
    prettyPrint(root->right, x+3);
    int i;
    for (i=0; i<x; i++)
    {
        printf(" ");
    }
    printf("%s\n", root->data);
    prettyPrint(root->left, x+3);
}

int main()
{   //wotk with a file for training
    f = fopen("data.txt", "r");
    NodeT* root = create_bin_tree();

    NodeL* firstFromList = tree2list(root);
    printf("This is the list:");
    printf("\n");
    preorder(firstFromList);
    root = list2tree(&firstFromList);
    printf("\n");
    printf("This is the tree: \n");
    prettyPrint(root, 0);

    return 0;
}
