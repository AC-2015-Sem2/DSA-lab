#include "functions.h"


struct node* getNewNode(int x)
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->value = x;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}


void addFirst(int x)
{
    struct node *newNode = getNewNode(x);
    if (head == NULL)
    {
        head = tail = newNode;
        newNode->next = newNode->prev = NULL;
        // return;
    }
    else
    {
        newNode->next = head;
        newNode->prev = NULL;
        head->prev = newNode;
        head = newNode;
    }
}
void addLast(int x)
{
    struct node *newNode = getNewNode(x);
    if (head == NULL)
    {
        head = tail = newNode;
        newNode->next = newNode->prev = NULL;
        // return;
    }
    else
    {
        newNode->next = NULL;
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }

}

void  deleteFirst()
{
    node *newNode = head;
    if(head != NULL)
    {
        head->next->prev = NULL;
        head = head->next;
        free(newNode);
    }
    /* SAU: (deși așa mi-a crăpat):

      head = head->next; //nonempty list assumed
      free(newNode);
      if(head == NULL)
          tail = NULL; //list became empty
      else
          head->prev = NULL;*/
}

void deleteLast()
{
    node *newNode = tail;

    if(newNode != NULL)
    {
        newNode->prev->next = NULL;
        tail = newNode->prev;
        free(newNode);
    }
    /* SAU: (deși așa mi-a crăpat):

        tail = tail->prev;
        if(tail ==NULL)
            head = NULL; //list became empty
    else
        tail->next = NULL;
    free(newNode);*/
}

void deleteX(int x)
{
    if(head->value == x)
    {
        deleteFirst();
    }
    else if(tail->value == x)
    {
        deleteLast();
    }
    else
    {
        node* newNode = head;

        while(newNode->next != tail )
        {
            if(newNode->value == x)
            {
                newNode->prev->next = newNode->next;
                newNode->next->prev = newNode->prev;
                free(newNode);
            }
            newNode=newNode->next;
        }


    }
}

void deleteAll()
{
    node *newNode;
    while(head != NULL)
    {
        newNode = head;
        head = head->next;
        free(newNode);
    }
    tail = NULL;
}

void printAll(FILE *fileOutput)
{
    struct node *temp = head;
    while(temp != NULL)
    {
        fprintf(fileOutput,"%d ", temp->value);
        temp = temp -> next;
    }
    fprintf(fileOutput," \n");
}

void printFirstX(int value, FILE *fileOutput)
{
    node *newNode = head;
    int i;
    for(i=0; ((i<value)&&(newNode!=NULL)); i++)
    {
        fprintf(fileOutput,"%d ", newNode-> value);
        newNode=newNode->next;
    }
    fprintf(fileOutput," \n");
}

void printLastX(int value,  FILE *fileOutput)
{
    node *newNode = tail;
    int i;
    for(i=0; ((i<value) && (newNode!= head)); i++)

    {
        fprintf(fileOutput,"%d ", newNode-> value);
        newNode=newNode->prev;
    }
    fprintf(fileOutput," \n");
}
