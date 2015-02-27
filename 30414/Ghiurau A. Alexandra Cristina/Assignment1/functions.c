#include "functions.h"

void printAll(FILE *fileOutput)
{
    node *aux = head; //we store the head in the variable aux
    while(aux!=NULL)
    {
        fprintf(fileOutput,"%d ", aux->value);
        aux = aux->next;
    }
    fprintf(fileOutput," \n");
}

void addFirst(int value)
{
    if(head==NULL)
    {
        head = (node*)malloc(sizeof(node));
        head->next = NULL;
        tail=head;
        head->value = value;

    }
    else
    {
        node *newNode = (node*)malloc(sizeof(node));
        newNode->next = head;
        head=newNode;
        newNode->value = value;
    }
}

void addLast(int value)
{
    if(head==NULL)
    {
        head = (node*)malloc(sizeof(node));
        tail = head;
        head->next = NULL;
        head->value = value;
    }
    else
    {
        node *newNode = (node*)malloc(sizeof(node));
        newNode->value = value;
        newNode->next =  NULL;
        tail->next = newNode;
        tail= newNode;
    }

}

void deleteFirst()
{
    if(head==NULL) //there is no node, the list is empty
    {
        printf("The list is already empty!");
    }
    else
    {
        if  (head==tail) //in this case we only have one element, we make it NULL
        {
            free(head);
            head= NULL;
        }
        else //>2 elements
        {
            node *auxNode;
            auxNode = head; //aux takes the value of the head
            head = head->next;// head is "right shifted" with "one bit" => "new" head
            free(auxNode);// "old" head deleted
        }
    }
}

void deleteLast()
{
    if(head==NULL)
    {
        printf("The list is already empty!");
    }
    else
    {
        if  (head==tail)
        {
            deleteFirst();
        }
        else //>2 elements
        {
            node *aux = tail; //we create an auxiliary variable of type node; we store the tail in aux, so we can delete it after we make some operations with tail (we "shift left" it)
            node *previousNode;
            previousNode = head;//with the previousNode variable we go from head to the previous of the tail element (the left element before tail)
            while(previousNode->next!=tail)
            {
                previousNode=previousNode->next;//we 'store' the previousNode variable as the left element before our tail, and make it the new tail
            }
            tail=previousNode;
            tail->next=NULL;
            free(aux);
        }
    }
}

void deleteAll()
{
    if(head==NULL)
    {
        printf("The list is already empty");
    }
    else
    {
        if  (head==tail)
        {
            deleteFirst();
        }
        else
        {
            //  node *auxNode=head; we would have used this line to delete (at the end) the head. But we will use the already created function "DeleteFirst"
            node *previous;
            while(head->next!=NULL)
            {
                previous = head;
                head=head->next;
                free(previous); //we delete the element before the "current" one
            }
            deleteFirst();
        }
    }
}

int deleteX(int value) //it is an "int" function which returns 1 (true) if such element was found and deleted, and 0 if no such element
{
    if(head==NULL)
    {
        printf("The list is empty!");
        return 0;
    }
    node *aux, *previous;
    aux=head;
    while(aux!=NULL)
    {
        if(aux->value == value) //we will go through all the list, if x is found (aux->value == x) we will do the following "operations"
        {
            if(aux == head) //if the element x which was found, is the data from the head, we have to delete the head, and "make" the next node be the new head
            {
                head = aux->next;
                free(aux); //or deleteFirst() -if so, without the code line above ^;
                return 1;
            }
            else
            {
                previous->next = aux-> next; //since aux stores the "x - data"; it has to be deleted
                // in order to do that we make sure that we "jump" over the aux, so the link will have continuity and we can delete aux
                free(aux);
                return 1;
            }
        }
        else
        {
            previous = aux;
            aux = aux->next; // escaping condition from loop (we go through each node)
        }
    }
    return 0;
}

void printFirstX(int value, FILE *fileOutput)
{

    node *aux = head;
    int i;
    for(i=0; (i<value)&&(aux!=NULL); i++) //we go traverse the list ("chain") from the head till the given value x, and print them out!
    {
        fprintf(fileOutput,"%d ", aux-> value);
        aux=aux->next;
    }
    fprintf(fileOutput," \n");
}

void printLastX(int value,  FILE *fileOutput)
{
    node *aux=head;
    int counter = 0; // in the variable counter we sill store the length of the 'chain' (the number of elements/nodes in the list)
    while(aux!=NULL)
    {
        aux=aux->next; //we go through all the list
        counter++; //counter = nr of elements/ length of the 'chain'
    }
    aux = head; //reinitialize the node aux to head as we want to traverse the node again, but only till position counter - x (length of list minus the given value)
    int i;
    for(i=0; (i<(counter-value))&&(aux!=NULL); i++) // we traverse the list once more from the first node (head) BUT only to the given value "x"; without printing them.
        //We just "cross" them. We will then have our aux node at the position counter-value +1 => we will traverse the list from here till the end
    {
        aux=aux->next;
    }
    while(aux!=NULL)
    {
        fprintf(fileOutput,"%d ", aux-> value); //print only the last x the in file "output.dat"
        aux= aux->next;
    }
    fprintf(fileOutput," \n");
}
