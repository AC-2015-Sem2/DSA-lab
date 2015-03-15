#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct s_NODE
{
    int data;
    struct s_NODE *next;
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
        tail=head;
    }
    else
    {
        newnode=(NODE*)malloc(sizeof(NODE));
        newnode->data=data;
        newnode->next=head;
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
        tail=head;
    }
    else
    {
        newnode=(NODE*)malloc(sizeof(NODE));
        newnode->data=data;
        newnode->next=NULL;
        tail->next=newnode;
        tail=newnode;
    }
}
void DF()/* delete first*/
{  if (head==NULL)
    return;
  if   (head==tail)
  {
      free(head);
      head=NULL;
      tail=NULL;
  }


    NODE *tmp;
    tmp=head;
    head=head->next;
    free(tmp);
   }


void DL()/*delete last*/
{
    if (head==NULL)
        printf("list is empty");
   if (head==tail)
   {
       free(tail);
       head=NULL;
       tail=NULL;
   }


        NODE *curr,*prev;
        curr=head;
        while (curr->next != NULL)
        {   prev=curr;
            curr=curr->next;
        }
        tail=prev;
        free(curr);

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
}

int DE(int x)
{
    NODE *temp, *prev;
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
                prev->next=temp->next;
                free(temp);
                return 1;
            }
        }
        else
        {
            prev=temp;
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
        fprintf(f2,"%d",p->data);
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
        fprintf(f2,"%d",p->data);
        p=p->next;
        cont++;
    }
    fprintf(f2,"\n");
}

void print_last_x(FILE *f2,int x)
{
	int		i;
	NODE	*curr;
	NODE	*start;

	curr = head;
	start = head;
	i = 0;
	while (curr != NULL)
	{
		if (i >= x)
			start = start->next;
		curr= curr->next;
		++i;
	}
	while (start != NULL)
	{
		fprintf(f2, "%d ", start->data);
		start = start->next;
	}
	fprintf(f2, "\n");
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

    while (fscanf(f1, "%s", str != EOF))
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

