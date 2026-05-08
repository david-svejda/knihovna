#ifndef CTENAR_H
#define CTENAR_H

#define MIN_KAPACITA_CTENARU    4
#define DB_CTENARU              "ctenari.txt"

// struktura Ctenar
typedef struct
{
    char jmeno[50];
    char prijmeni[50];
    int ID_ctenare;
} Ctenar;

// struktura Ctenari
typedef struct
{
    Ctenar *data;
    int pocet;
    int kapacita;
} Ctenari;

Ctenari ctenari;

// funkce souvisejici se ctenari
void init_ctenaru();
void uvolni_ctenare();
void vypis_stav_ctenaru();
int rozsir_ctenare();
void pridat_ctenare();

void nacti_ctenare();
void vypsat_ctenare();

#endif