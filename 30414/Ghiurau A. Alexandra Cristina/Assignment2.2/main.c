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


typedef struct sant
{
    node* head;
    node* tail;
    node* front;
    node* rear;
    int nrOfPeople; //n people/ n elements

} santinel;

santinel* s;


/* I am adding the seconds from ths first line of the input file into a singly linked list */
void addLast(int seconds)
{

    node *newNode = (node*)malloc(sizeof(node));
    newNode->seconds = seconds;
    newNode->next=NULL;
    if (s->front==NULL)
    {
        s->front=newNode;
        s->rear=newNode;
    }
    else
    {
        s->rear->next=newNode;
        s->rear=newNode;
    }
}

void deleteFirst()
{
    if(s->front==NULL)
    {
        printf("The list is already empty!");
    }
    else
    {
        if  (s->front==s->rear)
        {
            free(s->front);
            s->front= NULL;
        }
        else
        {
            node *auxNode;
            auxNode = s->front;
            s->front = s->front->next;
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
    if((s->head == NULL) && (s->tail == NULL))
    {
        s->head = s->tail = temp;
        return;
    }
    s->tail->next = temp;
    s->tail = temp;
    s->nrOfPeople ++;
}

void dequeue()
{
    struct node* temp = s->head;
    if(s->head == NULL)
    {
        printf("Queue is Empty\n");
        return;
    }
    if(s->head == s->tail)
    {
        s->head = s->tail = NULL;
    }
    else
    {
        s->head = s->head->next;
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

    int cashiersMoney = 0;
    int aux = 0;

    while(fscanf(file,"%s %d %d \n", name, &money, &time)!=EOF)
    {
        enqueue(money, time);
    }

    while((s->head != NULL) && (s->front !=NULL ))
    {
        node *temp = s->head;
        node *temp2 = s->front;

        int sec = temp2->seconds;

        if(temp2->seconds >= temp->time)
        {
            cashiersMoney = cashiersMoney + temp->money;
            temp2 = temp2 +temp->money;
            deleteFirst();
        }
        fprintf(fileOutput,"\nAfter %d seconds: %d", sec, cashiersMoney);
        dequeue();
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

    s = (santinel*)malloc(sizeof(santinel));
    s->head = NULL;
    s->tail = NULL;
    s->front = NULL;
    s->rear = NULL;

    readFromFile(file, fileOutput);

    fclose(fileOutput);
    return 0;
}
