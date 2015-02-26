#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct st_node
{
    int data;
    struct st_node* next;
}node;

node *head, *tail;

void printList()
{
    node* aux = head;
    FILE* f = fopen("output.dat", "a");
    while(aux != NULL)
    {
        fprintf(f, "%d ", aux->data);
        aux = aux->next;
    }
    fprintf(f, "\n");
    fclose(f);
}

void printFirst(int x)
{
    int count = 1;
    node* aux = head;
    FILE* f = fopen("output.dat", "a");
    while(aux != NULL && count <= x)
    {
        fprintf(f, "%d ", aux->data);
        aux = aux->next;
        count++;
    }
    fprintf(f, "\n");
    fclose(f);
}

void printLast(int x)
{
    int number=0, current=0;
    node* aux = head;
    FILE* f = fopen("output.dat", "a");
    while(aux != NULL)
    {
        number++;
        aux = aux->next;
    }

    aux = head;
    while(aux != NULL)
    {
        current++;
        if(current > number - x)
            fprintf(f, "%d ", aux->data);
        aux = aux->next;
    }

    fprintf(f, "\n");
    fclose(f);

    /*
    I don't know how elegant my solution is but it seems to be working.
    It is tricky because we don't know the length of the list beforehand and we don't have the address of the element before the current one to be able to go back from the tail.
    */
}

void addFirst(int data)
{
    if(head==NULL)
    {
        head = (node*)malloc(sizeof(node));
        tail = head;
        head->data = data;
        head->next = NULL;
    }
    else
    {
        node* newNode = (node*)malloc(sizeof(node));
        newNode->data = data;
        newNode->next = head;
        head = newNode;
    }
}

void addLast(int data)
{
    if(tail==NULL)
    {
        tail = (node*)malloc(sizeof(node));
        head = tail;
        tail->data = data;
        tail->next = NULL;
    }
    else
    {
        node* newNode = (node*)malloc(sizeof(node));
        newNode->data = data;
        newNode->next = NULL;
        tail->next = newNode;
        tail = newNode;
    }
}

void deleteFirst()
{
    if(head == tail)
    {
        free(head);
        head = NULL;
        tail = NULL;
    }
    else
    {
        node* newNode = (node*)malloc(sizeof(node));
        newNode = head;
        head = head->next;
        free(newNode);
    }
}

void deleteLast()
{
    if(head == tail)
    {
        free(tail);
        head = NULL;
        tail = NULL;
    }
    else
    {
        node* newNode = (node*)malloc(sizeof(node));
        newNode = head;
        while(newNode != NULL)
        {
            if(newNode->next == tail)
            {
                tail = newNode;
                tail->next = NULL;
                free(newNode->next);
                break;
            }
            else
                newNode = newNode->next;
        }
    }

}

void doom()
{
    node* newNode = (node*)malloc(sizeof(node));
    node* aux = (node*)malloc(sizeof(node));
    newNode = head;
    aux = newNode;
    while(newNode != NULL)
    {
        newNode = newNode->next;
        free(aux);
        aux = newNode;
    }
    head = NULL;
    tail = NULL;

}

void deleteX(int x)
{
    node* newNode = (node*)malloc(sizeof(node));
    node* aux = (node*)malloc(sizeof(node));

    if(head->data == x)
        deleteFirst();
    if(tail->data == x)
        deleteLast();

    newNode = head;

    while(newNode->next != NULL)
    {
        aux = newNode->next;
        if(aux->data == x)
        {
            newNode->next = aux->next;
            free(aux);
        }

        newNode = newNode->next;
    }
}


int main()
{
    FILE* g = fopen("input.dat", "r");

    char oper[20];
    int value;

    while(fscanf(g, "%s", oper)>0)
    {
        if(strcmp(oper, "AF")==0)
        {
            fscanf(g, "%d", &value);
            addFirst(value);
        }
        else if(strcmp(oper, "AL")==0)
        {
            fscanf(g, "%d", &value);
            addLast(value);
        }
        else if(strcmp(oper, "DF")==0)
            deleteFirst();
        else if(strcmp(oper, "DL")==0)
            deleteLast();
        else if(strcmp(oper, "DOOM_THE_LIST")==0)
            doom();
        else if(strcmp(oper, "DE")==0)
        {
            fscanf(g, "%d", &value);
            deleteX(value);
        }
        else if(strcmp(oper, "PRINT_ALL")==0)
            printList();
        else if(strcmp(oper, "PRINT_F")==0)
        {
            fscanf(g, "%d", &value);
            printFirst(value);
        }
        else if(strcmp(oper, "PRINT_L")==0)
        {
            fscanf(g, "%d", &value);
            printLast(value);
        }
    }

    fclose(g);
    return 0;
}
