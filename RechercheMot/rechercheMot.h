#ifndef RECHERCHEMOT_H
#define RECHERCHEMOT_H
#include "../Gestion-Config/Global.h"
#include "../comparaison/comparaison.h"

/**
 * @brief
 *La fonction "rechercheMot" permet de rechercher un mot spécifique dans une base de données de descripteurs de fichiers et de trier les résultats en fonction du nombre d'occurrences du mot.
  Elle utilise les fonctions système "echo" et "sort" de Linux pour effectuer la recherche et le tri.
  Le résultat final est stocké dans un tableau de structure "tab_similaire" qui contient l'ID du fichier et le nombre d'occurrences du mot.
  La fonction prend en entrée un mot à rechercher, un chemin vers la base de données de descripteurs, un tableau de structure "tab_similaire" pour stocker les résultats, le nombre de mots dans la base de données, un pointeur vers un entier pour stocker le nombre d'éléments dans le tableau de résultats, et un pointeur vers un entier pour stocker les erreurs.
 * @param mot
 * @param chemin
 * @param tabResultat
 * @param nb_mot
 * @param nbElTab
 * @param erreur
 */
void rechercheMot(char *mot, char *chemin, tab_similaire *tabResultat, int nb_mot, int *nbElTab, int *erreur);
#endif