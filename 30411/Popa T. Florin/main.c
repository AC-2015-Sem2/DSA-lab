#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <strings.h>

typedef struct node
{
    int val;
    struct node *link;
} node;
node *head,*tail;
FILE *f;
FILE *g;

void add_first(int x){
    if(head==NULL){
head=(node*)malloc(sizeof(node));
head->val=x;
head->link=NULL;
    }
    else if(tail==NULL){
        tail=head;
        node *temp=(node*)malloc(sizeof(node));
        temp->val=x;
        temp->link=tail;
        head=temp;
    }
    else{
        node *temp=(node*)malloc(sizeof(node));
        temp->val=x;
        temp->link=head;
        head=temp;
    }
}

void add_last(int x)
{
    node *temp,*right;
    temp=(node*)malloc(sizeof(node));
    temp->val=x;
    right=(node*)head;
    while(right->link!=NULL)
        right=right->link;
    right->link=temp;
    right=temp;
    right->link=NULL;

}

void del_first(){
        node* temp=head;
        head=temp->link;
        free(temp);
}

void del_list(){
        node *temp;
    while( (temp=head) ){
        head=temp->link;
        free(temp);
                        }
}

int del_last(){
    node *temp=head;
    node *aux;
    if(head==NULL){
        return 0;
    }
    if(head->link==NULL){
        free(head);
        head=NULL;
    }
    else{
        while(temp->link!=NULL){
            aux=temp;
            temp=temp->link;
        }
        free(aux->link);
        aux->link=NULL;
    }
    return 0;
}

void del_val(int x){
    node *temp=head;
    node *aux=0;

   while(temp!=NULL)
    {
        if(x==(*temp).val)
        {
               break;
        }
        aux=temp;
        temp=(*temp).link;
    }
    if(temp!=0){
        if(temp==head){
            temp=head;
            head=temp->link;
            free(temp);
        }
        else{
            aux->link=temp->link;
            free(temp);
        }
    }
}


void print_all(){

    node *temp=head;
    while(temp!=NULL)
    {
        fprintf(f,"%d ",(*temp).val);
        temp=(*temp).link;
    }
    fprintf(f,"\n");
}

void print_first(int x){
    node *temp=head;
    int aux=0;
    while(temp!=NULL && aux<x)
    {
        fprintf(f,"%d ",(*temp).val);
        temp=(*temp).link;
        aux=aux+1;
    }
    fprintf(f,"\n");
}

void print_last(int x){
    int aux=0,i=0;
    node *temp=head;
    while(temp!=NULL){
        temp=temp->link;
        aux=aux+1;
    }   temp=head;
    while(temp!=NULL){
        if(i>=aux-x){
            fprintf(f,"%d ",temp->val);
        }
        i=i+1;
        temp=temp->link;
    }
    fprintf(f,"\n");
}

void read(){

    FILE *g;
    char line[100];
    char *token;
    int nr;

    g=fopen("input.dat","r");
        if (g==0){
            printf( "Error! Could not open file\n" );
        }
        else
        {
            while  ( fgets(line,100,g)!=NULL )
            {
                token=strtok(line," ,.-\n");
                while(token!=NULL){
                   if(strcmp(token,"AF")==0)
                    {   token=strtok(NULL," ,.-\n");
                        nr=atoi(token);
                        add_first(nr);
                    }
                     else if(strcmp(token,"AL")==0){
                        token=strtok(NULL," ,.-\n");
                        nr=atoi(token);
                        add_last(nr);
                    }
                    else if(strcmp(token,"DE")==0){
                        token=strtok(NULL," ,.-\n");
                        nr=atoi(token);
                        del_val(nr);
                    }
                    else if(strcmp(token,"PRINT_F")==0){
                        token=strtok(NULL," ,.-\n");
                        nr=atoi(token);
                        print_first(nr);
                    }
                    else if(strcmp(token,"PRINT_L")==0){
                        token=strtok(NULL," ,.-\n");
                        nr=atoi(token);
                        print_last(nr);
                    }
                    else if(strcmp(token,"DF")==0){
                    del_first();
                    }
                     else if(strcmp(token,"DL")==0){
                    del_last();
                    }
                     else if(strcmp(token,"PRINT_ALL")==0){
                    print_all();
                    }
                    else if(strcmp(token,"DOOM_THE_LIST")==0){
                    del_list();
                    }
                    token=strtok(NULL," ,.-\n");
                }
            }
        }
        fclose( g );
}

int main()
{
    f=fopen("output.dat","w");
    read();
    fclose(f);
    return 0;
}
