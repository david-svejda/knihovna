#ifndef KNIHOVNA_MENU_H
#define KNIHOVNA_MENU_H
#include <stdio.h>

char menu();

int cteni_z_klavesnice(char *znak);
void odstraneni_entru(char *pole);
FILE* otvreni_souboru(char *jmeno_souboru, char *mode);

#endif //KNIHOVNA_MENU_H
