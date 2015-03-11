#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node
  {
  	int value;
    struct node* next;
	}node;

 FILE *in ,*out;
 node *head ,*tail;

   void  add_last(int value)
   		{if(head==NULL)
   		    {
            head=(node*)malloc(sizeof(node));
   		    head->value=value;
   		    head->next=NULL;
   		    tail=head;
            }
        else
   		  {node* k=(node*)malloc(sizeof(node));
   		  k->value=value;
   		  k->next=NULL;
   		  tail->next=k;
   		  tail=k;
   		  }
   		  }


   void   add_first(int value)
			{
				if(head==NULL)
					{
						head=(node*)malloc(sizeof(node));
						head->value=value;
						head->next=NULL;
						tail=head;
					}
		      else
		      {
		      	node* k=(node*)malloc(sizeof(node));
		      	k->value=value;
		      	k->next=head;
		      	head=k;
		      }

	  }






    void delete_element(int p)
		{node *g1,*g;
		 g1=NULL;
		 g=head;

		 while(g!=NULL)
		 {if(g->value==p)break;
		 g1=g;
		 g=g->next;

		}
		if(g!=NULL)
		{
			if(g==head)
			{
				head=head->next;
				if(head==NULL)
				tail=NULL;
			}
			else
			{
				g1->next=g->next;
				if(g==tail)
				tail=g1;
			}
		}}

void	print_first(int x)
		{
			int i=1;
   node* k=head;
    while(i<=x)
    {
        if(k!=NULL){
       fprintf(out,"%d ",k->value);
       k=k->next;
        i++;}
        else break;
    }
    fprintf(out,"\n");
		}


    int LenghtOfList()
{
  node* k=head;
  int l=0;
    while (k!=NULL)
 {
    l++;
    k=k->next;
 }
  return l;
}


 void	print_last(int x)
 	{
 	    int i=1,n;
   node* k=head;
   n=LenghtOfList();
   while(i<=n-x)
    {
       if(k!=NULL){
       k=k->next;
        i++;}
        else break;
    }
    while(i<=n)
    {
        if(k!=NULL){
        fprintf(out,"%d ",k->value);
        k=k->next;
        i++;}
        else break;
    }
    fprintf(out,"\n");

 	}

 void print_list()
{
    node* other=head;
    while(other!=NULL)
    {
        fprintf(out,"%d ",other->value);
        other=other->next;
    }
    fprintf(out,"\n");
}


 void	doom_the_list()
 		{
 			node* k;
    while (head!= NULL )
    {
        k = head;
        head=head->next;
        free(k);
    }
    tail=NULL;

 		}

 void	delete_first()
 		{node *k;
 		 if(head==NULL)
 		 {
 		 	k=head;
 		 	head=head->next;
 		 	free(k);
 		 	if(head==NULL)
 		 	tail=NULL;
 		 }

 		}


 void	delete_last()
 		{node *g,*g1;
 		g1=NULL;
 		g=head;
 		if(g!=NULL)
 		{
 			while(g!=tail)
 			{
 				g1=g;
 				g=g->next;
 			}
 			if(g==head)
 			{
 				head=NULL;
 				tail=NULL;
 			}
 			else
 			{
 				g1->next=NULL;
 				tail=g1;
 			}

 		}}

int main()
{
   char s[50];
   int x;

   in = fopen("DataIn.txt","r");
   out= fopen("DataOut.txt","w");



   while((fscanf(in,"%s %d",s,&x)!=EOF))
    {printf("%s %d\n",s,x);
       if(!strcmp(s,"AL"))
    	       add_last(x);
    	if(!strcmp(s,"AF"))
    	     	add_first(x);
    	if(!strcmp(s,"DE"))
    		delete_element(x);
    	if(!strcmp(s,"PRINT_F"))
    		print_first(x);
  		if(!strcmp(s,"PRINT_L"))
    			print_last(x);
    	if(!strcmp(s,"PRINT_ALL"))
   				print_list();
 		if(!strcmp(s,"DOOM_THE_LIST"))
   				doom_the_list();
    	if(!strcmp(s,"DF"))
   				delete_first();
    	if(!strcmp(s,"DL"))
    			delete_last();
            strcpy(s,"");

    }
	return 0;
}
