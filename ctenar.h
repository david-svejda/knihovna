#ifndef KNIHOVNA_CTENAR_H
#define KNIHOVNA_CTENAR_H

typedef struct {
    char jmeno[20];
    char prijmeni[20];
    int ID_ctenare;
} Ctenar;

typedef struct {
    Ctenar *data;
    int pocet_ctenaru;
    int alokovana_pamet;
} Ctenari;

void pridat_ctenare(Ctenari *ctenari);
void inicializuj_ctenare(Ctenari *ctenari);
void uvolni_pamet_ctenaru(Ctenari *ctenari);
void nacti_ctenare(Ctenari *ctenari);
void zobraz_udaje_o_ctenarich(Ctenari *ctenari);

void vypis_ctenare(Ctenari *ctenari);

#endif //KNIHOVNA_CTENAR_H
