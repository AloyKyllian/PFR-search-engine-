#ifndef LIRERESULTAT_H_INCLUS    
#define LIRERESULTAT_H_INCLUS   
#include "../Pile/Pile.h"

typedef struct {
    int id;
    int pourcentage;
}tabRes;

void LireResultat(tabRes*, int,char*, char*,char**);
void lire_chemin (PILE*,tabRes*,int,char*, int*);
void affichage(PILE*, tabRes*, char**);
#endif