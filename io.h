#include <stdio.h>
#ifndef IO_H
#define IO_H

//funkce souvisejici se vstupem a vystupem
void menu();
void vypsat_oddelovac();
int cteni_z_klavesnice( char *znak);
FILE* otvreni_souboru (char *jmeno_souboru);
void odstraneni_entru(char *pole);

#endif