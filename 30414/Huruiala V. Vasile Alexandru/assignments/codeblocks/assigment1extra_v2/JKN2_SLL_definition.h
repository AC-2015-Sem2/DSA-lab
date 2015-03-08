#include <stdio.h>
/*
Generalized list node
*/
typedef struct struct_army Army;
typedef struct struct_army
{
    void* data;
    Army* next;
} Army;

/*
Generalized list node with additional fields to point to another list
*/
typedef struct struct_country Country;
typedef struct struct_country
{
    void* data;
    Army* headArmy;
    Army* tailArmy;
    Country* next;
} Country;

/*
Object like structure with pointers to functions that act like member methods
Contains(storage for) all data the problem needs
*/
typedef struct struct_JKN JKN;
typedef struct struct_JKN
{
    ///The Sentinel
    //this only needs resources to one list - an army list
    //contained with a country struct
    Country* sentinel;

    ///The Rebel army
    //now we need a list of lists
    Country* headCou;
    Country* tailCou;
    Country* selCou;

    ///SLL methods
    //void (*AddLastCountry)(Country** hC, Country** tC);
    void (*AddLastCountryS)(JKN* J, void* data);
    void (*AddLastCountryC)(JKN* J, void* data);
    //void (*AddLastArmy)(Country* C);
    void (*AddLastArmyS)(JKN* J, void* data);
    void (*AddLastArmyC)(JKN* J, void* data);
    //void (*RemoveFirstArmy)(Country* C);
    void (*SelectCountry)(JKN* J, Country* C);
    void (*RemoveFirstArmyS)(JKN* J);
    void (*RemoveFirstArmyC)(JKN* J);
    //void (*SetArmyData)(Country* C, void* data);
    void (*SetArmyDataS)(JKN* J, void* data);
    void (*SetArmyDataC)(JKN* J, void* data);
    ///IO method
    void (*readFile)(JKN* J, FILE* I);
    ///Battle methods
    Country* (*StrongestCountry)(JKN* J);
    Country* (*WeakestCountry)(JKN* J);
    int (*SoloWin)(JKN* J, int* SentinelsDown, int* SentinelDamage);
    int (*Battle)(JKN* J, char** LastHitter);
    void (*PrintResults)(FILE* O, int victory, char* lasthit, char* strong, char* weak, int solopos, int sentsdown, int sentdamage);
    void (*Solve)(JKN* J, FILE* O);
    ///Debug method
    void (*DebugPrint)(JKN* J);
} JKN;

void InitJKN(JKN** J);
void Destroy(JKN** J);
