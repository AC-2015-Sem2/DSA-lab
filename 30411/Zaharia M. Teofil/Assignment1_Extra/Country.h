#ifndef COUNTRY_H
#define COUNTRY_H

#include "List.h"

typedef struct s_Country {
    char* name;
    List* army;
    int armySize;

    // if it would fight alone
    int lastDefeatedSentinel;
    int lastDmg;
} Country;

void initCountry(Country* c, char* newName);
void addUnit(Country* c, int unitStrength);
void readdUnit(Country* c, int unitStrength); // for fight sim
void printUnits(Country* c);
int hasUnits(Country* c);

// 1 round battle execution
// destructive function
// changes army unit sizes
char fightBattle(Country* ally, Country* enemy);


// 1 on 1 complete battle simulation
// non-destructive function
// just simulates, no soldier deaths
void oneOnOne(Country* ally, Country* enemy);


#endif // COUNTRY_H
