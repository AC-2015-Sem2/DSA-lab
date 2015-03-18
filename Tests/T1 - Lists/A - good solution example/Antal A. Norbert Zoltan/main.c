#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int data;
    struct node* next;
};

void AddFirst(struct node**, int);
void AddLast(struct node**, int);
void Append(struct node**, struct node**);
void PrintAll(struct node**);
void ReadFile(FILE*, struct node**);

int main()
{
    struct node* headA = NULL;
    struct node* headB = NULL;
    FILE* ifile = fopen("file1.dat", "r");
    ReadFile(ifile, &headA);
    ReadFile(ifile, &headB);
    Append(&headA, &headB);
    PrintAll(&headA);
    return 0;
}

void ReadFile(FILE* file, struct node** head)
{
    char* values = (char*)malloc(40);
    fgets(values, 40, file);
    char* value = strtok(values, " ");
    while (value)
    {
        AddLast(head, atoi(value));
        value = strtok(NULL, " ");
    }
}

void AddFirst (struct node** head, int x)
{
    if (*head==NULL)
    {
        *head = (struct node*)malloc(sizeof(struct node));
        (*head)->data = x;
        (*head)->next = NULL;
    }
    else
    {
        struct node* node = (struct node*)malloc(sizeof(struct node));
        node->next = *head;
        node->data = x;
        *head = node;
    }
}

void AddLast (struct node** head, int x)
{
    if (*head==NULL)
    {
        *head = (struct node*)malloc(sizeof(struct node));
        (*head)->data = x;
        (*head)->next = NULL;
    }
    else
    {
        struct node* last = *head;
        while (last->next!=NULL)
        {
            last = last->next;
        }
        struct node* node = (struct node*)malloc(sizeof(struct node));
        node->data = x;
        node->next = NULL;
        last->next = node;
    }
}

void Append (struct node** aRef, struct node** bRef)
{
    if (*aRef==NULL)
    {
        if (*bRef!=NULL)
        {
            *aRef = *bRef;
            *bRef = NULL;
            return;
        }
        return;
    }
    struct node* node = *aRef;
    while (node->next!=NULL)
    {
        node = node->next;
    }
    node->next = *bRef;
    *bRef = NULL;
}

void PrintAll (struct node** head)
{
    FILE* ofile = fopen("output.dat", "a");
    struct node* node = *head;
    while (node!=NULL)
    {
        fprintf(ofile, "%d ", node->data);
        node = node->next;
    }
    fprintf(ofile, "\n");
    fclose(ofile);
}
