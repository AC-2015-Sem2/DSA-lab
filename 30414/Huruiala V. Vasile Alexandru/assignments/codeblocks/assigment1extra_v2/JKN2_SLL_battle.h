Country* StrongestCountry(JKN* J);
Country* WeakestCountry(JKN* J);
int SoloWin(JKN* J, int* SentinelsDown, int* SentinelDamage);
int Battle(JKN* J, char** LastHitter);
void PrintResults(FILE* O, int victory, char* lasthit, char* strong, char* weak, int solopos, int sentsdown, int sentdamage);
void Solve(JKN* J, FILE* O);
