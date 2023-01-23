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
 * La fonction "LireResultat" prend en entrée un tableau de résultats de recherche, le nombre d'éléments dans ce tableau, le type de recherche effectuée (par mot-clé ou par comparaison de fichiers),
 * ainsi que la requête effectuée, un tableau de noms de fichiers, le nombre de mots-clés utilisés dans la recherche et un seuil de similarité. 
 * Elle affiche les résultats de la recherche en fonction du type de recherche effectuée, et utilise une fonction "lire_chemin" pour remplir un tableau de noms de fichiers correspondant aux résultats de la recherche. 
 * Elle renvoie le nombre d'éléments dans le tableau de noms de fichiers rempli.
 * 
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
int LireResultat(tab_similaire *tabResultat, int nbElement, char *type, char *requete, char *tabFileName[], int nombre_mot_cle, int similarite);
/**
 * @brief 
 * La fonction "lire_chemin" prend en entrée le tableau de résultats de recherche, un tableau de noms de fichiers, le nombre d'éléments dans le tableau de résultats, le type de recherche effectuée,
 * ainsi que le nombre de mots-clés utilisés dans la recherche, un seuil de similarité et un pointeur d'erreur. 
 * Elle remplit le tableau de noms de fichiers en lisant les résultats de la recherche dans un fichier et renvoie le nombre d'éléments dans le tableau rempli.
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
 * La fonction visualiser_fichier prend en entrée un tableau de noms de fichiers, un entier correspondant au nombre d'éléments dans le tableau et un type de fichier (texte, image ou audio). 
 * Selon le type de fichier spécifié, la fonction utilise des commandes système pour afficher le premier élément du tableau à l'aide d'un éditeur de texte, d'un visualiseur d'image ou d'un lecteur audio. 
 * Ensuite, l'utilisateur est invité à choisir s'il souhaite visualiser un autre fichier du tableau, et si tel est le cas, il est invité à entrer un numéro de fichier pour le visualiser. 
 * Les permissions d'écriture sur le fichier sont également modifiées à différents moments pendant l'exécution de la fonction.
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