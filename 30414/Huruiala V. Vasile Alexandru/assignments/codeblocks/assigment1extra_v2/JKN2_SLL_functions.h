#include <stdio.h>

void AddLastCountry(Country** hC, Country** tC, void* data);
void AddLastCountryS(JKN* J, void* data);
void AddLastCountryC(JKN* J, void* data);
void AddLastArmy(Country* C, void* data);
void AddLastArmyS(JKN* J, void* data);
void AddLastArmyC(JKN* J, void* data);
void SelectCountry(JKN* J, Country* C);
void RemoveFirstArmy(Country* C);
void RemoveFirstArmyS(JKN* J);
void RemoveFirstArmyC(JKN* J);
void SetArmyData(Country* C, void* data);
void SetArmyDataS(JKN* J, void* data);
void SetArmyDataC(JKN* J, void* data);
void DebugPrint(JKN* J);
