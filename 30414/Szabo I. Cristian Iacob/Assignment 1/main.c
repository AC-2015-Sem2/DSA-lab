#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{ int data;
  struct node *next;
}NODE;

NODE *head, *tail;

void print_all(FILE *g)
{ NODE* x=head;
  while(x!=NULL)
  {
   fprintf(g,"%d ", x->data);
   x = x->next;
  }
  fprintf(g,"\n");
}


void Add_first(int data)
{ if(head == NULL)
   { head = (NODE*)malloc(sizeof(NODE));
     head->data = data;
     head->next = NULL;
     tail = head;
   }
   else
   {
    NODE *new;
    new = (NODE*)malloc(sizeof(NODE));
    new->data = data;
    new->next = head;
    head = new;
    }
}

void Add_last(int data)
{ if(head == NULL)
   { head = (NODE*)malloc(sizeof(NODE));
     head->data = data;
     head->next = NULL;
     tail = head;
   }
   else
   { NODE *new;
     new = (NODE*)malloc(sizeof(NODE));
     new->data=data;
     new->next = NULL;
     tail->next = new;
     tail = new;
    }
 }

void Delete_first()
{
  NODE *new;
  new = head->next;
  free(head);
  head = new;
}

void Delete_last()
{
 NODE *x=head;
 while(x->next != tail)
  x = x->next;
 x->next=NULL;
 free(tail);
 x=tail;
 }

void Doom_list()
{ NODE *x=head;
  while(x!=NULL)
    { head = x->next;
      free(x);
      x=head;
    }
   tail=NULL;
}
void Delete_x(int data)
{ NODE *x=head, *previous=head;
  while(x!=NULL)
  {
      if(x->data==data)
      { if(head==x)
          head = x->next;
        if(tail==x)
        { previous->next=NULL;
          tail = previous;
        }
        previous ->next = x->next;
        free(x);
        return ;
      }
      else
       { previous =x;
         x=x->next;
       }
    }
}
void print_f(FILE *g,int data)
{ NODE *x=head;
  while(x!=NULL && data!=NULL)
  {
      fprintf(g,"%d ",x->data);
      data=data-1;
      x= x->next;
  }
  fprintf(g,"\n");
}

void print_l(FILE *g, int data)
{
    NODE *x=head, *start=head;
    while(x!=NULL)
    {
        if (data == 0)
           start = start->next;
        else
          data=data-1;
         x= x->next;
    }
    while(start!=NULL)
    { fprintf(g,"%d ",start->data);
      start = start->next;
    }
    fprintf(g,"\n");
}
int main()
{ 	FILE	*f, *g;
	char	*wtd; //what to do
	int		data;
	f = fopen("input.dat", "r");
    g = fopen("output.dat", "w");
    if(f==NULL)
	   perror("File error");
    if(g==NULL)
	   perror("File error");
	wtd = (char *)malloc(sizeof(char) * 20);

	while (fscanf(f, "%s", wtd) != EOF)
	{
		fscanf(f, "%d", &data);
		if (strcmp(wtd, "AF") == 0)
			Add_first(data);
		else if (strcmp(wtd, "AL") == 0)
			Add_last(data);
		else if (strcmp(wtd, "DF") == 0)
			Delete_first();
		else if (strcmp(wtd, "DL") == 0)
			Delete_last();
		else if (strcmp(wtd, "DOOM_THE_LIST") == 0)
			Doom_list();
		else if (strcmp(wtd, "DE") == 0)
			Delete_x(data);
		else if (strcmp(wtd, "PRINT_ALL") == 0)
			print_all(g);
		else if (strcmp(wtd, "PRINT_F") == 0)
			print_f(g, data);
		else if (strcmp(wtd, "PRINT_L") == 0)
			print_l(g, data);
	}
	fclose(f);
	fclose(g);
  return 0;

}
