#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct s_NODE
{
    int data;
    struct s_NODE *next;
    struct s_NODE *prev;
} NODE;
NODE *head,*tail ;

void AF(int data) /*addFirst*/
{
    NODE *newnode;
    if (head==NULL)
    {
        head= (NODE*)malloc(sizeof(NODE));
        head->data=data;
        head->next=NULL;
        head->prev=NULL;
        tail=head;
    }
    else
    {
        newnode=(NODE*)malloc(sizeof(NODE));
        newnode->data=data;
        newnode->next=head;
        newnode->prev=NULL;
        head=newnode;
    }
}

void AL(int data) /*addLast*/
{
    NODE *newnode;
    if(head==NULL)
    {
        head=(NODE*)malloc(sizeof(NODE));
        head->data=data;
        head->next=NULL;
        head->prev=NULL;
        tail=head;
    }
    else
    {
        newnode=(NODE*)malloc(sizeof(NODE));
        newnode->data=data;
        newnode->next=NULL;
        newnode->prev=tail;
        tail->next=newnode;  /* IS THIS STATEMENT REDUNDANT AS I'VE ALREADY MENTIONED THAT PREVIOUS STATEMENT?*/
        tail=newnode;
    }
}
void DF()/* delete first*/
{  if (head==NULL)
    return;
    else
  if   (head==tail)
  {
      free(head);
      head=NULL;
      tail=NULL;
  }
  else
{
    NODE *tmp;
    tmp=head;
    head=head->next;
    free(tmp);
   }}


void DL()/*delete last*/
{
    if (head==NULL)
        printf("list is empty");
  else if (head==tail)
   {
       free(tail);
       head=NULL;
       tail=NULL;
   }
   else
{
        NODE *temp;
        temp=tail;
        tail=tail->prev;
        free(temp);
}
    }


void DOOM_THE_LIST()/*deletes all*/
{
    NODE *temp;
    while (head != NULL)
    {
        temp = head;
        head = temp->next;
        free(temp);
    }
    head=NULL;
    tail=NULL;
}

int DE(int x)
{
    NODE *temp,*p;
    temp=head;
    while(temp!=NULL)
    {
        if(temp->data==x)
        {
            if(temp==head)
            {
                head=temp->next;
                free(temp);
                return 1;
            }
            else
            {
                p->next=temp->next;
                free(temp);
                return 1;
            }
        }
        else
        {
            p=temp;
            temp= temp->next;
        }
    }
    return 0;
}


void print_all(FILE *f2)
{
    NODE *p;
    p=head;
    while(p !=NULL)
    {
        fprintf(f2,"%d ",p->data) ;
        p=p->next;
    }
    fprintf(f2,"\n");
}

void print_x(FILE *f2,int x)
{
    int cont;
    NODE *p;
    cont=0;
    p=head;
    while((p->next !=NULL)&&(cont<x))
    {
        fprintf(f2,"%d ",p->data) ;
        p=p->next;
        cont++;
    }
    fprintf(f2,"\n");
}

void print_last_x(FILE *f2,int x)
{
     int cont;
    NODE *p;
    cont=0;
    p=tail;
    while((p->prev !=NULL)&&(cont<x))
    {
        fprintf(f2,"%d ",p->data) ;
        p=p->prev;
        cont++;
    }
    fprintf(f2,"\n");

}
int main()
{   FILE *f1;
    FILE *f2;
    char * str;
    int data;
    f1=fopen("input.txt","r");
    f2=fopen("output.txt","w");

    head=NULL;
    tail=NULL;
   str=(char*)malloc(sizeof(char)*20);

    while (fscanf(f1, "%s", str )!= EOF)
	{
		fscanf(f1, "%d", &data);
		if (strcmp(str, "AF") == 0)
			AF(data);
		else if (strcmp(str, "AL") == 0)
			AL(data);
		else if (strcmp(str, "DF") == 0)
			DF();
		else if (strcmp(str, "DL") == 0)
			DL();
		else if (strcmp(str, "DOOM_THE_LIST") == 0)
			DOOM_THE_LIST();
		else if (strcmp(str, "DE") == 0)
			DE(data);
		else if (strcmp(str, "PRINT_ALL") == 0)
			print_all(f2);
		else if (strcmp(str, "PRINT_F") == 0)
			print_x(f2, data);
		else if (strcmp(str, "PRINT_L") == 0)
			print_last_x(f2, data);
	}
	fclose(f1);
	fclose(f2);
	return (0);
}

