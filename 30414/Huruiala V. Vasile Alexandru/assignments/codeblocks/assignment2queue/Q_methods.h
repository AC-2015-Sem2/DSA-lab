#include "Q_definition.h"
#include <stdio.h>

void ENQ(Sentinel* S, void* data1, void* data2, void* data3);
void DEQ(Sentinel* S);
void AddLastTime(Sentinel* S, void* data);
void RemoveFirstTime(Sentinel* S);
void readFile(Sentinel* S, FILE* I);
