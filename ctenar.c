#include <stdlib.h>
#include "ctenar.h"
#include "io.h"

// VSE CO SOUVISI S CTENAREM
Ctenari ctenari;

//funkce - inicializace ctenaru
void init_ctenaru() {
    ctenari.pocet = 0;
    ctenari.kapacita = MIN_KAPACITA_CTENARU;

    ctenari.data = malloc(ctenari.kapacita * sizeof(Ctenar));

    nacti_ctenare();
}

//funkce - free ctenare
void uvolni_ctenare() {
    free(ctenari.data);

}

// funkce - realloc ctenaru pro pripad nedostatku pameti
int rozsir_ctenare() {
    if (ctenari.pocet == ctenari.kapacita) {
        int nova_kapacita = ctenari.kapacita * 2;

        Ctenar *nova_data = realloc(ctenari.data, nova_kapacita * sizeof(Ctenar)); // realloc nove pameti pro cenare
        if (nova_data == NULL) {
            printf("Chyba pri alokaci pameti");
            return 0;
        }

        ctenari.data = nova_data;
        ctenari.kapacita = nova_kapacita;
    }

    return 1;
}

// funkce - vypisat ctenare
void vypsat_ctenare() {
    printf("Ctenari:\n");
    vypsat_oddelovac(); //funkce vypis oddelovace
    for (int i = 0; i < ctenari.pocet; i++)
    {
        printf("%s %s; %i\n", ctenari.data[i].jmeno, ctenari.data[i].prijmeni, ctenari.data[i].ID_ctenare);
    }
    vypsat_oddelovac(); //funkce vypis oddelovace
}

//funkce - nacteni ctenare
void nacti_ctenare() {
    // otevri soubor
    FILE *soubor = otvreni_souboru(DB_CTENARU);

    // prochazej po radku a zapisuj do pameti a pro jistotu si zvetsuj pamet
    rozsir_ctenare();
    while (fscanf(soubor, "%51[^;];%51[^;];%i\n", ctenari.data[ctenari.pocet].jmeno, ctenari.data[ctenari.pocet].prijmeni, &ctenari.data[ctenari.pocet].ID_ctenare) == 3) {
        ctenari.pocet++;

        rozsir_ctenare(); //rozsir ctenare
    }

    fclose(soubor);
}

//funkce - pridat ctenare
void pridat_ctenare() {
    FILE *soubor = otvreni_souboru(DB_CTENARU);

    rozsir_ctenare(); //rozsir ctenare

    //nacitani jmena ctenare, prijmeni ctenare a ID ctenare
    printf ("Zadejte jmeno ctenare: ");
    fgets (ctenari.data[ctenari.pocet].jmeno, sizeof(ctenari.data[ctenari.pocet].jmeno), stdin);
    odstraneni_entru(ctenari.data[ctenari.pocet].jmeno);

    printf ("Zadejte prijmeni ctenare: ");
    fgets (ctenari.data[ctenari.pocet].prijmeni, sizeof(ctenari.data[ctenari.pocet].prijmeni), stdin);
    odstraneni_entru(ctenari.data[ctenari.pocet].prijmeni);

    printf ("Zadejte ID ctenare: ");
    scanf ("%i", &ctenari.data[ctenari.pocet].ID_ctenare);
    while(getchar() !='\n');

    //zapis ctenare do souboru
    fprintf (soubor,"%s; %s; %i \n", ctenari.data[ctenari.pocet].jmeno, ctenari.data[ctenari.pocet].prijmeni, ctenari.data[ctenari.pocet].ID_ctenare);
    ctenari.pocet++;

    fclose(soubor);
}

// vypis stavu ctenaru tj. kolik ctenaru je a jak velka je alokovana pamet
void vypis_stav_ctenaru() {
    printf("Ctenari: %d ctenaru, alokovana pamet: %d\n", ctenari.pocet, ctenari.kapacita);
}