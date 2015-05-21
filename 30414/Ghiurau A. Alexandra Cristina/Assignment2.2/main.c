#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int money; // x ruble
    int time; //  y time
    int seconds; //the given seconds from the first line of the input file
    //char *customerName; //name of the customer
    struct node* next;
} node;

typedef struct listT
{
    struct node *head;
    struct node *tail;
} listT;
listT *firstList;
listT *secondList;


/* I am adding the seconds from this first line of the input file into a singly linked list */
void addLast(int seconds)
{

    node *newNode = (node*)malloc(sizeof(node));
    newNode->seconds = seconds;
    newNode->next=NULL;
    if (firstList->head==NULL)
    {
        firstList->head=newNode;
        firstList->tail=newNode;
    }
    else
    {
        firstList->tail->next=newNode;
        firstList->tail=newNode;
    }
}

void deleteFirst()
{
    if(firstList->head==NULL)
    {
        printf("The list is already empty!");
    }
    else
    {
        if  (firstList->head==firstList->tail)
        {
            free(firstList->head);
            firstList->head= NULL;
        }
        else
        {
            node *auxNode= firstList->head;
            firstList->head = firstList->head->next;
            free(auxNode);
        }
    }
}

void enqueue(int x, int y) //this adds last
{
    struct node* temp =(struct node*)malloc(sizeof(struct node));
    temp->money = x;
    temp->time = y;
    temp->next = NULL;
    if((secondList->head == NULL) && (secondList->tail == NULL))
    {
        secondList->head = secondList->tail = temp;
        return;
    }
    secondList->tail->next = temp;
    secondList->tail = temp;
}

void dequeue()
{
    /*if(secondList->head == NULL)
    {
        printf("Queue is Empty\n");
    }
    if(secondList->head == secondList->tail)
    {
        free(secondList->head);
        secondList->head= NULL;
    }
    else
    {
        node* temp = secondList->head;
        secondList->head = secondList->head->next;
        free(temp);
    }*/

    node* temp = secondList->head;
    if(secondList->head == NULL)
    {
        printf("Queue is Empty\n");
        return;
    }
    if(secondList->head == secondList->tail)
    {
        secondList->head = secondList->tail = NULL;
    }
    else
    {
        secondList->head = secondList->head->next;
    }
    free(temp);

}

void readFromFile(FILE *file, FILE *fileOutput)
{
    char line[1000];
    int money = 0;
    int time = 0;
    int seconds = 0;
    int counter = 0;
    fgets(line, sizeof(line), file);
    char *tok = strtok(line,  " \n");

    while(tok != NULL)
    {
        fscanf(file,"%d", &seconds);
        seconds = atoi(tok);
        counter ++;
        addLast(seconds);
        tok = strtok(NULL, " ");
    }
    printf("%d\n", counter);

    char *name;
    name = (char*)malloc(sizeof(char));


    while(fscanf(file,"%s %d %d \n", name, &money, &time)!=EOF)
    {
        enqueue(money, time);
    }

    int cashiersMoney = 0;
    int timeLeft = 0;
    int timePassed = 0;

    while (firstList->head != NULL)
    {
        int sec2 = firstList->head->seconds;
        timeLeft = firstList->head->seconds - timePassed ;

        while ((secondList->head != NULL) && ( timeLeft  >= secondList->head->time))
        {
            cashiersMoney = cashiersMoney + secondList->head->money;
            timePassed  += secondList->head->time;
            timeLeft -= timePassed;
            dequeue();
        }
        deleteFirst();
        printf("\nAfter %d seconds: %d", sec2, cashiersMoney);
        fprintf(fileOutput,"\nAfter %d seconds: %d", sec2, cashiersMoney);
    }

}


int main()
{

    FILE *file, *fileOutput;
    file= fopen("input.dat", "r");

    if(file== NULL)
    {
        perror("Cannot open file");
        return -100;
    }
    fileOutput= fopen("output.dat","w");

    firstList = (listT*)malloc(sizeof(listT));
    secondList = (listT*)malloc(sizeof(listT));
    firstList->head = NULL;
    firstList->tail = NULL;
    secondList->head = NULL;
    secondList->tail = NULL;

    readFromFile(file, fileOutput);

     printf("Done\n");
    fclose(fileOutput);
    return 0;
}
