#include <stdio.h>

#include "vstup_vystup.h"
#include "kniha.h"

int main(void) {
    Knihovna knihovna;

    // Inicializuj knihovnu
    inicializuj_knihovnu(&knihovna);
    nacti_knihy(&knihovna);

    while (1) {
        zobraz_udaje_o_knihovne(&knihovna);
        char volba = menu();

        switch (volba) {
            case 'w':
                vypis_knihovnu(&knihovna);
                break;

            case 'e':
                pridat_knihu(&knihovna);
                break;

            case 'r':
                // Uvolni pamet
                uvolni_pamet_knihovny(&knihovna);
                printf ("KONEC...");
                return 0;

            default:
                printf("Neplatná volba.\n");
        }
    }

    return 0;
}
