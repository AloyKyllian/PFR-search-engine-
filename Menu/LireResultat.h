#ifndef LIRERESULTAT_H_INCLUS    
#define LIRERESULTAT_H_INCLUS   

typedef struct {
    int id;
    int pourcentage;
}tabRes;

void LireResultat(tabRes *tabResultat, int nbElement);
void lire_chemin (PILE *pourchemin, String type, int * erreur);

#endif