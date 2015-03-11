#include<stdio.h>
#define MAX_LENGTH 14

int openFiles(FILE** I, FILE** O);
int closeFiles(FILE** I, FILE** O);
int readLine(FILE* In, char* command, int* param);
