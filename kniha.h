#ifndef KNIHOVNA_KNIHA_H
#define KNIHOVNA_KNIHA_H

typedef struct {
    char jmeno_autora[20];
    char prijmeni_autora[20];
    char jmeno_knihy [30];
    int rok_vydani;
} Kniha;

typedef struct {
    Kniha *data;
    int pocet_knih;
    int alokovana_pamet;
} Knihovna;

void pridat_knihu(Knihovna *knihovna);

#endif //KNIHOVNA_KNIHA_H
