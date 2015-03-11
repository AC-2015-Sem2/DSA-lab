#ifndef BATTLEFUNCTIONS_H_INCLUDED
#define BATTLEFUNCTIONS_H_INCLUDED

#include "functions.h"

int calculateDefense(waveList *sentinels);
void computeBest(country** auxCountry, char** bestName, char** worstName, int *totalDamage, int *maxDamage);
void computeLast(int currentHealth, country** auxCountry, country* first, FILE* g);
void computeSingleCountry(country** auxCountry, waveList *sentinels, int totalDefense, int maxDamage, FILE* g);

#endif // BATTLEFUNCTIONS_H_INCLUDED
