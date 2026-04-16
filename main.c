#include <stdio.h>

#include "vstup_vystup.h"
#include "kniha.h"

int main(void) {
    Knihovna knihovna;

    // TODO inicializuj knihovnu

    while (1) {
        char volba = menu();

        switch (volba) {
            case 'e':
                pridat_knihu(&knihovna);
                break;

            case 'r':
                // TODO uvolni pamet
                printf ("KONEC...");
                return 0;

            default:
                printf("Neplatná volba.\n");
        }
    }

    return 0;
}
