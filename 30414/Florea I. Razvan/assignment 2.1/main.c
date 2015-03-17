#include <stdio.h>
#include <stdlib.h>

typedef struct StructNod
   {
      int value;
      struct StructNod *next;
      struct StructNod *prev;
   }nod;

nod *head, *tail;

typedef struct Sant
   {
      nod *head;
      nod *tail;
      int noe;    /*noe = number of elements*/
   }santinel;

santinel *sa;

void AddFirst(int data)
  {
    if (head==NULL)
         {
            head=(nod*)malloc(sizeof(nod));
            tail=head;
            head->value=data;
            head->next=NULL;
            head->prev=NULL;
         }
     else
        {
          nod *newnode=(nod*)malloc(sizeof(nod));
          newnode->value=data;
          newnode->next=head;
          newnode->prev=NULL;
          head->prev=newnode;
          head=newnode;

         }
  }

void AddLast(int data)
   {
       if(tail==NULL)
           {
              tail=(nod*)malloc(sizeof(nod));
              head=tail;
              tail->value=data;
              tail->next=head;
              tail->prev=NULL;
           }
       else
          {
             nod *newnode=(nod*)malloc(sizeof(nod));
             newnode->value=data;
             newnode->next=NULL;
             newnode->prev=tail;
             tail->next=newnode;
             tail=newnode;
          }
   }

void DeleteFirst()
  {
     if (head!=NULL)
         {
            nod *aux=head;
            head->next->prev=NULL;
            head=head->next;
            free(aux);
            /*verify the existence of a new head*/
            if (head==NULL)
                tail=NULL;
         }
  }

void DeleteLast()
   { /*search for the tail*/
      if(head!=NULL)
        {
           nod *aux;
           if(tail!=NULL)
              {
                aux=head;
                while(aux->next!=tail)
                     aux=aux->next;
                /*the element before the tail becomes the new tail*/
                tail->prev=NULL;
                tail=aux;
                free(aux->next);
              }
        }
        else
           {
              free(head);
              head=NULL;
           }
   }

void DoomTheList()
   {
     while (head!=NULL)
        DeleteFirst();
   }

void DeleteElement(int elem)
   {
     if(head!=NULL)
        {
           nod *FirstAux, *SecondAux;
           /*the searched element is the very first one, the head*/
           if(head->value==elem)
              {
                 FirstAux=head;
                 head=head->next;
                 free(FirstAux);
                 head->prev=NULL;
              }
           /*the searched element is inside the list*/
           if(tail!=NULL)
              {
                 SecondAux=head;
                 FirstAux=head->next;
                 while((FirstAux->value!=elem)&&(FirstAux!=tail))
                    {
                       FirstAux=FirstAux->next;
                       SecondAux=SecondAux->next;
                    }
                 /*the searched element is the last one, the tail*/
                 if((FirstAux==tail)&&(tail->value==elem))
                    {
                       SecondAux->next=NULL;
                       tail=SecondAux;
                       free(FirstAux);
                    }
                  /*the searched element is somewhere between the head and the tail*/
                 if((FirstAux!=tail)&&(FirstAux->value=elem))
                    {
                        SecondAux->next=FirstAux->next;
                        FirstAux->next->prev=FirstAux->prev;
                        free(FirstAux);
                    }
              }
        }
   }

 void PrintAllInFisier()
   {
      FILE *pfo;
      pfo=fopen("output.dat","w");
      nod* aux=head;
      while(aux!=NULL)
         {
            fprintf(pfo,"%d",aux->value);
            aux=aux->next;
         }
      fprintf(pfo,"\n");
      fclose(pfo);
   }

void PrintFirstXInFisier(int nrelem)
   {
     FILE *pfo;
     pfo=fopen("output.dat","w");
     nod *aux=head;
     int i=1;
     while((aux!=NULL)&&(i<=nrelem))
        {
           fprintf(pfo,"%d",aux->value);
           aux=aux->next;
           i++;
        }
     fclose(pfo);
   }

void PrintLastXInFisier(int nrelem)
   {
      FILE *pfo;
      pfo=fopen("output.dat","w");
      nod *aux=tail;
      int i=1;
      while(i<=nrelem)
         {
            fprintf(pfo,"%d",aux->value);
            aux=aux->prev;
            i++;
         }
   }
int main()
{
 char Comanda[30];
   int Element;
   FILE *pfi;
   pfi=fopen("input.dat","r");
   FILE *pfo;
   pfo=fopen("output.dat","w");
   while(fscanf(pfi,"%s %d", Comanda, &Element)!=EOF)
      {
         if(strcmp(Comanda,"AF")==0)
            AddFirst(Element);
         if(strcmp(Comanda,"AL")==0)
            AddLast(Element);
         if(strcmp(Comanda,"DF")==0)
            DeleteFirst();
         if(strcmp(Comanda,"DL")==0)
            DeleteLast();
         if(strcmp(Comanda,"DOOM_THE_LIST")==0)
            DoomTheList();
         if(strcmp(Comanda,"DE")==0)
            DeleteElement(Element);
         if(strcmp(Comanda,"PRINT_ALL")==0)
            PrintAllInFisier();
         if(strcmp(Comanda,"PRINT_F")==0)
            PrintFirstXInFisier(Element); /*in this case Element represents the number of elements to be printed, NOT a value*/
                                          /*in the list*/
         if(strcmp(Comanda,"PRINT_L")==0)
            PrintLastXInFisier(Element);  /*Element is also the nr of elements*/
      }
   fclose(pfi);
   fclose(pfo);
   return 0;
}
