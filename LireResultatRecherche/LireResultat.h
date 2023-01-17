#ifndef LIRERESULTAT_H_INCLUS    
#define LIRERESULTAT_H_INCLUS   
#include "../Pile/Pile.h"

typedef struct {
    int id;
    int pourcentage;
}tabRes;

void LireResultat(tabRes*, int, String, String);
void lire_chemin (PILE*,tabRes*,int,String, int*);
#endif