#ifndef COMPARAISON_H
#define COMPARAISON_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "../descripteur_audio/descripteur_audio.h"
#include "../descripteur_image/Descripteur_image.h"
#include "../descripteur_texte/descripteur_texte.h"

typedef struct
{
    int id;
    float pourcentage;
} tab_similaire;

tab_similaire *Comparaison_descripteur_image(int *Erreur, char PathRecueil[], char PathNvImg[], int Nb_Bits_Fort, int *Nb_des);

/**
 * @brief
 *
 */
float comparaison(int val_lu, descri_audio descripteur_comparé, int ligne, int intervalle, descri_audio descri, float fenetre);

/**
 * @brief
 *
 * Elle utilise la fonction "getligne" pour obtenir le nombre de lignes dans le fichier à comparer,
 * crée un descripteur audio pour ce fichier en utilisant la fonction "Descripteur_audio",
 * alloue de la mémoire pour une table de similarité,
 * ouvre le fichier de descripteur audio en mode lecture, lit les valeurs de ce fichier et les utilise pour créer un descripteur audio pour chaque fichier de comparaison,
 * utilise une fonction "comparaison" pour calculer le pourcentage de similarité entre les deux descripteurs audio,
 * stock ces pourcentages dans la table de similarité, trie les fichiers par ordre de similarité, et retourne la table de similarité.
 *
 * @param fenetre
 * @param intervalle
 * @param chemin_descripteur_compare
 * @param chemin_descripteur_audio
 * @param erreur
 * @param Nb_ligne
 * @return tab_similaire*
 */
tab_similaire *comparaison_audio(int fenetre, int intervalle, char *chemin_descripteur_compare, char *chemin_descripteur_audio, int *erreur, int *Nb_ligne);


/**
 * @brief
 *
 * Auteur : Hugo Lestrade
 * Cette fonction commence par créer un descripteur pour le nouveau fichier ajouté.
 * Elle fait une boucle qui balaye tous les descripteurs déjà créé et pour chacun :
 * Récupère l'id du descripteur déjà créé.
 * Puis vérifie si les mots du nouveau descripteur sont présents dans celui déjà présent
 * Si c'est le cas on regarde leur nombre d'apparition chacun, s'ils apparaissent à +/- 3 près alors on considère que ce mot est cité de manière similaire dans les deux textes.
 * Dans ce cas on augmente un compteur
 * Puis à la fin on fait le calcul du nombre de mot similaire divisé par le nombre de mot total multiplié par 100 pour avoir la similarité des deux textes en pourcentage.
 * Enfin on passe au descripteur suivant pour comparer.
 *
 * @param nbr_mot
 * @param chemin_fichier_a_compare
 * @param chemin_descripteur_compare
 * @param chemin_descripteur
 * @param Erreur
 * @param Nb_ligne
 * @return tab_similaire*
 */
tab_similaire *comparaison_texte(int nbr_mot, char *chemin_fichier_a_compare, char *chemin_descripteur, int *Erreur, int *Nb_ligne);

// typedef enum {texte,image,audio}type_compare;

#endif