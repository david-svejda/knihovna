#include "kniha.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "io.h"
#include "ctenar.h"

// VSE CO SOUVISI S KNIHAMI
Knihovna knihovna;

//funkce - inicializace knihovny
void init_knihovny() {
    knihovna.pocet = 0;
    knihovna.kapacita = MIN_KAPACITA_KNIH;

    //malloc knihovny
    knihovna.data = malloc(knihovna.kapacita * sizeof(Kniha));

    //nacteni knih do knihovny
    nacti_knihy();
}

//funkce - free knihovny
void uvolni_knihovnu() {
    free(knihovna.data);
}

//funkce - realloc knihovny v pripade nedostatku mista
int rozsir_knihovnu() {
    if (knihovna.pocet == knihovna.kapacita) {
        int nova_kapacita = knihovna.kapacita * 2;

        Kniha *nova_data = realloc(knihovna.data, nova_kapacita * sizeof(Kniha)); //realloc nove pameti pro knihovnu
        if (nova_data == NULL) {
            printf("Chyba pri alokaci pameti");
            return 0;
        }

        knihovna.data = nova_data;
        knihovna.kapacita = nova_kapacita;
    }

    return 1;
}

//funkce - nacitani knih
// otevri soubor
void nacti_knihy() {
    FILE *soubor = otvreni_souboru(DB_KNIHY);

    // prochazej po radku a zapisuj do pameti a pro jistotu si zvetsuj pamet -- potrebuju vysvetlit
    rozsir_knihovnu();
    while (fscanf(soubor, "%71[^;];%51[^;];%51[^;]; %i; %i\n", knihovna.data[knihovna.pocet].jmeno_knihy, knihovna.data[knihovna.pocet].jmeno_autora, knihovna.data[knihovna.pocet].prijmeni_autora, &knihovna.data[knihovna.pocet].rok_vydani, &knihovna.data[knihovna.pocet].ID_knihy) == 5) {
        knihovna.pocet++;

        rozsir_knihovnu(); //funkce rozsir knihovnu
    }

    fclose(soubor);
}

// funkce - vypis knih
void vypsat_knihy() {
    printf("Knihovna:\n");
    vypsat_oddelovac(); // funkce vypsat oddelovace
    for (int i = 0; i < knihovna.pocet; i++){
        printf("%s; %s %s; %i; %i\n", knihovna.data[i].jmeno_knihy, knihovna.data[i].jmeno_autora, knihovna.data[i].prijmeni_autora, knihovna.data[i].rok_vydani, knihovna.data[i].ID_knihy);
    }
    //funkce vypis oddelovace
    vypsat_oddelovac();
}

//funkce - pridat knihu
void pridat_knihu() {
    FILE *soubor = otvreni_souboru(DB_KNIHY);

    //rozsireni knihovny pro pripad ze bychom byli na hranici velikosti a nebylo by kam zapsat
    rozsir_knihovnu();

    //nacteni jmena knihy, jmena autora, prijmeni autora a rok vydani knihy
    printf ("Zadejte jmeno knihy: ");
    fgets (knihovna.data[knihovna.pocet].jmeno_knihy, sizeof(knihovna.data[knihovna.pocet].jmeno_knihy), stdin);
    odstraneni_entru(knihovna.data[knihovna.pocet].jmeno_knihy);

    printf ("Zadejte jmeno autora: ");
    fgets (knihovna.data[knihovna.pocet].jmeno_autora, sizeof(knihovna.data[knihovna.pocet].jmeno_autora), stdin);
    odstraneni_entru(knihovna.data[knihovna.pocet].jmeno_autora);

    printf ("Zadejte prijmeni autora: ");
    fgets (knihovna.data[knihovna.pocet].prijmeni_autora, sizeof(knihovna.data[knihovna.pocet].prijmeni_autora), stdin);
    odstraneni_entru(knihovna.data[knihovna.pocet].prijmeni_autora);

    printf ("Zadejte rok vydani knihy: ");
    scanf ("%i", &knihovna.data[knihovna.pocet].rok_vydani);
    while(getchar() !='\n');

    //zapis jmena knihy, jmena autora, prijmeni autora a rok vydani knihy do souboru
    fprintf (soubor,"%s; %s; %s; %i \n", knihovna.data[knihovna.pocet].jmeno_knihy, knihovna.data[knihovna.pocet].jmeno_autora, knihovna.data[knihovna.pocet].prijmeni_autora, knihovna.data[knihovna.pocet].rok_vydani);
    knihovna.pocet++;

    fclose(soubor);
}

//funkce - vypis stavu knihovny - tj. kolik knih knihovna obsahuje a jak velka je alokovana pamet
void vypis_stav_knihovny() {
    printf("Knihovna: %d knih, alokovana pamet: %d\n", knihovna.pocet, knihovna.kapacita);
}

/*
//funkce - vypujceni knihy
int vypujcit_knihu(){

    nacti_knihy(); //nacte knihy

    char vyhledani_knihy[70];
    int ID_vypujcky = 0;

    printf ("Zadeje jmeno knihy, kterou chcete vypujcit: ");
    fgets(vyhledani_knihy, sizeof(vyhledani_knihy), stdin);

    for (int i = 0; i < knihovna.pocet; i++){
        if (strcmp(vyhledani_knihy, knihovna.data[i].jmeno_knihy) != 0){
        printf ("Tuto knihu knihovna neobsahuje. \n");

        return 0;
        }

    }


    printf("zadejte ID ctenare, u ktereho chcete vypujcku provest: ");
    scanf("%i", &ID_vypujcky);

    for (int i = 0; i < ctenari.pocet; i++){
        if (ID_vypujcky != ctenari.data[i].ID_ctenare){
           printf ("Tento ctenar v knihovne neexistuje. \n");

           break;
        }

        else{
         FILE*soubor = otvreni_souboru(DB_VYPUJCENEKNIHY);
         fprintf(soubor, "%s - %s", &knihovna.data[knihovna.pocet].jmeno_knihy, &ctenari.data[ctenari.pocet].jmeno);
         printf("Kniha je uspesne zapsana do seznamu vypujcenych knih");
        }


    }



}
    */
