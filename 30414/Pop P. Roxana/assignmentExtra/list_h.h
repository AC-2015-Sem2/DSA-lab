#include <stdio.h>
#include <stdlib.h>
#include <string.h>

///DEFINING A LIST IN WHICH THE WAVES FOR EACH COUNTRY WILL BE STORED
typedef struct genericList{
    int force;//the force of a wave of attack of a specific country
    struct genericList * next;
} node;
///DEFINING A LIST WHICH CONTAINS INFORMATION ABOUT THE COUNTRIES. IT IS CALLED HEADER CELL AS EACH ELEMENT CONTAINS THE HEAD AND TAIL INDICATING ANOTHER LIST
typedef struct genericHeaderCell//a list of header cells+an extra field giving the country
{
    char *country;
    node * head;
    node *tail;
    int lifePoints;
    struct genericHeaderCell* nextHeader;
} headerCell;

///DEFINING A LIST IN WHICH THE AMOUNT OF DAMAGE EACH SENTINEL CAN TAKE IS STORED
typedef struct genericSentinels
{
    int damage;
    struct genericSentinels *nextSentinel;
} sentinels;

///HEADS AND TAILS
sentinels* sentinelHead;
sentinels* sentinelTail;
headerCell* headerHead;
headerCell* headerTail;
node* createNode(int data);
headerCell* createHeaderCellNode(char* s);
sentinels* createSentinel(int data);

///PROTOTYPES FOR THE HEADER CELLS LIST CORRESPONDING FUNCTIONS
void addLifePoints(headerCell* * p, int data);
void deleteCertainHeader(headerCell* *headerToDelete);
void addLastHeader(char* s);

///PROTOTYPES FOR THE LIST OF WAVES CORRESPONDING FUNCTIONS
void addLastNode (node* *head, node* *tail, int data);
void deleteFirstNode(node* *head, node* *tail);

///PROTOTYPES FOR THE LIST OF SENTINELS CORRESPONDING FUNCTIONS
void addLastSentinel(int data);
int totalSentinelForce();

///PROTOTYPES FOR THE FUNCTIONS COMPUTING THE OUTPUT
char* weakestCountry();
char* strongestCountry();
int mostSentinelsKilled(char*s,int *killedSentinels, int *pointsLeft);
int simulatingTheWar(char* *lastCountry);
