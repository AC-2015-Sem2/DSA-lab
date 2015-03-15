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
    if (s->head == NULL)
    {
        s->head = s->tail = newNode;
        newNode->next = newNode->prev = NULL;
        // return;
    }
    else
    {
        newNode->next = s->head;
        newNode->prev = NULL;
        s->head->prev = newNode;
        s->head = newNode;
    }
    s->length++;
}
void addLast(int x)
{
    struct node *newNode = getNewNode(x);
    if (s->head == NULL)
    {
        s->head = s->tail = newNode;
        newNode->next = newNode->prev = NULL;
        // return;
    }
    else
    {
        newNode->next = NULL;
        newNode->prev = s->tail;
        s->tail->next = newNode;
        s->tail = newNode;
    }
    s->length++;
}

void  deleteFirst()
{
    node *newNode = s->head;
    if(s->head != NULL)
    {
        s->head->next->prev = NULL;
        s->head = s->head->next;
        free(newNode);
    }
    /* SAU: (deși așa mi-a crăpat):

      s->head = head->next; //nonempty list assumed
      free(newNode);
      if(s->head == NULL)
          s->tail = NULL; //list became empty
      else
          s->head->prev = NULL;*/
    s->length--;
}

void deleteLast()
{
    node *newNode = s->tail;

    if(newNode != NULL)
    {
        newNode->prev->next = NULL;
        s->tail = newNode->prev;
        free(newNode);
    }
    /* SAU: (deși așa mi-a crăpat):

        s->tail = tail->prev;
        if(s->tail ==NULL)
            s->head = NULL; //list became empty
    else
        s->tail->next = NULL;
    free(newNode);*/
    s->length--;
}

void deleteX(int x)
{
    if(s->head->value == x)
    {
        deleteFirst();
    }
    else if(s->tail->value == x)
    {
        deleteLast();
    }
    else
    {
        node* newNode = s->head;

        while(newNode->next != s->tail )
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
      s->length--;
}

void deleteAll()
{
    node *newNode;
    while(s->head != NULL)
    {
        newNode = s->head;
        s->head = s->head->next;
        free(newNode);
    }
    s->tail = NULL;
      s->length = 0;
}

void printAll(FILE *fileOutput)
{
    struct node *temp = s->head;
    while(temp != NULL)
    {
        fprintf(fileOutput,"%d ", temp->value);
        temp = temp -> next;
    }
    fprintf(fileOutput," \n");
}

void printFirstX(int value, FILE *fileOutput)
{
    node *newNode = s->head;
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
    node *newNode = s->tail;
    int i;
    for(i=0; ((i<value) && (newNode!= s->head)); i++)

    {
        fprintf(fileOutput,"%d ", newNode-> value);
        newNode=newNode->prev;
    }
    fprintf(fileOutput," \n");
}
