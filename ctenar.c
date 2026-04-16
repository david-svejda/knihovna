#include "ctenar.h"

#include <stdlib.h>
#include "vstup_vystup.h"

#define INICIALNI_PAMET     4

// Zvětší paměť pro seznam čtenářů, když dochází = přidání dalšího čtenáře není možné
// Paměť se zvětší vždy jednou tolik, ať to není nutné dělat při každém přidaném čtenáři
int rozsir_pamet_ctenaru(Ctenari *ctenari) {
    // Když je dost paměti - tak nic nedělej
    if (ctenari->pocet_ctenaru < ctenari->alokovana_pamet)
        return 1;

    int nova_pamet = (ctenari->alokovana_pamet == 0)
        ? INICIALNI_PAMET
        : ctenari->alokovana_pamet * 2;

    Ctenar *nova_data = (Ctenar *)realloc(ctenari->data,nova_pamet * sizeof(Ctenar));
    if (!nova_data) {
        printf("  CHYBA: Nedostatek paměti pro rozšíření seznamu knih.\n");
        return 0;
    }

    ctenari->data = nova_data;
    ctenari->alokovana_pamet = nova_pamet;

    return 1;
}

// uvolnění paměti čtenářů
void uvolni_pamet_ctenaru(Ctenari *ctenari) {
    free(ctenari->data);

    ctenari->data = NULL;
    ctenari->pocet_ctenaru = 0;
    ctenari->alokovana_pamet = 0;
}

// inicializace prázdné knihovny
void inicializuj_ctenare(Ctenari *ctenari) {
    ctenari->data = NULL;
    ctenari->pocet_ctenaru = 0;
    ctenari->alokovana_pamet = 0;
    rozsir_pamet_ctenaru(ctenari);
}

// Zobraz informaci o počtu čtenářů a velikosti alokované paměti
void zobraz_udaje_o_ctenarich(Ctenari *ctenari) {
    printf("  Ctenari: %d celkem %d alokovaná paměť\n", ctenari->pocet_ctenaru, ctenari->alokovana_pamet);
}

// Přidej čtenáře jako vstup z klávesnice a přidej ho do souboru i do vnitřní paměti
void pridat_ctenare(Ctenari *ctenari) {
    rozsir_pamet_ctenaru(ctenari);

    FILE *soubor = otvreni_souboru("ctenari.txt", "a+");

    Ctenar *ctenar = &ctenari->data[ctenari->pocet_ctenaru];

    printf ("Zadejte jmeno ctenare: ");
    fgets(ctenar->jmeno, sizeof(ctenar->jmeno), stdin);
    odstraneni_entru(ctenar->jmeno);

    printf ("Zadejte prijmeni ctenare: ");
    fgets (ctenar->prijmeni, sizeof(ctenar->prijmeni), stdin);
    odstraneni_entru(ctenar->prijmeni);

    printf ("Zadejte ID ctenare: ");
    scanf ("%i", &ctenar->ID_ctenare);

    fprintf (soubor, "%s, %s, %i\n", ctenar->jmeno, ctenar->prijmeni, ctenar->ID_ctenare);

    fclose(soubor);

    // Pridej čtenáře oficiálně do paměti
    ctenari->pocet_ctenaru++;
}

// Načti jeden řádek s čtenářem ze souboru
int nacti_ctenare_ze_souboru(FILE *soubor, Ctenar *ctenar)
{
    if (soubor == NULL) return 0;

    // [^,] říká, že ten načítaný údaj je ukončený čárkou
    // číslo předtím počet znaků včetně té čárky - tedy o jedno větší než velikost řetězce
    return fscanf(soubor,
        " %21[^,], %21[^,], %i\n",
        ctenar->jmeno,
        ctenar->prijmeni,
        &ctenar->ID_ctenare);
}

// načti všechny čtenáře z souboru do paměti
void nacti_ctenare(Ctenari *ctenari) {
    FILE *soubor = otvreni_souboru("ctenari.txt", "r");

    while (nacti_ctenare_ze_souboru(soubor, &ctenari->data[ctenari->pocet_ctenaru]) == 3) {
        ctenari->pocet_ctenaru++;

        rozsir_pamet_ctenaru(ctenari);
    }

    fclose(soubor);
}

// vypiš čtenáře z paměti na obrazovku
void vypis_ctenare(Ctenari *ctenari) {
    for (int i = 0; i < ctenari->pocet_ctenaru; i++) {
        Ctenar ctenar = ctenari->data[i];
        printf("%s, %s, %i\n", ctenar.jmeno, ctenar.prijmeni, ctenar.ID_ctenare);
    }
}
