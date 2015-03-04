# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct nod
{
    int data;
    struct nod *next;
}NODE;

typedef struct nod1
{
    char name[100];
    NODE *head;
    NODE *tail;
    struct nod1 *next;
}COUNTRY;

COUNTRY *first, *last;
NODE *sen_first, *sen_last;

void addCountry(char name[100])
{
    COUNTRY *newnode;
    newnode=(COUNTRY*) malloc(sizeof(COUNTRY));
    strcpy(newnode->name, name);

    if(first==NULL)
    {
        first=last=newnode;
        newnode->next=NULL;
        first->head=last->head=NULL;
    }
    else
    {
        newnode->next=NULL;
        last->next=newnode;
        last=newnode;
        last->head=NULL;
    }
}

void addWave(int data)
{
    NODE *newnode;
    newnode=(NODE*) malloc(sizeof(NODE));
    newnode->data=data;

    if(last->head==NULL)
    {
        last->head=newnode;
        last->tail=newnode;
        newnode->next=NULL;
    }
    else
    {
        last->tail->next=newnode;
        last->tail=newnode;
        newnode->next=NULL;
    }
}

void addSen(int  data)
{
    NODE *newnode;
    newnode=(NODE*) malloc(sizeof(NODE));
    newnode->data=data;

    if(sen_first==NULL)
    {
        sen_first=sen_last=newnode;
        newnode->next=NULL;
    }
    else
    {
        sen_last->next=newnode;
        newnode->next=NULL;
        sen_last=newnode;
    }
}

void remWave(COUNTRY* ctry)
{
    NODE *curent;
    curent=ctry->head;
    ctry->head=ctry->head->next;
    free(curent);
}

void last_hit(int life, FILE *out)
{
    last->next=first; //the list becomes circular

    COUNTRY *ctry=first;

    while(life>0)
    {
        if(ctry->head!=NULL)
        {
            life=life-(ctry->head->data);
            remWave(ctry);
        }
        if(life>0)
            ctry=ctry->next;
    }

    fprintf(out,"The last hit was done by: %s\n", ctry->name);
}

void decide(FILE *in, FILE *out)
{
    int nr_sen, i, data, nr_ctry;
    int sen_total_life=0, maxpower=0, minpower=9999999, temp_power, total_power=0;
    char which_max[100], which_min[100], which_def_all[100];
    bool def_all=0;
    char line[100], *p, sep[]=" \n";

    fscanf(in, "%d", &nr_sen);

    for(i=0; i<nr_sen; i++)
    {
        fscanf(in, "%d", &data);
        sen_total_life+=data;
        addSen(data);
    }

    sen_total_life+=1; //we add tyrant's life

    fscanf(in, "%d %*c", &nr_ctry);

    for(i=0; i<nr_ctry; i++)
    {
        fgets(line, sizeof(line), in);
        p=strtok(line, sep);
        addCountry(p);

        temp_power=0;

        while(p!=NULL)
        {
            p=strtok(NULL, sep);
            data=atoi(p);
            temp_power+=data;
            if(p)
                addWave(data);
        }

        if(temp_power>maxpower)
        {
            maxpower=temp_power;
            strcpy(which_max, last->name);
        }
        if(temp_power<minpower)
        {
            minpower=temp_power;
            strcpy(which_min, last->name);
        }

        if(temp_power>=sen_total_life)
        {
            def_all=1;
            strcpy(which_def_all, last->name);
        }

        total_power+=temp_power;

    }

    if(sen_total_life<=total_power)
    {
        fprintf(out, "The tyrant was killed\n");
        last_hit(sen_total_life, out);
    }
    else
        fprintf(out, "The tyrant wasn't killed!\n");

    fprintf(out, "The strongest country was: %s\n", which_max);
    fprintf(out, "The weakest country was: %s\n", which_min);

    if(def_all)
        fprintf(out, "%s could have defeated all the sentinels", which_def_all);
    else
    {
        fprintf(out, "No country could have defeated all the sentinels.\n");

        NODE *curent=sen_first;
        int nr=0;

        while(maxpower-(curent->data)>0)
        {
            nr+=1;
            maxpower=maxpower-(curent->data);
            curent=curent->next;
        }

        fprintf(out, "%s could have brought down the first %d sentinels and would have had chipped off %d life points from sentinel %d.\n", which_max, nr, maxpower, nr+1);
    }


}

int main()
{
    FILE *in, *out;
    in=fopen("input.dat", "r");

    if(in==NULL)
    {
        perror("Error opening file");
        exit(1);
    }

    out=fopen("output.dat", "w");

    decide(in, out);
    //print();
}

