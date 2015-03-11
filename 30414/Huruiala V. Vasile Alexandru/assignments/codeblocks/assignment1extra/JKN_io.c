#include<stdio.h>
#include<string.h>
#include "SLL_definition.h"
#include "SLL_functions.h"

//constraints
#define MAX_LN_LENGTH 255
#define SENTINEL_NAME "Sentinels"

/*DEBUG FUNCTION*/
void listList(Country* Sent, Country* hS, Country* tS)
{
    int i = 0;//DEBUG
    fprintf(stderr, "DEBUG: THIS IS THE CONTENT READ FROM THE FILE\n");
    //The Sentinel
    Army* aS = Sent->headArmy;
    fprintf(stderr, "Sentinel name: %s\n", Sent->cname);
    while(aS != NULL)
    {
        fprintf(stderr, "%d ", aS->hitpoints);
        aS = aS->next;
    }
    fprintf(stderr, "\n");
    //The Scourge
    Country* cS = hS;
    while(cS->nextCountry != hS)//remember it is circular for the wave mechanics
    {
        i++;
        fprintf(stderr, "%d:cname: %s, having the armies: ", i, cS->cname);
        Army* aSc = cS->headArmy;
        while(aSc != NULL)
        {
            fprintf(stderr, "%d ", aSc->hitpoints);
            aSc = aSc->next;
        }
        fprintf(stderr, "\n");
        cS = cS->nextCountry;
    }
}
/**/

//this gives the number of digits of a number
int noOfDigits(int n)
{
    int x = n;
    int count = 0;
    while(x > 0)
    {
        count++;
        x /= 10;
    }
    return count;
}

//this is a bit tricky because we don't know how many waved a country has
//so i read the entire line of the file, and then use an offset value of that line to sequentially extract the numbers
void readFile(FILE* In, int* nSentinels, Country** Sentinels, int* nCountries, Country** headScourge, Country** tailScourge)
{
    //The Sentinels
    fscanf(In, "%d", nSentinels);//no. of sentinels

    //the Sentinels will have a single node of country, which contains
    //the head and tail pointers to the list of armies
    *Sentinels = NULL;
    addLinkCountry(Sentinels, Sentinels, SENTINEL_NAME);//1 element so head == tail
    //temporary pointers they make things easier
    Army* headSent = NULL;
    Army* tailSent = NULL;

    //now to read the hp values of the sentinels
    for(int i = 0; i < *nSentinels; i++)
    {
        int hpSent;
        fscanf(In, "%d", &hpSent);

        addLinkArmy(&headSent, &tailSent, hpSent);
    }
    ///add JKN as a 1 hp sentinel
    addLinkArmy(&headSent, &tailSent, 1);
    //update the actual pointers
    (*Sentinels)->headArmy = headSent;
    (*Sentinels)->tailArmy = tailSent;

    //The Rebel Army
    fscanf(In, "%d", nCountries);//no. of countries

    fscanf(In, "\n");//this skips to the next line since we will be reading full lines now
    for(int i = 0; i < *nCountries+1; i++)
    {
        //reading an entire line
        char line[MAX_LN_LENGTH];
        fgets(line, MAX_LN_LENGTH, In);

        //extract country name
        char cname[MAX_LN_LENGTH];
        sscanf(line, "%s", cname);

        //Country list update
        if(i == 0)//if it is the first element
        {
            *headScourge = NULL;
            *tailScourge = NULL;
        }
        //add a country node
        addLinkCountry(headScourge, tailScourge, cname);
        //temporary pointers
        Army* headC = NULL;
        Army* tailC = NULL;

        int lnlen = strlen(line) - 1;//-1 for the '\n' character
        int lnPtr = strlen(cname);//the offset value
        while(lnPtr < lnlen)
        {
            //advance to a next digit(skipping all spaces and everything else)
            while(((*(line + lnPtr) < '0')||(*(line + lnPtr) > '9'))&&(lnPtr <= lnlen))
            {
                lnPtr++;
            }

            //this is necessary since a space can appear after the last number
            if(lnPtr < lnlen)
            {
                int hpC;
                sscanf(line + lnPtr, "%d", &hpC);

                lnPtr += noOfDigits(hpC);

                addLinkArmy(&headC, &tailC, hpC);
            }
        }
        //add the head and tail to the new element of the country list
        //that element is the tail
        (*tailScourge)->headArmy = headC;
        (*tailScourge)->tailArmy = tailC;
    }
}
