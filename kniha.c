#include "kniha.h"

#include "vstup_vystup.h"

void pridat_knihu(Knihovna *knihovna) {
    FILE *soubor = otvreni_souboru("knihy.txt");
    Kniha kniha;

    printf ("Zadejte jmeno knihy: ");
    fgets(kniha.jmeno_knihy, sizeof(kniha.jmeno_knihy), stdin);
    odstraneni_entru(kniha.jmeno_knihy);

    printf ("Zadejte jmeno autora: ");
    fgets (kniha.jmeno_autora, sizeof(kniha.jmeno_autora), stdin);
    odstraneni_entru(kniha.jmeno_autora);

    printf ("Zadejte prijmeni autora: ");
    fgets (kniha.prijmeni_autora, sizeof(kniha.prijmeni_autora), stdin);
    odstraneni_entru(kniha.prijmeni_autora);

    printf ("Zadejte rok vydani knihy: ");
    scanf ("%i", &kniha.rok_vydani);

    fprintf (soubor, "%s, %s, %s, %i", kniha.jmeno_knihy, kniha.jmeno_autora, kniha.prijmeni_autora, kniha.rok_vydani);

    fclose(soubor);
}
