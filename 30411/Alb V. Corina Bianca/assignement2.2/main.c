#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE * f;

typedef struct time{
    int tdata;
    struct time * next;
    struct time * prev;
}timeT;

typedef struct sentinel{
    timeT* first;
    timeT* last;
}sentinelT;

struct sentinel *senti;

typedef struct customers{
    int m,t;
    char *name;
    struct customers * next;
}customersT;

void create_time_list(){//CREATES AN EMPTY LIST FOR THE TIME
    timeT * p;
    senti->first=NULL;
    senti->last=NULL;
    p=NULL;
    p->next=NULL;
    p->prev=NULL;
}

void time_list(char *numbers){
    timeT *p;
    p=(timeT*)malloc(sizeof(timeT));
    p->tdata=(int)strtok(numbers," ");
    senti->first=p;
    while(numbers!=NULL){
        timeT *n;
        n=(timeT*)malloc(sizeof(timeT));
        p->next=NULL;
        n=p->next;
        n->tdata=(int)strtok(NULL," ");
        p=n;
    }
    senti->last=p;
}

void problem(){
    timeT * p;
    FILE *g;
    g=fopen("output.txt","w");
    int sec=0,money=0;
    p=senti->first;
    while(p!=NULL){
        while(sec<p->tdata){
            customersT *client;
            client=(customersT*)malloc(sizeof(customersT));
            fscanf(f,"%c %d %d",client->name, &client->m, &client->t);
            sec=sec+client->t;
            money=money+client->m;
            free(client);
        }
       fprintf(g,"After %d seconds: %d\n",sec,money);
       p=p->next;
    }
    fclose(g);
}

int main()
{
    char *numbers;
    numbers=(char*)malloc(sizeof(char)*100);
    f=fopen("input.txt","r");
    fscanf(f,"%c",numbers);
    create_time_list();
    time_list(numbers);
    problem();
    fclose(f);
    return 0;
}
