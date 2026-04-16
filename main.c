#include "vstup_vystup.h"
#include "kniha.h"
#include "ctenar.h"

int main(void) {
    Knihovna knihovna;
    Ctenari ctenari;

    // Inicializuj knihovnu
    inicializuj_knihovnu(&knihovna);
    nacti_knihy(&knihovna);

    // Inicializuj ctenare
    inicializuj_ctenare(&ctenari);
    nacti_ctenare(&ctenari);

    while (1) {
        zobraz_udaje_o_knihovne(&knihovna);
        zobraz_udaje_o_ctenarich(&ctenari);
        char volba = menu();

        switch (volba) {
            case 'w':
                vypis_knihovnu(&knihovna);
                break;

            case 'v':
                vypis_ctenare(&ctenari);
                break;

            case 's':
                pridat_ctenare(&ctenari);
                break;

            case 'e':
                pridat_knihu(&knihovna);
                break;

            case 'r':
                // Uvolni pamet
                uvolni_pamet_knihovny(&knihovna);
                uvolni_pamet_ctenaru(&ctenari);
                printf ("KONEC...\n");
                return 0;

            default:
                printf("Neplatná volba.\n");
        }
    }

    return 0;
}
