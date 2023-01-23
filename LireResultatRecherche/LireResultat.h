#ifndef LIRERESULTAT_H_INCLUS    
#define LIRERESULTAT_H_INCLUS   
#include "../Pile/Pile.h"
#include "../comparaison/comparaison.h"

typedef struct {
    int id;
    int pourcentage;
}tabRes;


/**
 * @brief 
 * 
 * @param tabResultat 
 * @param nbElement 
 * @param type 
 * @param requete 
 * @param tabFileName 
 * @param nombre_mot_cle 
 * @param similarite 
 * @return int 
 */
int LireResultat(tab_similaire *tabResultat, int nbElement, char *type, char *requete, char *tabFileName[], int nombre_mot_cle, int similarite)
/**
 * @brief 
 * 
 * @param tabResultat 
 * @param tabFileName 
 * @param nbElement 
 * @param type 
 * @param nombre_mot_cle 
 * @param similarite 
 * @param erreur 
 * @return int 
 */
int lire_chemin(tab_similaire *tabResultat, char *tabFileName[], int nbElement, char *type, int nombre_mot_cle, int similarite, int *erreur);
/**
 * @brief 
 * 
 * @param tabFileName 
 * @param nbElement 
 * @param type 
 * @return char 
 */
char visualiser_fichier(char *tabFileName[], int nbElement, char *type);
/**
 * @brief 
 * 
 * @param type 
 * @param chemin 
 */
void recup_CheminPour_Affichage(char *type, char *chemin);

#endif