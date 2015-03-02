typedef struct st_army
{
    int hitpoints;
    struct st_army* next;
} Army;

//each country has a pointer to the head and tail of the army list
typedef struct st_country
{
    char* cname;
    struct st_army* headArmy;
    struct st_army* tailArmy;
    struct st_country* nextCountry;
} Country;
