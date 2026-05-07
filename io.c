#include "io.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

//VSE CO SOUVISI SE VSTUPEM A VYSTUPEM

//funkce - vypis menu
void menu(){
    printf("MENU: \n");
    printf("w - Vypsat knihy \n");
    printf("s - Vypsat ctenare \n");
    printf("a - Pridat knihu \n");
    printf("d - Pridat ctenare \n");
    printf("e - Vypujcit knihu \n");
    printf("q - Vratit knihu \n");
    printf("r - Konec \n");
}

//funkce - cteni z klavesnice
int cteni_z_klavesnice( char *znak){
    printf ("Vyberte klavesu: ");
    *znak = _getch();

   printf ("\n");
}

//funkce - odstraneni enteru
void odstraneni_entru(char *pole){
    int pozice = strcspn (pole, "\n");
    pole[pozice] = '\0';

}

//funkce - otevreni souboru
FILE* otvreni_souboru (char *jmeno_souboru){
    FILE *soubor = fopen (jmeno_souboru, "a+");

    return soubor;
}

//funkce - vypsat oddelovac
void vypsat_oddelovac() {
    printf("------------------------------\n");
}