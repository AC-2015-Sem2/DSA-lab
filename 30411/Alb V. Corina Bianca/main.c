#include <stdio.h>
#include <stdlib.h>
#include<string.h>

typedef struct nod{
    int data;
    struct nod* next;
    struct nod* prev;
} nodt;

typedef struct sentinel{
    nodt* first;
    nodt* last;
    int sent_size;
}SentinelT;

struct sentinel * sent;

void create_list(){ // creates the initial list
    nodt * p;
    p=(nodt*)malloc(sizeof(nodt));
    printf("give the first node");
    scanf("%d",&p->data);// reads the first node from the screen
    if ( sent->first==NULL){
        sent->first=p;
        sent->last=p;
        p->next=NULL;
        p->prev=NULL;
    }
    else {// in case the list already has a value, p->data will be inserted at the end
        sent->last->next=p;
        p->prev=sent->last;
        sent->last=p;
    }
}

void AF(int x){// adds a node at the front of the list
    nodt * p; // declares an empty node
    p=(nodt*)malloc(sizeof(nodt));//allocates memory
    if(sent->first==NULL){
        sent->first->data=x;
        sent->last->data=x;
        p=sent->first;
        p->next=NULL;
        p->prev=NULL;
        p->data=x;
    }
    else if (sent->first!=NULL){
        p->next=sent->first;
        p->data=x;
        p->prev=NULL;
        sent->first=p;
    }
}

void AL(int x){//adds at the end of the list
    nodt * p;
    p=(nodt*)malloc(sizeof(nodt));
    if(sent->last==NULL){
        sent->last->data=x;
        sent->first->data=x;
        p->data=x;
        p->next=NULL;
        p->prev=NULL;
    }
    else if (sent->last!=NULL){
        p->prev=sent->last;
        p->data=x;
        p->next=NULL;
        sent->last=p;
    }
}

int DF(){
    nodt * n;
    n=(nodt*)malloc(sizeof(nodt));
    if(sent->first==NULL){
        perror("there is nothing to delete in the list");
        return -1;
    }
    else if(sent->first!=NULL){
        n=sent->first->next;
        free(sent->first);
        sent->first=n;
        sent->first->prev=NULL;
    }
    return 0;
}

int DL(){
    if(sent->last==NULL){
        perror("there is no last node");
        return -1;
    }
    else if (sent->last!=NULL){
        nodt * n;
        n=(nodt*)malloc(sizeof(nodt));
        n=sent->last->prev;
        free(sent->last);
        sent->last=n;
        sent->last->next=NULL;
    }
    return 0;
}

void DOOM(){
    nodt * n;
    n=(nodt*)malloc(sizeof(nodt));
    while(sent->first!=NULL){
        n=sent->first;
        sent->first=n->next;
        free(n);
    }
}

void DE(int x){
    nodt * n;
    n=(nodt*)malloc(sizeof(nodt));
    n=sent->first;
    while(n->next!=NULL){
        if(n->data==x){
            nodt * p;
            p=(nodt*)malloc(sizeof(nodt));
            p=n->next;
            p->prev=n->prev->prev;
            free(n);
        }
    }
}

void PRINT_ALL(){
    FILE *g;
    g=fopen("open.txt","w");
    nodt * p;
    p=(nodt*)malloc(sizeof(nodt));
    p=sent->first;
    while (p!=NULL){
        fprintf(g,"%d ",p->data);
        p=p->next;
    }
    fclose(g);
}

int sentinel_size(){
    nodt * p;
    p=(nodt*)malloc(sizeof(nodt));
    sent->sent_size = 0;
    p=sent->first;
    while(p!=NULL){
        p=p->next;
        sent->sent_size ++;
    }
    return sent->sent_size;
}

void PRINT_F(int x, int n){
    FILE * g;
    g=fopen("output.txt","w");
    nodt * p;
    p=(nodt*)malloc(sizeof(nodt));
    p=sent->first;
    if(x<n){
        printf("there are not %d elements in the list",x);
    }
    while(x>0){
        fprintf(g,"%d ",p->data);
        p=p->next;
        x--;
    }
    fclose(g);
}

void PRINT_L(int x, int n){
    FILE * g;
    g=fopen("output.txt","w");
    if (x<n){
        fprintf(g,"there are not %d elements in the list",x);
    }
    nodt *p ;
    p=(nodt*)malloc(sizeof(nodt));
    p=sent->first;
    while(x>0){
        x--;
        fprintf(g,"%d ",p->data);
        p=p->next;
    }
    fclose(g);
}

int main()
{
    FILE *f;
    char *command;
    int nr;
    f=fopen("lists.txt","r");
    if (f==NULL){
        perror("cannot open file!");
        return -1;
    }
    int n;
    command=(char*)malloc(sizeof(char)*10);
    while (fscanf(f,"%c %d",command,&nr)>0){
        if (strcmp(command,"AF")){
            AF(nr);
        }
        else if (strcmp(command,"AL")){
            AL(nr);
        }
        else if (strcmp(command,"DF")){
            DF();
        }
        else if (strcmp(command,"DL")){
            DL();
        }
        else if (strcmp(command,"DOOM_THE_LIST")){
            DOOM();
        }
        else if (strcmp(command,"DE")){
            DE(nr);
        }
        else if (strcmp(command,"PRINT_ALL")){
            PRINT_ALL();
        }
        else if (strcmp(command,"PRINT_F")){
            n=sentinel_size();
            PRINT_F(nr,n);
        }
        else if (strcmp(command,"PRINT_L")){
            n=sentinel_size();
            PRINT_L(nr,n);
        }
        else
            printf("there is an invalid command");
    }

    return 0;
}
