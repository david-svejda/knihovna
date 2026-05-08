#ifndef KNIHA_H
#define KNIHA_H

// makra min. kapacitu knih a jmeno oteviraneho souboru
#define MIN_KAPACITA_KNIH       5
#define DB_KNIHY                "knihy.txt"
#define DB_VYPUJCENEKNIHY       "vypujcky.txt"

// struktura Kniha
typedef struct
{
    char jmeno_autora[50];
    char prijmeni_autora[50];
    char jmeno_knihy[70];
    int rok_vydani;
    int ID_knihy;
} Kniha;

// struktura Knihovna
typedef struct
{
    Kniha *data;
    int pocet;
    int kapacita;
} Knihovna;

Knihovna knihovna;

// funkce souvisejici s knihami
void init_knihovny();
void uvolni_knihovnu();
void vypis_stav_knihovny();
int rozsir_knihovnu();
void pridat_knihu();

void nacti_knihy();
void vypsat_knihy();

int vypujcit_knihu();

#endif