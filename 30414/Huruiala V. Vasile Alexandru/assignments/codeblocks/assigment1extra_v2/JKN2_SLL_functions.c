#include "JKN2_SLL_definition.h"
#include "JKN2_SLL_functions.h"
#include "JKN2_SLL_io.h"
#include "JKN2_SLL_battle.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void InitJKN(JKN** J)
{
    *J = (JKN*)malloc(sizeof(JKN));

    (*J)->sentinel = NULL;
    (*J)->headCou = NULL;
    (*J)->tailCou = NULL;
    (*J)->selCou = NULL;

    //(*J)->AddLastCountry = &AddFirstCountry;
    (*J)->AddLastCountryS = &AddLastCountryS;
    (*J)->AddLastCountryC = &AddLastCountryC;
    //(*J)->AddLastArmy = &AddFirstArmy;
    (*J)->AddLastArmyS = &AddLastArmyS;
    (*J)->AddLastArmyC = &AddLastArmyC;
    //(*J)->RemoveFirstArmy = RemoveFirstArmy;
    (*J)->SelectCountry = &SelectCountry;
    (*J)->RemoveFirstArmyS = &RemoveFirstArmyS;
    (*J)->RemoveFirstArmyC = &RemoveFirstArmyC;
    //(*J)->SetArmyData = &SetArmyData;
    (*J)->SetArmyDataS = &SetArmyDataS;
    (*J)->SetArmyDataC = &SetArmyDataC;

    (*J)->readFile = &readFile;

    (*J)->StrongestCountry = &StrongestCountry;
    (*J)->WeakestCountry = &WeakestCountry;
    (*J)->SoloWin = &SoloWin;
    (*J)->Battle = &Battle;
    (*J)->PrintResults = &PrintResults;
    (*J)->Solve = &Solve;

    (*J)->DebugPrint = &DebugPrint;
}

void AddLastCountry(Country** hC, Country** tC, void* data)
{
    Country* NewCountry = (Country*)malloc(sizeof(Country));
    char* cname = (char*)malloc(strlen((char*)data));
    strcpy(cname, (char*)data);
    NewCountry->data = (void*)cname;
    NewCountry->headArmy = NULL;
    NewCountry->tailArmy = NULL;
    NewCountry->next = NULL;
    if(*tC == NULL)
    {
        *hC = NewCountry;
        *tC = NewCountry;
    }
    else
    {
        (*tC)->next = NewCountry;
        *tC = NewCountry;
    }
}

void AddLastCountryS(JKN* J, void* data)
{
    AddLastCountry(&(J->sentinel), &(J->sentinel), data);
}

void AddLastCountryC(JKN* J, void* data)
{
    AddLastCountry(&(J->headCou), &(J->tailCou), data);
}

void AddLastArmy(Country* C, void* data)
{
    Army* NewArmy = (Army*)malloc(sizeof(Army));
    NewArmy->data = data;
    NewArmy->next = NULL;
    if(C->tailArmy == NULL)
    {
        C->headArmy = NewArmy;
        C->tailArmy = NewArmy;
    }
    else
    {
        C->tailArmy->next = NewArmy;
        C->tailArmy = NewArmy;
    }
}

void AddLastArmyS(JKN* J, void* data)
{
    AddLastArmy(J->sentinel, data);
}

void AddLastArmyC(JKN* J, void* data)
{
    AddLastArmy(J->tailCou, data);
}

void SelectCountry(JKN* J, Country* C)
{
    J->selCou = C;
}

void RemoveFirstArmy(Country* C)
{
if(C->headArmy != NULL)
    {
        if(C->headArmy == C->tailArmy)
        {
            free(C->headArmy);
            C->headArmy = NULL;
            C->tailArmy = NULL;
        }
        else
        {
            Army* Del = C->headArmy;
            C->headArmy = C->headArmy->next;
            free(Del);
        }
    }
}

void RemoveFirstArmyS(JKN* J)
{
    RemoveFirstArmy(J->sentinel);
}

void RemoveFirstArmyC(JKN* J)
{
    RemoveFirstArmy(J->selCou);
}

void SetArmyData(Country* C, void* data)
{
    C->headArmy->data = data;
}

void SetArmyDataS(JKN* J, void* data)
{
    SetArmyData(J->sentinel, data);
}


void SetArmyDataC(JKN* J, void* data)
{
    SetArmyData(J->selCou, data);
}

void DestroyCountry(Country** C)
{
    free((char*)(*C)->data);
    (*C)->data = NULL;
    while((*C)->headArmy != NULL)
    {
        Army* del = (*C)->headArmy;
        (*C)->headArmy = (*C)->headArmy->next;
        free(del);
    }
    free(*C);
    *C = NULL;
}

void Destroy(JKN** J)
{
    DestroyCountry(&((*J)->sentinel));
    while((*J)->headCou)
    {
        Country* del = (*J)->headCou;
        (*J)->headCou = (*J)->headCou->next;
        DestroyCountry(&del);
    }
    (*J)->tailCou = NULL;
    (*J)->selCou = NULL;

    //(*J)->AddLastCountry = NULL;
    (*J)->AddLastCountryS = NULL;
    (*J)->AddLastCountryC = NULL;
    //(*J)->AddLastArmy = NULL;
    (*J)->AddLastArmyS = NULL;
    (*J)->AddLastArmyC = NULL;
    //(*J)->RemoveFirstArmy = NULL;
    (*J)->SelectCountry = NULL;
    (*J)->RemoveFirstArmyS = NULL;
    (*J)->RemoveFirstArmyC = NULL;
    //(*J)->SetArmyData = NULL;
    (*J)->SetArmyDataS = NULL;
    (*J)->SetArmyDataC = NULL;

    (*J)->DebugPrint = NULL;
}

void DebugPrint(JKN* J)
{
    printf("DEBUG PRINT\n");
    printf("%s\n", (char*)J->sentinel->data);
    Army* tA = J->sentinel->headArmy;
    while(tA != NULL)
    {
        printf("%d ", (int)tA->data);
        tA = tA->next;
    }
    printf("\n");
    Country* tC = J->headCou;
    while(tC != NULL)
    {
        printf("%s: ", (char*)tC->data);
        tA = tC->headArmy;
        while(tA != NULL)
        {
            printf("%d ", (int)tA->data);
            tA = tA->next;
        }
        tC = tC->next;
        printf("\n");
    }
}
