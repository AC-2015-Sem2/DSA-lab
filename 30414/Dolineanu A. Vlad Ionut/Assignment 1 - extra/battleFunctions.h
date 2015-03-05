#ifndef BATTLEFUNCTIONS_H_INCLUDED
#define BATTLEFUNCTIONS_H_INCLUDED

#include "functions.h"

int calculateDefense(waveList *sentinels);
void computeBest(country** newCountry, char** bestName, char** worstName, int *totalDamage, int *maxDamage);
void computeLast(int currentHealth, country** newCountry, country* first, FILE* g);
void computeSingleCountry(country** newCountry, waveList *sentinels, int totalDefense, int maxDamage, int *turrets, int *chipped, int *nr, FILE* g);

#endif // BATTLEFUNCTIONS_H_INCLUDED
