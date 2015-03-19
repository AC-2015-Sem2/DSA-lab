#include <stdio.h>
#include <stdlib.h>

typedef struct Coada
   {
       char person[15];
       int money, time;
       struct Coada *next;
   }client;

client *head, *tail;
FILE *pfin, *pfout;

/* enqueue = add last */
void AddClient(char name[20],int cash,int seconds)
   {
       if(tail==NULL)
           {
              tail=(client*)malloc(sizeof(client));
              head=tail;
              strcpy(tail->person,name);
              tail->money=cash;
              tail->time=seconds;
              tail->next=head;
           }
       else
          {
             client *newclient=(client*)malloc(sizeof(client));
             strcpy(tail->person,name);
             newclient->money=cash;
             newclient->time=seconds;
             newclient->next=NULL;
             tail->next=newclient;
             tail=newclient;
          }

   }


void PrintAllInFisier()
   {
      client* aux=head;
      while(aux!=NULL)
         {
            fprintf(pfout,"%c %d %d\n",aux->person,aux->money,aux->time);
            aux=aux->next;
         }
      fprintf(pfout,"\n");
      fclose(pfout);
   }


int main()
{
  pfout=fopen("output.dat","w");
  pfin=fopen("input.txt","r"); /*i used the .txt extension for input file because it took some randim usless values if used .dat*/
  int T;                       /*i don't really know how to create a new .dat file*/
  int suma_timp=0;
  //fscanf(pfin,"%d",&T);
  //fprintf(pfout,"Numarul de secunde cerut este: %d\n",T);
  int timp_cerut[200];
  int i=1;
  int nr_de_timp_cerut;
  while (fscanf(pfin,"%d",&timp_cerut[i]))
    i++;
  nr_de_timp_cerut=i-1;
  int timp,bani;
  char nume[20];
  for(i=1;i<=nr_de_timp_cerut;i++)
  {
    while((fscanf(pfin,"%s %d %d",nume,&bani,&timp)!=EOF)&&(suma_timp<=timp_cerut[i]))
      {
          AddClient(nume,timp,bani);
          suma_timp+=timp;
      }
    PrintAllInFisier();
  }
  fclose(pfout);

    return 0;
}
