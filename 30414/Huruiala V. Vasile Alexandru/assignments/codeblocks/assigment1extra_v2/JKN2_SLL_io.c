#include "JKN2_SLL_definition.h"
#include <stdio.h>
#include <string.h>

#define SENT_NAME "Sentinel"
#define LINE_LN 256
#define FILE_IN "input.dat"
#define FILE_OUT "output.dat"

void openFiles(FILE** I, FILE** O)
{
    *I = fopen(FILE_IN, "r");
    *O = fopen(FILE_OUT, "w");
}

void closeFiles(FILE** I, FILE** O)
{
    fclose(*I);
    *I = NULL;
    fclose(*O);
    *O = NULL;
}

void readFile(JKN* J, FILE* I)
{
    //Reading Sentinel data
    (*J->AddLastCountryS)(J, (void*)SENT_NAME);
    int nSent = 0;
    fscanf(I, "%d", &nSent);

    for(int i = 0; i < nSent; i++)
    {
        int hp;
        fscanf(I, "%d", &hp);

        (*J->AddLastArmyS)(J, (void*)hp);
    }
    //Add JKN as an 1 hp army
    (*J->AddLastArmyS)(J, (void*)1);

    //Reading Countries data
    int nCou = 0;
    fscanf(I, "%d", &nCou);

    fscanf(I, "\n");
    for(int i = 0; i < nCou; i++)
    {
        char line[LINE_LN];
        fgets(line, LINE_LN, I);

        char* tok = strtok(line, " ");

        char cname[LINE_LN];
        sscanf(tok, "%s", cname);

        (*J->AddLastCountryC)(J, (void*)cname);
        tok = strtok(NULL, " ");
        while(tok != NULL)
        {
            int hp = 0;
            sscanf(tok, "%d", &hp);

            (*J->AddLastArmyC)(J, (void*)hp);

            tok = strtok(NULL, " ");
        }
    }
}

