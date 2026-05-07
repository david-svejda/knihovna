#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#include "io.h"
#include "kniha.h"
#include "ctenar.h"

//funkce - vraceni knihy
void vratit_knihu(){

}

//MAIN
int main()
{
    //funkce na inicializaci knihovny
    init_knihovny();

    //funkce na inicializaci ctenaru
    init_ctenaru();

    //funkce vypsat stav knihovny, vypsat stav ctenaru, vypsat oddelovac (-------)
    vypis_stav_knihovny();
    vypis_stav_ctenaru();
    vypsat_oddelovac();

    //hlavni while cyklus
    while(1){

    char znak;

    //funkce na vypis menu a na nacteni znaku z klavesnice
    menu();
    cteni_z_klavesnice(&znak);

    //switch podle toho, jakou klavesu uzivatel zada
    switch(znak){

    //vypis knih
    case 'w':
        vypsat_knihy();
    break;

    //vypsat ctenare
    case 's':
        vypsat_ctenare();
    break;

    //pridat knihu
    case 'a':
        pridat_knihu();
    break;

    // pridat ctenare
    case 'd' :
       pridat_ctenare();
    break;

    // vvypujcit knihu
    case 'e' :
        vypujcit_knihu();
    break;

    //vratit knihu
    case 'q' :

    break;

    //konec programu + free knihovny a ctenaru
    case 'r' :
        printf ("KONEC...");
        uvolni_knihovnu();
        uvolni_ctenare();
        return 0;
    }

    }

    //free knihovny a ctenaru v pripade ze by program spadl a neukoncil se pres moznost konce
    uvolni_knihovnu();
    uvolni_ctenare();
    return 0;
}