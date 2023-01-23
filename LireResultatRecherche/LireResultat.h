#ifndef LIRERESULTAT_H_INCLUS    
#define LIRERESULTAT_H_INCLUS   
#include "../Pile/Pile.h"
#include "../comparaison/comparaison.h"

typedef struct {
    int id;
    int pourcentage;
}tabRes;

int LireResultat(tab_similaire *tabResultat, int nbElement, char *type, char *requete, char *tabFileName[], int nombre_mot_cle, int similarite)
int lire_chemin(tab_similaire *tabResultat, char *tabFileName[], int nbElement, char *type, int nombre_mot_cle, int similarite, int *erreur);
char visualiser_fichier(char *tabFileName[], int nbElement, char *type);
void recup_CheminPour_Affichage(char *type, char *chemin);

#endif