#ifndef LIRERESULTAT_H_INCLUS    
#define LIRERESULTAT_H_INCLUS   
#include "../Pile/Pile.h"
#include "../comparaison/comparaison.h"

typedef struct {
    int id;
    int pourcentage;
}tabRes;

void LireResultat(tab_similaire*, int, char*, char*, char**, int, int);
void lire_chemin (tab_similaire*,int,char*,int,int, int*);
void affichage(PILE*, tab_similaire*, char**);
#endif