#include "kniha.h"

#include <stdlib.h>

#include "vstup_vystup.h"

#define INICIALNI_PAMET     4

// Zvětší paměť pro knihovnu, když dochází = přidání další knihy není možné
// Paměť se zvětší vždy jednou tolik, ať to není nutné dělat při každé knize
int rozsir_pamet_knihovny(Knihovna *knihovna) {
    // Když je dost paměti - tak nic nedělej
    if (knihovna->pocet_knih < knihovna->alokovana_pamet)
        return 1;

    int nova_pamet = (knihovna->alokovana_pamet == 0)
        ? INICIALNI_PAMET
        : knihovna->alokovana_pamet * 2;

    Kniha *nova_data = (Kniha *)realloc(knihovna->data,nova_pamet * sizeof(Kniha));
    if (!nova_data) {
        printf("  CHYBA: Nedostatek paměti pro rozšíření seznamu knih.\n");
        return 0;
    }

    knihovna->data = nova_data;
    knihovna->alokovana_pamet = nova_pamet;

    return 1;
}

// uvolnění paměti knihovny
void uvolni_pamet_knihovny(Knihovna *knihovna) {
    free(knihovna->data);

    knihovna->data = NULL;
    knihovna->pocet_knih = 0;
    knihovna->alokovana_pamet = 0;
}

// inicializace prázdné knihovny
void inicializuj_knihovnu(Knihovna *knihovna) {
    knihovna->data = NULL;
    knihovna->pocet_knih = 0;
    knihovna->alokovana_pamet = 0;
    rozsir_pamet_knihovny(knihovna);
}

// Zobraz informaci o počtu knih v knihovně a velikosti alokované paměti
void zobraz_udaje_o_knihovne(Knihovna *knihovna) {
    printf("  Knihy: %d celkem %d alokovaná paměť\n", knihovna->pocet_knih, knihovna->alokovana_pamet);
}

// Přidej knihu jako vstup z klávesnice a přidej ji do souboru i do vnitřní paměti
void pridat_knihu(Knihovna *knihovna) {
    rozsir_pamet_knihovny(knihovna);

    FILE *soubor = otvreni_souboru("knihy.txt", "a+");

    Kniha *kniha = &knihovna->data[knihovna->pocet_knih];

    printf ("Zadejte jmeno knihy: ");
    fgets(kniha->jmeno_knihy, sizeof(kniha->jmeno_knihy), stdin);
    odstraneni_entru(kniha->jmeno_knihy);

    printf ("Zadejte jmeno autora: ");
    fgets (kniha->jmeno_autora, sizeof(kniha->jmeno_autora), stdin);
    odstraneni_entru(kniha->jmeno_autora);

    printf ("Zadejte prijmeni autora: ");
    fgets (kniha->prijmeni_autora, sizeof(kniha->prijmeni_autora), stdin);
    odstraneni_entru(kniha->prijmeni_autora);

    printf ("Zadejte rok vydani knihy: ");
    scanf ("%i", &kniha->rok_vydani);

    fprintf (soubor, "%s, %s, %s, %i\n", kniha->jmeno_knihy, kniha->jmeno_autora, kniha->prijmeni_autora, kniha->rok_vydani);

    fclose(soubor);

    // Pridej knihu oficiálně do paměti
    knihovna->pocet_knih++;
}

// Načti jeden řádek s knihou ze souboru
int nacti_knihu_ze_souboru(FILE *soubor, Kniha *kniha)
{
    if (soubor == NULL) return 0;

    // [^,] říká, že ten načítaný údaj je ukončený čárkou
    // číslo předtím počet znaků včetně té čárky - tedy o jedno větší než velikost řetězce
    return fscanf(soubor,
        " %31[^,], %21[^,], %21[^,], %i\n",
        kniha->jmeno_knihy,
        kniha->jmeno_autora,
        kniha->prijmeni_autora,
        &kniha->rok_vydani);
}

// načti všechny knihy z souboru do paměti
void nacti_knihy(Knihovna *knihovna) {
    FILE *soubor = otvreni_souboru("knihy.txt", "r");

    while (nacti_knihu_ze_souboru(soubor, &knihovna->data[knihovna->pocet_knih]) == 4) {
        knihovna->pocet_knih++;

        rozsir_pamet_knihovny(knihovna);
    }

    fclose(soubor);
}

// vypiš knihy z paměti na obrazovku
void vypis_knihovnu(Knihovna *knihovna) {
    for (int i = 0; i < knihovna->pocet_knih; i++) {
        Kniha kniha = knihovna->data[i];
        printf("%s, %s, %s, %i\n", kniha.jmeno_knihy, kniha.jmeno_autora, kniha.prijmeni_autora, kniha.rok_vydani);
    }
}
