#include "vstup_vystup.h"

#include <string.h>

#ifdef _WIN32
    /* Windows hlavickove soubory */
    #include <windows.h>
    #include <conio.h>
#else
    /* Linux / macOS hlavickove soubory */
    #include <termios.h>
    #include <unistd.h>
    #include <sys/select.h>
    #include <sys/ioctl.h>

    char _getch() {
        struct termios oldt, newt;
        int ch;

        tcgetattr(STDIN_FILENO, &oldt);     // save current terminal settings
        newt = oldt;
        newt.c_lflag &= ~(ICANON | ECHO);  // disable buffering and echo
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);

        ch = getchar();

        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);  // restore settings
        return ch;
    }
#endif

//funkce - cteni z klavesnice
int cteni_z_klavesnice(char *znak) {
    printf ("Vyberte klavesu: ");
    *znak = _getch();

    /*
        if ((*znak != 'w') && (*znak != 's') && (*znak != 'a') && (*znak =!'d') && (*znak =!'e') && (*znak != 'r')){
            printf ("Zadeli jste neplatnou klavesu");
            return 0;
        }
    */
    printf ("\n");
}

//funkce odstraneni enteru
void odstraneni_entru(char *pole) {
    int pozice = strcspn (pole, "\n");
    pole[pozice] = '\0';
}

//funkce otevreni souboru
FILE* otvreni_souboru(char *jmeno_souboru, char *mode) {
    FILE *soubor;

    soubor = fopen (jmeno_souboru, mode);
    if(soubor == NULL){
        printf ("Chyba pri otevirani souboru");
    }
    return soubor;
}

//funkce menu
char menu() {
    char znak;

    printf("MENU: \n");
    printf("w - Vypsat knihy \n");
    printf("s - Pridat ctenare \n");
    printf("a - Vypujcit knihu \n");
    printf("d - Vratit knihu \n");
    printf("e - Pridat knihu \n");
    printf("r - Konec \n");

    cteni_z_klavesnice(&znak);

    return znak;
}
