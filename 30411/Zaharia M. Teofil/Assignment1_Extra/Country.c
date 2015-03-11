#include "Country.h"

void initCountry(Country* c, char* newName) {
    c->name = newName;

    c->army = (List*) malloc(sizeof(List));
    c->armySize = 0;

    initList(c->army);

    // if it would fight alone
    int lastDefeatedSent = 0;
    int lastDmg = 0;
}

void deleteCountry(Country *c) {
    c->name = NULL;

    deleteList(c->army);
    free(c->army);

    c->armySize = 0;
}

void addUnit(Country* c, int unitStrength) {
    addLast(c->army, (void*)unitStrength);

    // also counts total army size
    c->armySize += unitStrength;
}

void readdUnit(Country* c, int unitStrength) {
    addFirst(c->army, (void*)unitStrength);

    c->armySize += unitStrength;
}

void printUnits(Country* c) {
    printList(c->army);
}

int hasUnits(Country* c) {
    if (c->army->first != NULL) {
        return 1;
    }

    return 0;
}

// suppose ally and enemy still have units left
// check from main
char fightBattle(Country* ally, Country* enemy) {
// allied, enemy unit sizes
//
//    printUnits(enemy);
//    printf("%s:", ally->name);

    int auSize = getData(ally->army->first),
        euSize = 0;

    while (auSize > euSize && enemy->army->first != NULL) {
        euSize += getData(enemy->army->first);
        delFirst(enemy->army);
    }
    delFirst(ally->army);

    if (auSize > euSize) {
        // won
        // also takes Kim's 1 HP
        return 'w';
    } else if (auSize == euSize) {
        // 1 HP remaining

        return 'K';
    } else {
        // lost, euSize > auSize
        readdUnit(enemy, euSize-auSize);
        // last remaining unit

        return 'l';
    }
}

void oneOnOne(Country* ally, Country* enemy) {

    Node *allyUnit, *enemyUnit;

    allyUnit = ally->army->first;
    enemyUnit = enemy->army->first;

    int auSize = getData(allyUnit),
        euSize = getData(enemyUnit);

    int lastEnemy = 0;

    while (allyUnit != NULL && enemyUnit != NULL) {
        if (auSize > euSize) {
            auSize -= euSize;
            euSize = 0;
        } else if (auSize < euSize) {
            euSize -= auSize;
            auSize = 0;
        } else {
            euSize = auSize = 0;
        }

        if (!euSize) {
            enemyUnit = enemyUnit->next;
            if (enemyUnit != NULL) {
                lastEnemy++;
                euSize = getData(enemyUnit);
            }
        }

        if (!auSize) {
            allyUnit = allyUnit->next;
            if (allyUnit != NULL) {
                auSize = getData(allyUnit);
            } else {
                // defeated by the enemy
                ally->lastDefeatedSentinel = lastEnemy;
                ally->lastDmg = getData(enemyUnit) - euSize;
            }
        }
    }
}
