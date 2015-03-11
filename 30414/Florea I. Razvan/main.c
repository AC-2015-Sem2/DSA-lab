#include <stdio.h>
#include <stdlib.h>

typedef struct StructuraNodului
    {
      int data;
      struct StructuraNodului *next;
    }nod;

   nod *head, *tail;

void PrintList()
  {
     nod *aux=head;
     while(aux!=NULL)
     {
         printf("%d", aux->data);
         aux=aux->next;
     }
  }

void AddFirst(int data)
  {
    if (head==NULL)
         {
            head=(nod*)malloc(sizeof(nod));
            tail=head;
            head->data=data;
            head->next=NULL;
         }
     else
        {
          nod *newnode=(nod*)malloc(sizeof(nod));
          newnode->data=data;
          newnode->next=head;
          head=newnode;
        }
  }

void AddLast(int data)
   {
       if(tail==NULL)
           {
              tail=(nod*)malloc(sizeof(nod));
              head=tail;
              tail->data=data;
              tail->next=head;
           }
       else
          {
             nod *newnode=(nod*)malloc(sizeof(nod));
             newnode->data=data;
             newnode->next=NULL;
             tail->next=newnode;
             tail=newnode;
          }
   }

void DeleteFirst()
  {
     if (head!=NULL)
         {
            nod *aux=head;
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

void DoomList()
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
           if(head->data==elem)
              {
                 FirstAux=head;
                 head=head->next;
                 free(FirstAux);
              }
           /*the searched element is inside the list*/
           if(tail!=NULL)
              {
                 SecondAux=head;
                 FirstAux=head->next;
                 while((FirstAux->data!=elem)&&(FirstAux!=tail))
                    {
                       FirstAux=FirstAux->next;
                       SecondAux=SecondAux->next;
                    }
                 /*the searched element is the last one, the tail*/
                 if((FirstAux==tail)&&(tail->data==elem))
                    {
                       SecondAux->next=NULL;
                       tail=SecondAux;
                       free(FirstAux);
                    }
                  /*the searched element is somewhere between the head and the tail*/
                 if((FirstAux!=tail)&&(FirstAux->data=elem))
                    {
                        SecondAux->next=FirstAux->next;
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
            fprintf(pfo,"%d",aux->data);
            aux=aux->next;
         }
      fprintf(pfo,"\n");
      fclose(pfo);
   }

void PrintFirstxInFisier(int nr)
   {
     FILE *pfo;
     pfo=fopen("output.dat","w");
     nod *aux=head;
     int i=1;
     while((aux!=NULL)&&(i<=nr))
        {
           fprintf(pfo,"%d",aux->data);
           aux=aux->next;
           i++;
        }
   }

void PrintLastxInFisier(int nr)
   {
      FILE *pfo;
      pfo=fopen("output.dat","w");
      nod *aux=head;
      int i=1;
      /*i counts the elements*/
      while(aux!=NULL)
         {
            if(aux->next!=NULL)
            {
               aux=aux->next;
               i++;
            }
         }
      if(i>=nr)
            PrintAllInFisier();
      while(aux!=NULL)
         {
      /*I kept on getting error messages so I stopped here*/
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
            DoomList();
         if(strcmp(Comanda,"DE")==0)
            DeleteElement(Element);
         if(strcmp(Comanda,"PRINT_ALL")==0)
            PrintAllInFisier();
         if(strcmp(Comanda,"PRINT_F")==0)
            PrintFirstxInFisier(Element); /*in this case Element represents the number of elements to be printed, NOT a value*/
                                          /*in the list*/
         if(strcmp(Comanda,"PRINT_L")==0)
            PrintLastxInFisier(Element);  /*Element is also the nr of elements*/
      }
   fclose(pfi);
   fclose(pfo);
   return 0;
}
